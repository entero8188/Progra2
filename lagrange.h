#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <iostream>
#include <cmath>
#include<fstream>
#include<vector>




using namespace std;
typedef unsigned int uint;

class lagrange{
    private:
        string name_archivo;

        vector<vector<double>> datos;

        vector<vector<double>> datos_interpolados;


    public:




        lagrange(string name_archivo, int n_columna=1){
            this->name_archivo=name_archivo;

            vector<string> lineas=lector(name_archivo);
            vector<vector<string> >datos_string=separador(lineas);

            vector<double> t;
            vector<double> x;

            for(int i=0; i<datos_string.size();i++){
                t.push_back(stod(datos_string[i][0]));
                x.push_back(stod(datos_string[i][n_columna]));

            }

            this->datos.push_back(t);
            this->datos.push_back(x);

            this->datos_interpolados=interpolacion(datos);

        };


        vector<vector<double>> get_lagrange(){
            return datos_interpolados;
        };



        double calcular(double &x,//punto a evaluar
        vector<double> &t,//tiempo
         vector<double> &datos){//numero de particiones del intervalo
            /* esta funcion lo que hace es devolver 
            f_i/[(x_0-x_1)*...*(x_0-x_{i-1})*(x_0-x_{i+1})*...*(x_0-x_n)]
            */

            vector<double> divisores;
            double resultado=1;

            for(int i =0; i<t.size(); i++){
                double producto=1;

                for(int j=0; j<t.size();j++){
                    if(i==j){

                    }

                    else{
                        producto*=(x-t[j])/(t[i]-t[j]);
                    }

                }
                divisores.push_back(producto);

            }

            for(int i=0;i<divisores.size();i++){
                resultado+=datos[i]*divisores[i];
            }
            return resultado;
        };




        








        vector<vector<double>> interpolacion(vector<vector<double>> datos){
            vector<double> t= datos[0];
            vector<double> x= datos[1];

            int n=t.size()-1;

            
            double t_j=t[0];
            double polinomio;
            int puntos_interpolacion=10;

            vector<vector<double>> interpolacion;

            for(int i=0; i<=n-1;i++){
                
                for(int j=0; j<puntos_interpolacion;j++){


                    polinomio=calcular(t_j,t,x,1);

                    interpolacion.push_back(vector<double>{t_j,polinomio-1});
                    t_j=t_j+(t[i+1]-t[i])/puntos_interpolacion;
                }

                
            }
            return interpolacion;
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

};
#endif