#ifndef A_INCLUDED
#define A_INCLUDED
#define A_TAPE_SIZE 1000000

#define A_UNDEF -1
#define A_CONST 0
#define A_ASG 1
#define A_ADD 2
#define A_SUB 3
#define A_MUL 4
#define A_SIN 5
#define A_COS 6
#define A_EXP 7

class A_TapeEntry{
  public:
    int oc;
    int arg1;
    int arg2;
    double v;
    double a;
    A_TapeEntry() : oc(A_UNDEF), arg1(A_UNDEF), arg2(A_UNDEF), v(0), a(0) {}; 
};

class Atype{
  public:
    int va;
    double v;
    Atype() : va(A_UNDEF), v(0) {};
    Atype(const double&);
    Atype& operator=(const Atype&);
};

Atype operator*(const Atype&, const Atype&);
Atype operator+(const Atype&, const Atype&);
Atype operator-(const Atype&, const Atype&);

Atype sin(const Atype&);
Atype cos(const Atype&);
Atype exp(const Atype&);

void A_PrintTape();
void A_InterpretTape();
void A_ResetTape();
#endif
