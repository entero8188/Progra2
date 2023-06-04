#include <iostream>
#include <cmath>
#include "Cuadraturas.h"

double f(double );

int main(){
  double a=0;
  double b=5;
  double N=10;

  Cuadratura ec(a,b,N,f);

  cout << "trapezoidal: " << endl;
  ec.trapezoidal();
  cout << "simpson: " << endl;
  ec.simpson();
  cout << "richardson: " << endl;
  ec.richardson(10000);// esta cosa si es muy baja el error es super alto
  cout << "romberg: " << endl;
  ec.romberg();
  cout << "Gauss: " << endl;
  ec.gauss();

  return 0;
}

double f(double x){
  return (x*x*x*x); // Con polinomios de orden 4 gauss se cae a pedazos.
  //return (x*x*x+2*x*x+3*x+2); // con ordenes menores como estos funciona bien.
  //return (x*x + 6*x -8);
}


// el resultado analitico de integrar x^4 entre 0 y 5 es 625.
