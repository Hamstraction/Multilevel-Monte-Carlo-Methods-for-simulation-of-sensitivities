#include <cmath>
#include <iostream>

using namespace std;
#include "Atype.hpp"

static int Avac=0;
A_TapeEntry Atape[A_TAPE_SIZE];

Atype::Atype(const double& x) : v(x){
  Atape[Avac].oc= A_CONST;
  Atape[Avac].v= x;
  va= Avac++;
}

Atype& Atype::operator=(const Atype& x){
  if(this==&x) return *this;
  Atape[Avac].oc= A_ASG;
  Atape[Avac].v= v= x.v;
  va= Avac++;
  return *this;
}

Atype operator*(const Atype& x1, const Atype& x2){
  Atype temp;
  Atape[Avac].oc = A_MUL;
  Atape[Avac].arg1 = x1.va;
  Atape[Avac].arg2 = x2.va;
  Atape[Avac].v = temp.v = x1.v*x2.v;
  temp.va= Avac++; 
  return temp;
}

Atype operator+(const Atype& x1, const Atype& x2){
  Atype temp;
  Atape[Avac].oc = A_ADD;
  Atape[Avac].arg1 = x1.va;
  Atape[Avac].arg2 = x2.va;
  Atape[Avac].v = temp.v = x1.v+x2.v;
  temp.va= Avac++; 
  return temp;
}

Atype operator-(const Atype& x1, const Atype& x2){
  Atype temp;
  Atape[Avac].oc = A_SUB;
  Atape[Avac].arg1 = x1.va;
  Atape[Avac].arg2 = x2.va;
  Atape[Avac].v = temp.v = x1.v-x2.v;
  temp.va= Avac++; 
  return temp;
}

Atype sin(const Atype& x){
 Atype temp;
 Atape[Avac].oc = A_SIN;
 Atape[Avac].arg1 = x.va;
 Atape[Avac].v = temp.v = sin(x.v);
 temp.va = Avac++;
 return temp;
}

Atype cos(const Atype& x){
 Atype temp;
 Atape[Avac].oc = A_COS;
 Atape[Avac].arg1 = x.va;
 Atape[Avac].v = temp.v = cos(x.v);
 temp.va = Avac++;
 return temp;
}

Atype exp(const Atype& x){
 Atype temp;
 Atape[Avac].oc = A_EXP;
 Atape[Avac].arg1 = x.va;
 Atape[Avac].v = temp.v = exp(x.v);
 temp.va = Avac++;
 return temp;
}

void A_PrintTape(){
  cout << "tape:" << endl;
  for(int i=0;i<Avac;i++){
    cout << i << ": [ " << Atape[i].oc << ", " << Atape[i].arg1 << ", " << Atape[i].arg2 << ", " << Atape[i].v << ", " << Atape[i].a << " ]" << endl;
  }
}

void A_ResetTape(){
  for(int i=0;i<Avac;i++){
    Atape[i].a = 0;
  }
  Avac = 0;
}

void A_InterpretTape(){
  for(int i=Avac-1; i >= 0; i--){
    //cout << i << ") case " << Atape[i].oc << " value " << Atape[i].a  << endl;
    switch(Atape[i].oc){
      case A_ASG : {
        Atape[Atape[i].arg1].a += Atape[i].a;
        break;		   
      }
      case A_ADD : {
        Atape[Atape[i].arg1].a += Atape[i].a;
        Atape[Atape[i].arg2].a += Atape[i].a;
        cout << Atape[Atape[i].arg1].a << endl;	
        break;		   
      }
      case A_SUB : {
        Atape[Atape[i].arg1].a += Atape[i].a;
        Atape[Atape[i].arg2].a -= Atape[i].a;
        break;		   
      }
      case A_MUL : {
        Atape[Atape[i].arg1].a += Atape[Atape[i].arg2].v * Atape[i].a;
        Atape[Atape[i].arg2].a += Atape[Atape[i].arg1].v * Atape[i].a;
        break;		   
      }
      case A_SIN : {
	Atape[Atape[i].arg1].a += cos(Atape[Atape[i].arg1].v) * Atape[i].a;
        break;		   
      }
      case A_COS : {
 	Atape[Atape[i].arg1].a -= sin(Atape[Atape[i].arg1].v) * Atape[i].a; 
        break;		   
      }
      case A_EXP : {
  	Atape[Atape[i].arg1].a += Atape[i].v * Atape[i].a;     
        break;		   
      }
    }
  }
}






