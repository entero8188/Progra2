#ifndef CUADRATURAS_H
#define CUADRATURAS_H
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Cuadratura{
  private:
    int a;
    int b;
    double N;
    double (*f)(double);
  public:
    Cuadratura(){};
    ~Cuadratura(){};
    Cuadratura(int a, int b, double N, double (*f)(double)){
      this-> a=a;
      this-> b=b;
      this-> N=N;
      this-> f=f;
    }

    // Aceleracion de Richardson 
    double R(int factor){
      double h=factor*((b-a)/N);
      //double h=(b-a)/N;
      double suma=0;
      double xk;
      for(int k=1; k<N; k++){
        xk = a + h*k;
        suma += f(xk);
  }

      //double I = ((h*factor)/2)*(f(a)+f(b)) + (h*factor)*suma;
      double I = (h/2)*(f(a)+f(b)) + h*suma;
      return I;
    }

    // El factor de richardson es basicamente el algoritmo trapezoidal
    // cuando el factor que multiplica a h es 1.
    void trapezoidal(){
      double I = R(1);
      cout << I << endl;
    }

    void simpson(){
      double h=(b-a)/N;
      double xk_impar;
      double suma_impar=0;
      for (int k=1; k<=(N/2); k++){
        xk_impar = a+h*(2*k-1);
        suma_impar += f(xk_impar);
      }


      double xk_par;
      double suma_par=0;
      for (int k=1; k<(N/2); k++){
        xk_par = a+h*(2*k);
        suma_par += f(xk_par);
      }

      double I = (h/3)*(f(a)+f(b)) + ((4./3.)*h)*suma_impar + ((2./3.)*h)*suma_par;

      cout << I << endl;
    }


    // aqui aplicamos el metodo de richardson. a menor valor de j menor el orden
    // de error (ver formula de la clase de toledo).
    void richardson(int j){
      double Q= R(1)+ ((R(1)-R(2))/pow(4,j)-1);
      cout << Q << endl;
    }

    // POR TERMINAR...
    void romberg(){

      vector<double> h;
      h.push_back(b-a);
      for (int i=1; i<N; i++){
        h.push_back((1/pow(2,i-1))*(b-a));
      }

      vector<vector<double>> M_R(N,vector<double>(N));
      double I_n = (1./2.)*(f(a)+f(b));
      for (int i=2; i<N; i++){
        double fx=0;
        for (int s=1; s<=pow(2,i-2); s++){
          fx += f(a + h[i]*(2*s-1));
        }
        M_R[0][i] = I_n;
        I_n = (1./2.)*I_n + h[i]*fx;
      }

      for (int i=0; i<N-1; i++){
        for (int j=0; j<N-1; j++){
          M_R[i+1][j+1] = M_R[i][j+1] + ((M_R[i][j+1]-M_R[i][j])/pow(4,i)-1);
        }
      }
      cout << M_R[N-1][N-1] << endl;



      //double h=(b-a)/N;
      //double xk_impar;
      //double suma_impar=0;
      //for (int k=1; k<N; k++){
      //  xk_impar = a+h*(2*k-1);
      //  suma_impar += f(xk_impar);
      //}
      //vector<vector<double>> M_R(N,vector<double>(N));

      //double I_n = R(1); 
      //for (int i=0; i<N; i++){
      //  M_R[0][i] = I_n;
      //  I_n = (1./2.)*I_n + suma_impar;
      //}
      //for (int i=0; i<N-1; i++){
      //  for (int j=0; j<N-1; j++){
      //    M_R[i+1][j+1] = M_R[i][j+1] + ((M_R[i][j+1]-M_R[i][j])/pow(4,i)-1);
      //  }
      //}
      //cout << M_R[N-1][N-1] << endl;
    }
};
#endif
