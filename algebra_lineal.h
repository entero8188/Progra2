#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<vector>
#include<cmath>
#include "complejos.h"
#include "fracciones.h"
#include "dual.h"
#include <fstream>


using namespace std;

template <class T>
class Vector{
    private:
        int dim;
        vector<T> coeficientes; 
    public:
        Vector(){};
    
        Vector(vector<T> v){
            this->dim = v.size();
            this->coeficientes=v;
        } ;  

        ~Vector(){};

        Vector(const Vector<T> &v){
            this->dim=v.dim;
            this->coeficientes=v.coeficientes;
        };

        Vector<T> operator=(const Vector<T> &v){
            this->dim=v.dim;
            this->coeficientes=v.coeficientes;
            
        };

        vector<T> get_coeficientes(){
            return coeficientes;
        }; 
};

template<class T>
Vector<T> operator+(const Vector<T> &a, const Vector<T> &b){
    vector<T> coef1=a.get_coeficientes();
    vector<T> coef2=b.get_coeficientes();
    vector<T> suma;
    for(int i =0; i<a.size();i++){
        suma.push_back(a[i]+b[i];)
    }
    return suma;
}





template<class T>
Vector<T> operator-(const Vector<T> &a, const Vector<T> &b){
    vector<T> coef1=a.get_coeficientes();
    vector<T> coef2=b.get_coeficientes();
    vector<T> resta;
    for(int i =0; i<a.size();i++){
        resta.push_back(a[i]-b[i];)
    }
    return resta;
}



template<class T>
T operator*(const Vector<T> &a, const Vector<T> &b){
    vector<T> coef1=a.get_coeficientes();
    vector<T> coef2=b.get_coeficientes();
    T produc_punto=0;
    for(int i =0; i<a.size();i++){
        produc_punto+=a[i]*b[i];
    }
    return produc_punto;
}




#endif