#ifndef COMPLEJOS_H
#define COMPLEJOS_H
#include <iostream>
#include <cmath>
#include "dual.h"
#include "fracciones.h"

using namespace std;


template <class T>
class complejo
{
    private:
        T real;
        T imaginaria;
    public:
        complejo();
        complejo(const T&, const T&);
        ~complejo();
        complejo(const complejo<T> &);
        T & operator()(bool);
        T operator()(bool) const;
        complejo<T> operator=(const complejo<T> &);
        ostream & operator<<(const complejo<T> &);  
        double modulo();
        complejo<T> conjugado();    

};

template<class T>
ostream & operator<<(ostream &os, const complejo<T> &c)
{
  os<<"{"<<c(0)<<"+ "<<c(1)<<"i}";
  return os;
}

template<class T>
complejo<T>::complejo(){
    real=static_cast<T>(0);
    imaginaria=static_cast<T>(0);
}

template<class T>
complejo<T>::complejo(const T &re,const  T &im){
    real=re;
    imaginaria=im;
}

template<class T>
complejo<T>::~complejo()
{}

template<class T>
T & complejo<T>:: operator()(bool i)
{
    return (i==0) ? real : imaginaria;
}

template<class T>
T complejo<T>:: operator()(bool i) const
{
    return (i==0) ? real : imaginaria;
}

template<class T>
complejo<T>::complejo(const complejo<T> &c)
{
    real=c.real;
    imaginaria=c(1);
}

template<class T>
complejo<T> complejo<T>::operator=(const complejo<T> &c)
{
    if (this !=&c){
        real=c.real;
        imaginaria=c.imaginaria;

    }
    return *this;
}

template<class T>
complejo<T> complejo<T>::conjugado(){

  return complejo<T>(real,-imaginaria);
}









template<class T>
complejo<T>  operator+(const complejo<T> &c1, const complejo<T> &c2)
{
  return complejo<T>(c1(0)+c2(0),
  c1(1)+c2(1));
}

template<class T,class T1>
complejo<double>  operator+(const complejo<T> &c1, const complejo<T1> &c2)
{
  return complejo<double>(c1(0)+c2(0),
  c1(1)+c2(1));
}





template<class T>
complejo<T>  operator-(const complejo<T> &c1, const complejo<T> &c2)
{
  return complejo<T>(c1(0)-c2(0),
  c1(1)-c2(1));
}

template<class T,class T1>
complejo<double>  operator-(const complejo<T> &c1, const complejo<T1> &c2)
{
  return complejo<double>(c1(0)-c2(0),
  c1(1)-c2(1));
}





template<class T>
complejo<T> operator*(const complejo<T> &c1, const complejo<T> &c2){
  return (
    complejo<T>(c1(0)*c2(0)-c1(1)*c2(1),c1(0)*c2(1)+c1(1)*c2(0))
  );

}

template<class T,class T1>
complejo<double> operator*(const complejo<T> &c1, const complejo<T1> &c2){
  return (
    complejo<double>(c1(0)*c2(0)-c1(1)*c2(1),c1(0)*c2(1)+c1(1)*c2(0))
  );

}





template<class T>
complejo<T> operator/(const complejo<T> &c1, const complejo<T> &c2){
  complejo<T> resultado;
  
  resultado(0)=(c1(0)*c2(0)+c1(1)*c2(1))/(c2(0)*c2(0)+c2(1)*c2(1));
  resultado(1)=(c1(1)*c2(0)-c1(0)*c2(1))/(c2(0)*c2(0)+c2(1)*c2(1));
  return resultado;
}

template<class T,class T1>
complejo<double> operator/(const complejo<T> &c1, const complejo<T1> &c2){
  complejo<double> resultado;
  
  resultado(0)=(c1(0)*c2(0)+c1(1)*c2(1))/(c2(0)*c2(0)+c2(1)*c2(1));
  resultado(1)=(c1(1)*c2(0)-c1(0)*c2(1))/(c2(0)*c2(0)+c2(1)*c2(1));
  return resultado;
}






template<class T>
double complejo<T>::modulo()
{
  double resultado=sqrt(real*real+imaginaria*imaginaria);
  return resultado;
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









template<class T,class T1>
complejo<T>  operator+(T1 c1, const complejo<T> &c2)
{
  return complejo<T>(c1+c2(0),
  c2(1));
}

template<class T,class T1>
complejo<T>  operator+(const complejo<T> &c1, T1 c2)
{
  return complejo<T>(c1(0)+c2,
  c1(1));
}






template<class T,class T1>
complejo<T>  operator-(T1 c1, const complejo<T> &c2)
{
  return complejo<T>(c1-c2(0),
  -c2(1));
}

template<class T,class T1>
complejo<T>  operator-(const complejo<T> &c1, T1 c2)
{
  return complejo<T>(c1(0)-c2,
  c1(1));
}









template<class T,class T1>
complejo<T> operator*(const complejo<T> &c1, T1 c2){
  return (
    complejo<T>(c1(0)*c2,c1(1)*c2)
  );

}

template<class T,class T1>
complejo<T> operator*(T1 c1, const complejo<T> &c2){
  return (
    complejo<T>(c2(0)*c1,c2(1)*c1)
  );

}




template<class T,class T1>
complejo<T> operator/(T1 c1, const complejo<T> &c2){
  complejo<T> resultado;
  
  resultado(0)=(c1*c2(0)/(c2(0)*c2(0)+c2(1)*c2(1)));
  resultado(1)=(-c1*c2(1)/(c2(0)*c2(0)+c2(1)*c2(1)));
  return resultado;
}


template<class T,class T1>
complejo<T> operator/(const complejo<T> &c1, T1 c2){
  complejo<T> resultado;
  
  resultado(0)=(c1(0)/c2);
  resultado(1)=(c1(1)/c2);
  return resultado;
}




template<class T>
complejo<T> sin(const complejo<T> &c){
  return complejo<T>(
    cosh(c(1))*sin(c(0)), 
    cos(c(0))*sinh(c(1))
    );
}


template<class T>
complejo<T> cos(const complejo<T> &c){
  return complejo<T>(
    cos(c(0))*cosh(c(1)),
    -sin(c(0))*sinh(c(1))
  );
}

template<class T>
complejo<T> tan(const complejo<T> &c){
  return sin(c)/cos(c);
}


template<class T>
complejo<T> exp(const complejo<T> &c){
  return complejo<T>(
    exp(c(0))*cos(c(1)),
    exp(c(0))*sin(c(1))
  );

}



//({-10.8362+ 2.75242i}/{1+ 1i})




















#endif
// comentario para ver como funciona github
// comentario 2