#ifndef DUAL
#define DUAL

#include <iostream>
#include <cmath>

class Dual{
  private:
    double val;
    double der;

    public:
      Dual();
      Dual(double val);
      Dual(double val,double der);

    double getDerivative() const;
    void setDerivative(double derivative);

    //Operators
    friend Dual operator+(const Dual& u, const Dual& v);
    friend Dual operator-(const Dual& u, const Dual& v);
    friend Dual operator*(const Dual& u, const Dual& v);
    friend Dual operator/(const Dual& u, const Dual& v);

    friend std::ostream& operator<<(std::ostream& os,const Dual& a);

    //Trig functions
    friend Dual sin(Dual d);
    friend Dual cos(Dual d);
    friend Dual exp(Dual d);
    friend Dual log(Dual d);
    friend Dual abs(Dual d);
    friend Dual pow(Dual d, double p);
};
#endif
