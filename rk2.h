#ifndef RK2_H
#define RK2_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//clase de rk2 (basandonos en el rk4 de la ayudantia) lo modifiqué acorde a lo que aparece en el pdf de edos
//lo hice para cachar mejor como funciona esto e igual por si acaso (aun no sé que hace)

template <class T>

class RK2{

 private:
  T dt = 0.1; //delta t
  T t_i; //tiempo inicial
  T t_f; //tiempo final
  
  //condiciones iniciales en t_i
  vector<T> posiciones_iniciales; //(x, y, z)
  //ecuaciones diff a resolver
  vector<T> (*derivadas)(vector<T>); //(t, x, y, z)

 public:
  //constructor generico
  RK2(){};
  //el fr fr
  RK2(vector<T> (*derivadas)(vector<T>),
      vector<T> posiciones_iniciales, T t_i,  T t_f,  T dt){

    this-> dt = dt;
    this-> t_i = t_i;
    this-> t_f = t_f;
    this-> posiciones_iniciales = posiciones_iniciales;
    this-> derivadas = derivadas;
  };

  
  //funcion que resulve la edo introducida al inicializar la clase
  void rk2(string nombre){
    T t = t_i;
    vector<T> posiciones = posiciones_iniciales;
    /*analogo a:
      x = posiciones_iniciales[0]
      y = posiciones_iniciales[0]
      ...*/
    // guarda los datos en "nombre"
    ofstream rk2;
    rk2.open(nombre);

    //numero variables
    int n_var = posiciones_iniciales.size();

    //guardo el valor de los k1, k2 para cada variable
    //analogo a crear k1_x, k1_y, ..., k2_x, k2_y ... k2_n
    vector<T> k1(n_var);
    vector<T> k2(n_var);

    /*valores en los cuales está evaluando k1, k2 para 
      cada componente incluye la variable independiente (t),
      por ello tiene tamaño n_var+1*/

    vector<T> posicion_k1(n_var+1);
    vector<T> posicion_k2(n_var+1);

    //comienza a calcular la solucion de edo hasta t_f
    while(t<t_f){
      //se guardan los datos de rk2
      rk2 << t << " ";
      for(int i = 0; i < n_var; i++){
	rk2 << posiciones[i] << " ";
      }
      rk2 << endl;

      //pongo los valores independientes en la coordenada 0
      posicion_k1[0] = t;
      posicion_k2[0] = t+dt;

      //calculo los valores de posicion_k1 para todas las variables
      //dado que ya puse el tiempo, comienzo desde i+1
      for(int i = 0; i < n_var; i++){
	posicion_k1[i+1] = posiciones[i];
      }
      k1 = derivadas(posicion_k1);
      
      //calculo posicion_k2 y k2
      //siguiendo los pasos del metodo runge-kutta
      for(int i = 0; i < n_var; i++){
	posicion_k2[i+1] = posiciones[i]+k1[i]*dt;
      }
      k2 = derivadas(posicion_k2);

      /*lo anterior es analogo (para el caso n_var=3) a lo siguiente:
	k1 = derivadas(t, x, y, z);
	k2 = derivadas(t+dt, x + k1[0]*dt, y 
	+ k1[1]*dt, z + k1[2]*dt);
	(notese que habría que definir de forma distinta la función
	derivadas a como se hizo en la parte sin comentar)*/

      /*encontramos las siguientes posiciones para cada
	componente realizando un promedio sobre k1, k2,*/
      for(int i = 0; i<n_var; i++){
	posiciones[i] = posiciones[i] + 1./2.*
	  (k1[i]+k2[i])*dt;
      }
      t = t+dt;
    }
    rk2.close();
  }
};

#endif
