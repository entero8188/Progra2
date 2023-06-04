#ifndef RLS_H
#define RLS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;
// Regresion lineal simple (Rls) (no usando matrices), para una expresion Y = a_1 + a_2(X)

class Rls{
	private:
		string nombre_archivo;
		vector<double> x; 
		vector<double> y;
		vector<double> sigma; // los errores

		// estos son los elementos que se operan posteriormente en los calculos.
		vector<double> xx;
		vector<double> xy;
		vector<double> X;
		vector<double> Y;
		vector<double> s;
		double S;
		
	public:
		Rls(){};
		~Rls(){};
		Rls(string nombre_archivo, int n_col=1, int col_error=0){
			this-> nombre_archivo = nombre_archivo;

			// similar a los splines, obtenemos los double a partir del archivo..
			vector<string> lineas = lector(nombre_archivo);
			vector<vector<string>> datos_string = separador(lineas);


  		for(int i=0; i<datos_string.size();i++){
  		    this-> x.push_back(stod(datos_string[i][0]));
  		    this-> y.push_back(stod(datos_string[i][n_col]));
  		}

			// si especificamos la columna perteneciente al error
			if (col_error != 0){
  			for(int i=0; i<datos_string.size();i++){
					// entonces creamos el vector de double con los datos correspondientes.
  			    this-> sigma.push_back(stod(datos_string[i][col_error]));
  			}
			}
			else{ // sino tomamos cada valor sigma_i constante = 1
  			for(int i=0; i<datos_string.size();i++){
  			    this-> sigma.push_back(1);
  			}
			}


  		for(int i=0; i<x.size();i++){
				this-> xx.push_back((x[i]*x[i])/(sigma[i]*sigma[i]));
  		}

  		for(int i=0; i<y.size();i++){
				this-> xy.push_back((x[i]*y[i])/(sigma[i]*sigma[i]));
  		}

  		for(int i=0; i<x.size();i++){
				this-> X.push_back((x[i])/(sigma[i]*sigma[i]));
  		}

  		for(int i=0; i<y.size();i++){
				this-> Y.push_back((y[i])/(sigma[i]*sigma[i]));
  		}

  		for(int i=0; i<sigma.size();i++){
				this-> s.push_back(1/(sigma[i]*sigma[i]));
  		}
		};


		vector<string> lector(string texto){
			vector<string> lineas;
			string linea;
			ifstream myfile(texto);
			while(getline(myfile, linea)){
				lineas.push_back(linea);
			}
			return lineas;
		}
					
		vector<vector<string>> separador(vector<string> lineas){
		    vector<vector<string>> palabras;
		
		    for(int i=0; i<lineas.size(); i++){
		
		        vector<string> vectori;
		        string palabra= " ";
		
		        for(int j=0; j<=lineas[i].length();j++){
		
		            char caracter=lineas[i][j];
		
		            if(caracter=='\t' || caracter==' ' || j==lineas[i].length()){
		                vectori.push_back(palabra);
		                palabra= " ";
		            }
		            else{
		                palabra.push_back(caracter);
		            }
		        }
		
		        palabras.push_back(vectori);
		    }
		    return palabras;
		}

		// Esta funcion suma los elementos internos de un vector.
		double Suma(vector<double> &x, double i=0, double N=0){
		
			// si no especificamos un limite superior
			if (N == 0){
				// es el tamaño del vector
				N = x.size();
			}
		
			double sum = 0;
			for (i; i<N; i++){
				sum += x[i];
			}
			return sum;
		}

		// calcula y retorna a_1 o a_2 (nom significa n(intercepto) o m(pendiente))
		double a(int nom){

			double S = Suma(s);

			// el intercepto.
			double a_1 = (Suma(Y)*Suma(xx) - Suma(X)*Suma(xy))/((S*Suma(xx)) - (Suma(X)*Suma(X)));

			// la pendiente.
			double a_2 = ((S*Suma(xy))-Suma(X)*Suma(Y))/((S*Suma(xx))-(Suma(X)*Suma(X)));


			return ((nom == 1) ? a_1 : a_2);

		}

		double error(int nom){
			double S = Suma(s);
			// error de a_1 (intercepto)
			double sigma_a1 = sqrt(Suma(xx)/((S*Suma(xx))-(Suma(X)*Suma(X))));
			// error de a_2 (pendiente)
			double sigma_a2 = sqrt(S/((S*Suma(xx))-(Suma(X)*Suma(X))));

			return ((nom == 1) ? sigma_a1 : sigma_a2);

		}

		// imprime
		void regresion(){
			cout << "La ecuacion lineal que representa los datos del archivo son: ";
			cout << "y=" << a(2) << "x + " << a(1) << endl; 
		}

};

#endif
