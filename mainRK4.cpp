#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include"rk4.h"

using namespace std;
//este es el main con el que se probó el rk4 
/*funcion que será la edo a resolver 
  uso un vector como input para poder tener una generalizacion para n variables
  (aunque en este caso solo uso 4)*/
vector<double> derivada(vector<double> variables){ // t, x, y, z
  vector<double> derivadas;

  double derivada_x = cos(variables[2]);
  double derivada_y = -sin(variables[1]);
  double derivada_z = 1;

  derivadas.push_back(derivada_x);
  derivadas.push_back(derivada_y);
  derivadas.push_back(derivada_z);

  return derivadas;

}

int main() {
  //aquí puede ser cualquier valor inicial en teoría
  vector<double> posicion = vector{0., 0., 0.};

  //inicializo un objeto de la clase con la edo a resolver
  RK4<double> mi_edo(derivada, posicion, 0., 10., 0.5);

  //guardo los puntos obtenidos en rk4.dat
  mi_edo.rk4("rk4.dat");
  return = 0;

}
