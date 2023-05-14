#ifndef FRACCIONES_H
#define FRACCIONES_H

#include<iostream>
#include<cmath>
#include "complejos.h"
#include "dual.h"

using namespace std;



template <class T>
class fraccion
{
    private:    
        T numerador;
        T denominador;

    public: 
        fraccion();
        fraccion(T=static_cast<T>(0), T=static_cast<T>(1));
        void simplificar();
        int MCD(const T &, const T &);
        ~fraccion();
        fraccion(const fraccion<T> &);
        T & get_numerador();//lecto-escritura
        T get_numerador() const;//solo lectura
        T & get_denominador();
        T get_denominador()const;
        fraccion<T> operator=(const fraccion<T> &);
        ostream & operator<<(const fraccion<T> &);

};

template<class T>
ostream & operator<<(ostream &os, const fraccion<T> &f){
    os<<"("<<f.get_numerador()<<"/"<<f.get_denominador()<<")";

  return os;

}

template<class T>
fraccion<T>::fraccion(){
    numerador = static_cast<T>(0);
    denominador= static_cast<T>(1);
}



template<class T>
fraccion<T>::fraccion(T num, T den){
    numerador = num;
    denominador= den;
}


template<class  T>
void fraccion<T>::simplificar(){
    int mcd = this ->MCD(numerador,denominador);
    numerador/=mcd;
    denominador/=mcd;
}

template<class T>
int fraccion<T>::MCD(const T &a,const T &b)
{
    if(b==0){
        return a;
    }
    return MCD(b,a%b);
}


template<class T>
fraccion<T>::~fraccion(){}

template<class T>
fraccion<T>::fraccion(const fraccion<T> &f){
    numerador=f.numerador;
    denominador=f.get_denominador();
}



template<class T>
T &fraccion<T>::get_numerador(){
    return numerador;
}


template<class T>
T fraccion<T>::get_numerador() const{
    return numerador;
}




template<class T>
T &fraccion<T>::get_denominador(){
    return denominador;
}


template<class T>
T fraccion<T>::get_denominador() const{
    return denominador;
}


template <class T>
fraccion<T> fraccion<T>:: operator=(const fraccion<T> &f)
{
    if(this!=f){
        numerador=f.numerador;
        denominador=f.denominador;
    }

    return *this;
}








template<class T>
fraccion<T> operator+(const fraccion<T> &f1,const fraccion<T> &f2)
{   
    
    return fraccion<T>((f1.get_numerador()*f2.get_denominador()+f1.get_denominador()*f2.get_numerador()),f1.get_denominador()*f2.get_denominador());
}

template<class T>
fraccion<T> operator-(const fraccion<T> &f1,const fraccion<T> &f2)
{
    return fraccion<T>(f1.get_numerador()*f2.get_denominador()-f1.get_denominador()*f2.get_numerador(),f1.get_denominador()*f2.get_denominador());
}

template<class T>
fraccion<T> operator*(const fraccion<T> &f1,const fraccion<T> &f2)
{
    return fraccion<T>(f1.get_numerador()*f2.get_numerador(),f1.get_denominador()*f2.get_denominador());
}

template<class T>
fraccion<T> operator/(const fraccion<T> &f1,const fraccion<T> &f2)
{
    return fraccion<T>(f1.get_numerador()*f2.get_denominador(),f1.get_denominador()*f2.get_numerador());
}

// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0
// 0

template<class T, class T1>
fraccion<T> operator+(const fraccion<T> &f1, T1 f2)
{
    fraccion<T> resultado(f1.get_numerador()+f1.get_denominador()*f2,f1.get_denominador());
    
    return resultado;
}

template<class T, class T1>
fraccion<T> operator-(const fraccion<T> &f1,T1 f2)
{   fraccion<T> resultado(f1.get_numerador()-f1.get_denominador()*f2,f1.get_denominador());
    
    return resultado;
}

template<class T, class T1>
fraccion<T> operator*(const fraccion<T> &f1, T1 f2)
{
    fraccion<T> resultado(f1.get_numerador()*f2,f1.get_denominador());
 
    return resultado;
}

template<class T, class T1>
fraccion<T> operator/(const fraccion<T> &f1,T1 f2)
{
    fraccion<T> resultado(f1.get_numerador(),f2*f1.get_denominador());

    return resultado;
}



template<class T, class T1>
fraccion<T> operator+(T1 f2, const fraccion<T> &f1)
{
    fraccion<T> resultado(f1.get_numerador()+f1.get_denominador()*f2,f1.get_denominador());

    return resultado;
}

template<class T, class T1>
fraccion<T> operator-(T1 f1,const fraccion<T> &f2)
{   fraccion<T> resultado(f1*f2.get_denominador()-f2.get_numerador(),f2.get_denominador());

    return resultado;
}

template<class T, class T1>
fraccion<T> operator*(T1 f2, const fraccion<T> &f1)
{
    fraccion<T> resultado(f1.get_numerador()*f2,f1.get_denominador());
 
    return resultado;
}

template<class T, class T1>
fraccion<T> operator/(T1 f1,const fraccion<T> &f2)
{
    fraccion<T> resultado(f2.get_denominador()*f1,f2.get_numerador());

    return resultado;
}






















#endif
