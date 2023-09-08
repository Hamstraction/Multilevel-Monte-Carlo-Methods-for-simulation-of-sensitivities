#include <iostream>
using namespace std;

const int n=50000;

void f(double *x, double &y){
  y=0;
  for(int i=0; i<n; i++){
    y = y + x[i]*x[i];
  }
  y=y*y;
}

int main(){
  
  double x[n], y;
  for(int j=0; j<n; j++){
    x[j] = 1;
  }
  f(x,y);
  return 0;
}

