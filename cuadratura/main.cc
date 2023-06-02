#include <iostream>
#include <cmath>
#include "Cuadraturas.h"

double f(double );

int main(){
  double a=0;
  double b=5;
  double N=10;

  Cuadratura ec(a,b,N,f);
  int fac = 1;

  cout << "trapezoidal: " << endl;
  ec.trapezoidal();
  cout << "simpson: " << endl;
  ec.simpson();
  cout << "richardson: " << endl;
  ec.richardson(10000);// esta cosa si es muy baja el error es super alto
  cout << "romberg: " << endl;
  ec.romberg();

  return 0;
}

double f(double x){
  return (x*x*x*x);
  //return (x*x + 6*x -8);
}


// el resultado analitico de integrar x^4 entre 0 y 5 es 625.
// el N aqui esta muy bajo, estaba probando..
