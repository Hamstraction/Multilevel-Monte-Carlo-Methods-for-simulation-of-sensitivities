#include <iostream>
#include "Atype.cpp"
using namespace std;

const int n=100000;
extern A_TapeEntry Atape[A_TAPE_SIZE];

void f(Atype *x, Atype &y){
  y=0;
  for(int i=0; i<n; i++){
    y = y + x[i]*x[i];
  }
  y=y*y;
}

int main(){
  
  Atype x[n], y;
  for(int j=0; j<n; j++){
    x[j] = 1;
  }
  f(x,y);
  //A_PrintTape();
  Atape[y.va].a = 1;
  A_InterpretTape();
  cout << "\n-------\n";
  //A_PrintTape();
  A_ResetTape();
  return 0;
}

