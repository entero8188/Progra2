#ifndef ENL_H
#define ENL_H

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
// CLASE PARA UNA SOLA DIMENSION
class Enl{
  private:
    double x_1;
    double x_2;
    int N;
    double (*f)(double ); 
  public:
    Enl(){};
    ~Enl(){};
    Enl(double x_1, double x_2, int N, double (*f)(double)){
      this-> x_1 = x_1;
      this-> x_2 = x_2;
      this-> N = N;
      this-> f = f;
    }

    void biseccion(){
      double x_c;
      double x_a = x_1;
      double x_b = x_2;
      int contador = 0;

      while (contador < N){
        x_c = (x_a+x_b)/2.;
        double fx_c = f(x_c);

        if (fx_c < 0){
          x_a = x_c;
        }

        if (fx_c > 0){
          x_b = x_c;
        }

        contador++;
      }
      cout << x_c << endl;
    }

    void newton(double (*df)(double )){
      double x_n = x_1;
      int contador = 0;

      while (contador < N){
        x_n = x_n - f(x_n)/df(x_n);
        contador++;
      }
      cout << x_n << endl;
    }

    void secante(){
      double x_m = x_1;
      double x_n = x_2;
      int contador = 0;

      while (contador < N){
        x_n = x_n - (f(x_n)*((x_n-x_m)/(f(x_n)-f(x_m))));
        contador++;
      }
      cout << x_n << endl;
    }
};

#endif
