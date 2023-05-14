#ifndef DUAL_H
#define DUAL_H
#include <iostream>
#include <cmath>
#include "complejos.h"
#include "fracciones.h"
#include <fstream>

using namespace std;

template <class T>
class dual
{
 private:
  T P_real, P_dual1, P_dual2, P_dual3;//no podemos definir un atributo con el mismo nombre de la clase pq el compilador llora 

 public:
  dual();// constructor por defecto
  dual(T, T=static_cast<T>(0),T=static_cast<T>(0),T=static_cast<T>(0));// ojo
  ~dual();
  dual(const dual<T> &);//regla de la cadena
  T & operator()(int);//ojo
  T operator()(int) const;//ojo
  dual<T> operator=(const dual<T> &);
  dual<T> operator-();
  ostream & operator<<(const dual<T> &);
};

template<class T>
ostream & operator<<(ostream &os, const dual<T> c)
{
  os<<"{"<<c(0)<<", "<<c(1)<<", "<<c(2)<<", "<<c(3)<<"}";

  return os;
}

template <class T>
dual<T>::dual()
{
  P_real = static_cast<T>(0);
  P_dual1 = static_cast<T>(0);
  P_dual2 = static_cast<T>(0);
  P_dual3 = static_cast<T>(0);
  
}

template <class T>
dual<T>::dual(T a,T b, T c, T d)
{
  P_real = a;
  P_dual1 = b;
  P_dual2 = c;
  P_dual3 = d;

}

template <class T>
dual<T>::~dual()
{
}

template<class T>
dual<T>::dual(const dual<T> &d1)
{
  P_real=d1.P_real;
  P_dual1=d1.P_dual1;
  P_dual2=d1.P_dual2;
  P_dual3=d1.P_dual3;
}


template<class T>
T & dual<T>:: operator()(int i)
{
  if(i==0){
    return P_real;
  }

  else if(i==1){
    return P_dual1;
  }

  else if(i==2){
    return P_dual2;
  }

  else if(i==3){
    return P_dual3;
  }
}

template<class T>
T dual<T>:: operator()(int i) const
{
  if(i==0){
    return P_real;
  }

  else if(i==1){
    return P_dual1;
  }

  else if(i==2){
    return P_dual2;
  }

  else if(i==3){
    return P_dual3;
  }

}

template<class T>
dual<T> dual<T>:: operator=(const dual<T> &d1)
{ if(this!=&d1){
    P_real=d1.P_real;
    P_dual1=d1.P_dual1;
    P_dual2=d1.P_dual2;
    P_dual3=d1.P_dual3;
  }
  return *this;
}


template<class T>
dual<T> dual<T>::operator-()
{
  return dual<T>(-P_real,-P_dual1,-P_dual2,-P_dual3);
  ;
}




template<class T>
dual<T>  operator+(const dual<T> &d1, const dual<T> &d2)
{
  return dual<T>(d1(0)+d2(0),
  d1(1)+d2(1),
  d1(2)+d2(2),
  d1(3)+d2(3)
  );
}

template<class T>
dual<T> operator*(const dual<T> &d1, const dual<T> &d2)
{
  //e⁴=0
  //(a+be+ce²+de³)(w+xe+ye²+ze³)
  //=aw+axe+aye²+aze³+bwe+bxe²+bye³+cwe²+cxe³+wde³
  //=aw+
  //e(ax+bw)+
  //e²(ay+bx+cw)+
  //e³(az+by+cx+dw)
 
  return dual<T>(d1(0)*d2(0),
  d1(1)*d2(0)+d2(1)*d1(0),
  (d1(2)*d2(0)+2*d1(1)*d2(1)+d1(0)*d2(2)),
  (d1(3)*d2(0)+3*d1(2)*d2(1)+3*d1(1)*d2(2)+d1(0)*d2(3))
  
  );
}

template<class T>
dual<T>  operator/(const dual<T> &f, const dual<T> &g)
{
  T n1=g(0)*g(0);
  T n2= g(0)*g(0)*g(0);
  T n3=g(0)*g(0)*g(0)*g(0);
  return dual<T>(f(0)/g(0),
  (f(1)*g(0)-f(0)*g(1))/(n1),
  (g(0)*(f(2)*g(0)-f(0)*g(2)-2*(f(1)*g(0)-f(0)*g(1))))/n2,
  (2*g(0)*g(0)*g(1)*f(2)-f(0)*g(0)*g(1)*g(2)+f(3)*g(0)*g(0)*g(0)-g(0)*g(0)*f(1)*g(2)+f(0)*g(0)*g(0)*g(3)-5*g(0)*g(0)*f(2)+5*f(0)*g(0)*g(2)+6*g(0)*f(1)-6*f(0)*g(1))/n3
  
  
  
  
  
  );
}

// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1

template<class T, class T1>
dual<T> operator+(T1 x, const dual<T> &d){
  return dual<T>(x+d(0),d(1));
}


template<class T, class T1>
dual<T> operator+(const dual<T> &d, T1 x){
  return dual<T>(x+d(0),d(1));
}













template<class T, class T1>
dual<T> operator-(T1 x, const dual<T> &d){
  return dual<T>(x-d(0),-d(1));
}


template<class T, class T1>
dual<T> operator-(const dual<T> &d, T1 x){
  return dual<T>(d(0)-x,d(1));
}


















template <class T, class T1>
dual<T> operator*(T1 x, const dual<T> &d){
  return dual<T>(x*d(0),x*d(1));
}


template <class T, class T1>
dual<T> operator*(const dual<T> &d, T1 x){
  return dual<T>(x*d(0),x*d(1));
}









template <class T, class T1>
dual<T> operator/(T1 x, const dual<T> &d){
  return dual<T>(x/d(0),-x*d(1)/(d(0)*d(0)));
}


template <class T, class T1>
dual<T> operator/(const dual<T> &d, T1 x){
  return dual<T>(d(0)/x,d(1)/x);
}






















template<class T>
dual<T> cos(const dual<T> &x)
{
  return
    dual<T>
    (
     cos(x(0)),
     -sin(x(0))*x(1)
     );
}

template<class T>
dual<T> sin(const dual<T> &x)
{
  return
    dual<T>
    (
     sin(x(0)),
     cos(x(0))*x(1),
     cos(x(0))*x(2)-sin(x(0))*x(1)*x(1),
     cos(x(0))*x(3)-sin(x(0))*x(1)*x(2)-cos(x(0))*x(1)*x(1)*x(1)-2*sin(x(0))*x(1)*x(2)
     );
}

template<class T>
dual<T> tan(const dual<T> &x)
{
  return sin(x)/cos(x);
}

// template<fraccion<complejo<int>>>
// dual<double> f(const double &x)
// {
//   return dual<double>(x(4))

  
// }







#endif
