
#include <cmath>

using namespace std;
#include "TLtype.hpp"

TLtype::TLtype(const double& x): v(x), t(0) { };
TLtype::TLtype(): v(0), t(0) { };

TLtype& TLtype::operator=(const TLtype& x){
  if(this==&x) return *this;
  v=x.v;
  t=x.t;
  
  return *this;
}


TLtype operator*(const TLtype& x1,const TLtype& x2){
  TLtype temp;
  temp.v=x1.v*x2.v;
  temp.t=x1.t*x2.v+x1.v*x2.t;
  
  return temp;
}

TLtype operator+(const TLtype& x1,const TLtype& x2){
  TLtype temp;
  temp.v=x1.v+x2.v;
  temp.t=x1.t+x2.t;
  
  return temp;
}

TLtype operator-(const TLtype& x1,const TLtype& x2){
  TLtype temp;
  temp.v=x1.v-x2.v;
  temp.t=x1.t-x2.t;
  
  return temp;
}


TLtype sin(const TLtype& x){
  TLtype temp;
  temp.v=sin(x.v);
  temp.t=cos(x.v)*x.t;
  
  return temp;
}

TLtype cos(const TLtype& x){
  TLtype temp;
  temp.v=cos(x.v);
  temp.t=-sin(x.v)*x.t;
  
  return temp;
}


TLtype exp(const TLtype& x){
  TLtype temp;
  temp.v=exp(x.v);
  temp.t=temp.v*x.t;

  return temp;
}



