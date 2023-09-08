

#include <iostream>
#include <stdio.h>

using namespace std;
#include "TLtype.cpp"

//Dimension of problem
const int n=100000;

//Prototype function
void f(TLtype*, TLtype&);

int main(){
  TLtype x[n]; 
  TLtype y;

  for(int i=0;i<n;i++){
    x[i]=1;
  }
  //Want to square each element of sum and then square sum
  for(int i=0;i<n;i++){
    x[i].t=1;
    f(x,y);
    x[i].t=0;
    cout << i << ") " <<  y.t <<endl;
  }

  return 0;
}

void f(TLtype *x, TLtype &y){
  y=0;
  for(int i=0;i<n;i++){
    y = y+ x[i]*x[i];
  }
  y = y*y;
}


