//Code snippet for example of manual adjoint differenciation


double C(
  const double S0,
  const double r,
  const double y,
  const double sig,
  const double K,
  const double T,

  //Adjoints
  //
  const bool calcAdjoints = false,
  double *S0_ = nullptr,
  double *r_ = nullptr,
  double *y_ = nullptr,
  double *sig_ = nullptr,
  double *K_ = nullptr,
  double *T_ = nullptr,

  const double C_ = 1.0
  )
{
  const double sqrtT = sqrt(T);
  const double df = exp(-r*T);
  const double F = S0*exp((r-y)*T);
  const double std = sig*sqrtT;
  const double d = log(F/K)/std;
  const double d1 = d+0.5*std;
  const double d2 = d-0.5*std;
  const double nd1 = normalCdf(d1);
  const double nd2 = normalCdf(d2);
  const double v = df*(F*nd1-K*nd2);

  //Calculation
  //
  double v_ = C_;

  double df_ = v_*(F*nd1-K*nd2);
  double F_ = v_*df*nd1;
  double nd1_ = v_*df*F;

  if(K_){
    *K = -v_*df*nd2;
  }
  double nd2_ = -v_*df*K;

  //Normal density
  //
  double d2_ = nd2_*normalDens(d2);
  double d1_ = nd1_*normalDens(d1);

  double d_ = d2_;
  double std_ = -0.5*d2_;
  d_ += d1_;

  std_ += 0.5*d1_;

  F_ += d_/(F*std);
  if(K_){
    *K -= d_/(K*std);
  }
  std_ -+d_*d/std;

  if(sig_) *sig += std*sqrtT;

  if(T_) *T_ += 0.5*std_*sig/sqrtT;

  if(S0_) *S0_ += F_*F/S0;

  if(r_) *r_ += F_*T*F;

  if(y_) *y_ -= F_*T*F;

  if(T_) *T += F_*(r-y)*F;

  if(r_) *r += -df_*df*T;

  if(T_) *T += -df_*df*r;

  return v;
}


