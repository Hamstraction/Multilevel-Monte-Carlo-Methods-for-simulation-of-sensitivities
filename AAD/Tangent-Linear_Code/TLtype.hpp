#ifndef TLTYPE_
#define TLTYPE_

class TLtype{
  public:
    double v;
    double t;

    TLtype(const double&);
    TLtype();
    TLtype& operator=(const TLtype&);
};

TLtype operator*(const TLtype&,const TLtype&);

TLtype operator+(const TLtype&,const TLtype&);

TLtype operator-(const TLtype&,const TLtype&);

TLtype sin(const TLtype&);

TLtype cos(const TLtype&);

TLtype exp(const TLtype&);

#endif
