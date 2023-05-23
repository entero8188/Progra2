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



            /* Para iniciarlizar un splain tenemos que darle el nombre del
            archivo(name_archivo) de donde va a sacar los datos para interpolar, asumimos
            que la primera columna del archivo corresponde al tiempo, pero le
            entregamos el número de columna de los datos que queremos interpolar
            (n_columna)
             */
        lagrange(string name_archivo, int n_columna=1){
            this->name_archivo=name_archivo;

            vector<string> lineas=lector(name_archivo);
            vector<vector<string> >datos_string=separador(lineas);

            vector<double> t;
            vector<double> x;

            for(uint i=0; i<datos_string.size();i++){
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

            vector<double> divisores;//le puse divisores porque inicialmente solo iba a devolver los divisores de cada V_i pero me di cuenta que se podian calcular tanto los divisores como numerador de una y me dio flojera cambiarle el nombre
            double resultado=0.;

            for(uint i =0; i<t.size(); i++){
                double producto=1;

                for(uint j=0; j<t.size();j++){
                    if(i==j){

                    }

                    else{
                        producto*=(x-t[j])/(t[i]-t[j]);
                    }

                }
                divisores.push_back(producto);

            }

            for(uint i=0;i<divisores.size();i++){
                resultado+=datos[i]*divisores[i];
            }
            return resultado;
        };




        








        vector<vector<double>> interpolacion(vector<vector<double>> datos){
            vector<double> t= datos[0];//le pasamos el tiempo
            vector<double> x= datos[1];//y los puntos f(t)

            int n=t.size()-1;//le pasamos el numero de intervalos

            
            double t_j=t[0];
            double polinomio;
            int puntos_interpolacion=10;

            vector<vector<double>> interpolacion;

            for(int i=0; i<=n-1;i++){
                
                for(int j=0; j<puntos_interpolacion;j++){


                    polinomio=calcular(t_j,t,x);

                    interpolacion.push_back(vector<double>{t_j,polinomio});
                    t_j=t_j+(t[i+1]-t[i])/puntos_interpolacion;
                }

                
            }
            return interpolacion;
        };








/* 
La siguiente funcion se encarga de tomar un archivo ascii y pasarlo a 
una unica cadena de string */
        vector<string> lector(string texto){
                vector<string> lineas;

                string linea;

                ifstream myfile(texto);

                while(getline(myfile, linea)){
                    lineas.push_back(linea);
                }
                
                return lineas;
                
            }






/* 
Esta funcion pasa la cadena que genera la funcion anterior a un arreglo
matricial donde la i-esima fila de la matriz corresponde a la i-esima
fila del archivo que lee el programa y lo mismo para las columnas */


            vector<vector<string>> separador(vector<string> lineas){
                vector<vector<string>> palabras;

                for(uint i=0; i<lineas.size(); i++){
                    vector<string> vectori;

                    string palabra= " ";

                    for(uint j=0; j<=lineas[i].length();j++){
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