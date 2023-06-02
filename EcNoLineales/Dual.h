#include <iostream>
#include <cmath>

using namespace std;

// Duales hasta la 4ta derivada.
template <class T>
class Dual
{
 private:
  T parte_real, parte_Dual, parte_Dual2, parte_Dual3, parte_Dual4;

 public:
                    /* CONSTRUCTORES */
  Dual();// defecto
  Dual(T, T=static_cast<T>(0), T=static_cast<T>(0), T=static_cast<T>(0), T=static_cast<T>(0));// generico
  ~Dual(); // destructor
  Dual(const Dual<T> &); // constructor de copia

  Dual<T> operator=(const Dual<T> &);// asignacion
  Dual<T> operator-(); 

  T & operator()(uint);//lecto-escritura
  T operator()(uint) const;//solo lectura
};

template <class T>
Dual<T>::Dual()
{
  parte_real = static_cast<T>(0);
  parte_Dual = static_cast<T>(0);
  parte_Dual2 = static_cast<T>(0);
  parte_Dual3 = static_cast<T>(0);
  parte_Dual4 = static_cast<T>(0);
}

template <class T>
Dual<T>::Dual(T a,T b, T c, T d, T e)
{
  parte_real = a;
  parte_Dual = b;
  parte_Dual2 = c;
  parte_Dual3 = d;
  parte_Dual4 = e;
}

template <class T>
Dual<T>::~Dual()
{
}

template <class T>
Dual<T>::Dual(const Dual<T> &x)
{
  parte_real = x.parte_real;
  parte_Dual = x.parte_Dual;
  parte_Dual2 = x.parte_Dual2;
  parte_Dual3 = x.parte_Dual3;
  parte_Dual4 = x.parte_Dual4;
}

template <class T>
Dual<T> Dual<T>::operator=(const Dual<T> &x)
{
  if(this != &x)
    {
      parte_real = x.parte_real;
      parte_Dual = x.parte_Dual;
      parte_Dual2 = x.parte_Dual2;
      parte_Dual3 = x.parte_Dual3;
      parte_Dual4 = x.parte_Dual4;
    }

  return *this;
}

template <class T>
Dual<T> Dual<T>::operator-()
{
  return Dual<T>(-parte_real,-parte_Dual, -parte_Dual2, -parte_Dual3, -parte_Dual4);
}

template <class T>
T & Dual<T>::operator()(uint i)
{
  switch(i)
    {
    case 0:
      return parte_real;
      break;
    case 1:
      return parte_Dual;
      break;
    case 2:
      return parte_Dual2;
      break;
    case 3:
      return parte_Dual3;
      break;
    case 4:
      return parte_Dual4;
      break;
    default:
      cout<<"error!!!!\n";
      return parte_real;
    }
}


template <class T>
T Dual<T>::operator()(uint i) const
{
  switch(i)
    {
    case 0:
      return parte_real;
      break;
    case 1:
      return parte_Dual;
      break;
    case 2:
      return parte_Dual2;
      break;
    case 3:
      return parte_Dual3;
      break;
    case 4:
      return parte_Dual4;
      break;
    default:
      cout<<"error!!!!\n";
      return parte_real;
    }
}

// SUMAS
template <class T>
Dual<T> operator+ (const Dual<T> &c1, const Dual<T> &c2){
  return Dual<T>(
     c1(0)+c2(0),
     c1(1)+c2(1),
     c1(2)+c2(2),
     c1(3)+c2(3),
     c1(4)+c2(4)
     );
}

template<class T, class T1>
Dual<T> operator+(T1 x, const Dual<T> &d){
  return Dual<T>(x+d(0),d(1),d(2),d(3),d(4));
}

template<class T, class T1>
Dual<T> operator+(const Dual<T> &d, T1 x){
  return Dual<T>(x+d(0),d(1),d(2),d(3),d(4));
}

// RESTAS
template <class T>
Dual<T> operator- (const Dual<T> &c1, const Dual<T> &c2){
  return Dual<T>(
     c1(0)-c2(0),
     c1(1)-c2(1),
     c1(2)-c2(2),
     c1(3)-c2(3),
     c1(4)-c2(4)
     );
}

template<class T, class T1>
Dual<T> operator-(T1 x, const Dual<T> &d){
  return Dual<T>(x-d(0),d(1),d(2),d(3),d(4));
}

template<class T, class T1>
Dual<T> operator-(const Dual<T> &d, T1 x){
  return Dual<T>(d(0)-x,d(1),d(2),d(3),d(4));
}

// como el numero Dual es distinto de cero cuando se le opera a si mismo entonces
template <class T>
Dual<T> operator* (const Dual<T> &c1, const Dual<T> &c2){
  return Dual<T>(
      c1(0)*c2(0),       // real
      c1(0)*c2(1)+c1(1)*c2(0), // primera derivada
     c1(0)*c2(2)+2*c1(1)*c2(1)+c1(2)*c2(0), // segunda derivada
     c1(0)*c2(3)+3*c1(1)*c2(2)+3*c1(2)*c2(1)+c1(3)*c2(0), // tercera derivada
     c1(0)*c2(4)+4*c1(1)*c2(3)+4*c1(2)*c2(2)+4*c1(3)*c2(1)+c1(4)*c2(0) // cuarta derivada
     );
}

template <class T, class T1>
Dual<T> operator* (T1 x, const Dual<T> &c1)
{
  return
    Dual<T>
    (
     x*c1(0),
     x*c1(1),
     x*c1(2),
     x*c1(3),
     x*c1(4)
     );
}

template <class T, class T1>
Dual<T> operator* (const Dual<T> &y, T1 x)
{
  return
    Dual<T>
    (
     x*y(0),
     x*y(1),
     x*y(2),
     x*y(3),
     x*y(4)
     );
}

template <class T>
Dual<T> operator/(const Dual<T> &c1, const Dual<T> &c2)
{
  return
    Dual<T>(
     c1(0)/c2(0)
     );
}


template <class T>
Dual<T> operator/(T x, const Dual<T> &y)
{
  return
    Dual<T>
    (
     x/y(0),
     -x*y(1)/(y(0)*y(0))
     );
}


template <class T, class T1>
Dual<T> operator/(const Dual<T> &y, T1 x)
{
  return
    Dual<T>
    (
     y(0)/x,
     y(1)/x,
     y(2)/x,
     y(3)/x,
     y(4)/x
     );
}

template <class T>
ostream & operator<<(ostream &os, const Dual<T> &x)
{
  os<<"{"<<x(0)<<", "<<x(1)<< ", " << x(2) << ", " << x(3) << ", " << x(4) << "} \n";

  return os;
}

template<class T>
Dual<T> cos(const Dual<T> &x)
{
  return
    Dual<T>
    (
     cos(x(0)),
     -sin(x(0))*x(1),
     -1*(cos(x(0))*x(1)*x(1)+sin(x(0))*x(2)),
     sin(x(0))*x(1)-cos(x(0))*2*x(1)*x(2)-cos(x(0))*x(1)*x(2)-sin(x(0))*x(3),
     0
     );
}

template<class T>
Dual<T> sin(const Dual<T> &x)
{
  return
    Dual<T>
    (
     sin(x(0)),
     cos(x(0))*x(1),
     cos(x(0))*x(2)-sin(x(0))*x(1)*x(1),
     cos(x(0))*x(3)-sin(x(0))*x(1)*x(2)-cos(x(0))*x(1)*x(1)*x(1)-2*sin(x(0))*x(1)*x(2)
     );
}


// incompleto, falta division. El resto esta ok.

