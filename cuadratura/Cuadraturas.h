#ifndef CUADRATURAS_H
#define CUADRATURAS_H
#include <cmath>
#include <ostream>
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

    void romberg(){

      // Guiandome por los apuntes de nombre 'mfm' en u-cursos, se tiene un h variable
      vector<double> h;
      h.push_back(b-a);// h_0 = b-a
      for (int i=1; i<N; i++){
        h.push_back((1/pow(2,i-1))*(b-a)); // el resto: h_i = (1/2^i)*(b-a)
      }
      // asi hasta un h_n

      // declaramos nuestra matriz de tamaño NxN
      vector<vector<double>> M_R(N,vector<double>(N));
      double I_n = (1./2.)*(f(a)+f(b));// este primer I_n es I_0
      M_R[0][0] = I_n; // Recordemos:   R_0,0 = I_0
      I_n = (1./2.)*h[1]*(f(a)+f(b)); // ahora tendriamos I_n como I_1
      M_R[1][0] = I_n; // Recordemos R_1,0 = I_1

      // en general R_i,0 = I_i, entonces empezando en 2 tenemos
      for (int i=2; i<N; i++){

        double suma=0;
        // este for es para una suma que se ve en la formula
        // esta sumatoria empieza en 1 y termina en 2^(n-2).
        for (int s=1; s<=pow(2,i-2); s++){
          suma += f(a + h[i]*(2*s-1));
        }
        // 'la formula'... I_n = ... I_n-1
        I_n = (1./2.)*I_n + h[i]*suma;
        M_R[i][0] = I_n;
      }

      // Ahora que tenemos ya toda la primera columna de la matriz
      // usamos la expresion de richardson para calcular las otras columnas

      // este for externo cambia de columnas
      for (int j=0; j<N-1; j++){
        // este for interno genera todos los elementos de la siguiente columna
        for (int i=j; i<N-1; i++){ // i=j para crear la matriz triangular sup. con ceros.
          M_R[i+1][j+1] = M_R[i+1][j] + ((M_R[i+1][j]-M_R[i][j])/(pow(4,j+1)-1));
        }
      }
      // el resultado final de romberg
      cout << M_R[N-1][N-1] << endl;

      // SI QUIEREN, impriman la matriz para que vean como queda descomenten el for de abajo. (si prueban un N muy grande no lo recomiendo).


      //for (int i=0; i<N; i++){
      //  for (int j=0; j<N; j++){
      //    cout << M_R[i][j] << " ";
      //  }
      //  cout << endl;
      //}
    }

    // FUNCIONES NECESARIAS PARA GAUSS 
    double t(double x){
      return (((b-a)/2)*x + ((a+b)/2));
    } 
    
    double P(double x){
      return (((b-a)/2)*f(t(x)));
    }


    void gauss(){
      // gauss con dos puntos..
      double x_1 = -(sqrt(3)/3);
      double x_2 = sqrt(3)/3;
      double w_1=1;
      double w_2=1;


      double I = w_1*P(x_1) + w_2*P(x_2);
      cout << I << endl;
    }
};


#endif
