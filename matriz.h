#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <vector>

using namespace std;


template<class T>
class matriz
{
private:
    int filas;
    int columnas;
    vector<vector<T> > Matriz;
public:
    matriz(){
        
        this->columnas=static_cast<T>(0);
        this->filas=static_cast<T>(0);
    };
    ~matriz(){};

    int get_filas(){
        return this-> filas;
    }

    int get_columnas(){
        return this-> columnas;
    }




    matriz(vector<vector<T>> m){
        this->columnas=m[0].size();
        this->filas=m.size();
        this->Matriz=m;
    };

    matriz(const matriz<T> &m){
        this->columnas=m.columnas;
        this->filas=m.filas;
        this->Matriz=m.Matriz;
    };

    matriz<T> operator=(const matriz<T> &m){
        if(this!=&m){
            this->columnas=m.columnas;
            this->filas=m.filas;
            this->Matriz=m.Matriz;
        }
        return *this;

    }

    vector<T> operator[](int i){
        return this->Matriz[i];
    };

    /* matriz<T> operator+(matriz<T> m1, matriz<T> m2){
        matriz<T> resultado;
        for(int i =0; i< filas; i++){
            for(int j =0 ; j <  columnas;j++ ){
                resultado[i][j]=m2[i][j]+m1[i][j];
            }
        }
        return resultado;

    }; */

    void print(){
        matriz matriz=this->Matriz;
        for(int i=0; i < filas; i++){
            cout<<"[ ";
            for(int j=0; j < columnas; j++){
                cout<<matriz[i][j]<<" ";
            }
            cout<<"]\n";
        }

    };



















};



template<class T>
matriz<T> operator+(matriz<T> m1, matriz<T> m2){
        vector<vector<T> > resul;

        for(int i =0; i< m1.get_filas(); i++){
            vector<T> fila;
            for(int j =0 ; j <  m1.get_columnas();j++ ){
                fila.push_back(m2[i][j]+m1[i][j]);
            }
            resul.push_back(fila);
        }
        return matriz<T>(resul);

};

template<class T>
matriz<T> operator-(matriz<T> m1, matriz<T> m2){
        vector<vector<T> > resul;

        for(int i =0; i< m1.get_filas(); i++){
            vector<T> fila;
            for(int j =0 ; j <  m1.get_columnas();j++ ){
                fila.push_back(m2[i][j]-m1[i][j]);
            }
            resul.push_back(fila);
        }
        return matriz<T>(resul);

    };


template<class T, class T1>
matriz<T> operator*(const matriz<T> &m, T1 a){
    vector<vector<T> > resul;

    for(int i =0; i< m.get_filas(); i++){
        vector<T> fila;
        for(int j =0 ; j <  m.get_columnas();j++ ){
            fila.push_back(a*m[i][j]);
        }
        resul.push_back(fila);
    }
    return matriz<T>(resul);


}
template<class T, class T1>
matriz<T> operator*( T1 a, matriz<T> &m){
    vector<vector<T> > resul;

    for(int i =0; i< m.get_filas(); i++){
        vector<T> fila;
        for(int j =0 ; j <  m.get_columnas();j++ ){
            fila.push_back(a*m[i][j]);
        }
        resul.push_back(fila);
    }
    return matriz<T>(resul);


}













#endif