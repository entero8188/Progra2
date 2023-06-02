#include "Enl.h"
#include "Dual.h"
#include <iostream>
#include <cmath>

double f(double );
double df(double );

int main(){
  double x_1=0.2;
  double x_2=0.9;
  int N=20;
  Enl ec(x_1, x_2, N, f);
  cout << "metodo de biseccion: " << endl;
  ec.biseccion();
  cout << "metodo de newton: " << endl;
  ec.newton(df);

  // la misma ecuacion pero otros limites. el metodo de secante requiere otros limites.
  // en realidad todos requieren distintos limites, todo depende de como se vea la 
  // grafica.
  double x_m=0.6;
  double x_n=1.0;
  Enl ec1(x_m, x_n, N, f);
  cout << "metodo de secante: " << endl;
  ec1.secante();


  return 0;
}

double f(double x){
  return ((5*x*x*x) - (2*x*cos(x/5)) -1);
  //return (x*x + 6*x -8);
}

double df(double x){
  Dual<double> dx(x,1,0,0,0);
  Dual<double> resultado((5*dx*dx*dx)-(2*dx*cos(dx/5))-1);
  return resultado(1);
}
