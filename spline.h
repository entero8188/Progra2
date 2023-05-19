#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;

class spline{
    private:
        string name_archivo;
        vector<vector<double> > datos;
        vector<vector<double> > datos_interpolados;

    public:
        spline(){};

/*
va a ser un pequeño resumen de como funciona esta clase.
Los splains al final los usamos cuando tenemos una serie de puntos, estos puntos los podemos obtener de la medición en algún experimento, 
puede que la separación entre cada medición sea grande y para eso esta la interpolación que es como decir, "ya, este punte es el que debería venir 
entremedio de estos dos puntos que medí". Un metodo de interpolación y el q importa para la prueba son los splain








*/
    

    //constructor genérico//
        spline(string name_archivo, int n_columna=1){
            //el name_archivo es el archivo.dat donde estan los puntos que medimos experimentalmente y a los cuales queremos realizarles una interpolación
            this->name_archivo=name_archivo;
            
            /*La función lector(definida como la penultima) se encarga de pasar el archivo.dat con los datos a un vector en c++ para que el programa pueda usar los datos en si.
            la  funcion pasa todo el .dat, ya sean numeros, espacios, tabulaciones y cambios de linea a un único VECTOR de largo arbitrario, osea, escribe todo lo del .dat en una sola linea, la otra funcion se encarga de dejarlo bonito*/
            vector<string> lineas=lector(name_archivo);
            
            /*
            La función separador toma el super vector que crea la función lector y va armando los numeros que estaban anotados en el .dat, en la implementación del separador voy a explicar mejor como funciona
            lo importante a cachar es que, la columna 0 del .dat es el tiempo(variable independiente) del experimento del que tomamos los datos y n_columna es la medición que tomamos para un tiempo dado*/
            vector<vector<string> >datos_string=separador(lineas);

            vector<double> t;
            vector<double> x;

            for(int i=0; i<datos_string.size();i++){
                t.push_back(stod(datos_string[i][0]));//aca le digo a c++ que tome la primera columna como si fuera el tiempo
                x.push_back(stod(datos_string[i][n_columna]));//aca le digo q la n_columna son los datos que quiero interpolar

            }

            this->datos.push_back(t);
            this->datos.push_back(x);

            this->datos_interpolados=interpolacion(datos);

        };









        vector<vector<double>> get_spline(){
            return datos_interpolados;
        };






        vector<vector<double> > constantes(vector<double> t/*el vector t son los intervalos de tiempo que tomamos*/,
                                           vector<double> x/*x son las mediciones que tomamos*/ ,
                                           int n){
            vector<double> a(n+1);
            for(int i=0; i<=n;i++){
                a[i]=x[i];//defino los y_i que salen en  el pdf interpolacion.pdf diapo 16
            }

            vector<double> b(n,0.);
            vector<double> c(n,0.);
            vector<double> d(n,0.);
            

            vector<double> h(n);

            for(int i=0;i<=n-1; i++){
                h[i]=t[i+1]-t[i];//definimos los intervalos de tiempo en los que realizamos mediciones
            }
            
            vector<double> r(n);//aca definimos la mitad del r que aparece en el pdf

            
            //sinceramente no se como funciona esta parte pq usa una forma del algoritmo q sale en wikipedia y el profe no explico, pero es analogo a lo del pdf
            for(int i=1; i<=n-1; i++ ){
                r[i]=3.*(a[i+1]-a[i])/(h[i])-3.*(a[i]-a[i-1])/(h[i-1]);

            }

            vector<double> l(n,0.);
            vector<double> mu(n,0.);
            vector<double> k(n,0.);

            l[0]=1.;
            mu[0]=0.;
            k[0]=0.;

            for(int i=1; i<n; i++){
                l[i]=2.*(t[i+1]-t[i-1])-h[i-1]*mu[i-1];
                mu[i]=h[i]/l[i];
                k[i]=(r[i]-h[i-1]*k[i-1])/l[i];
            }

            l[n]=1.;
            k[n]=0.;
            c[n]=0.;




            for(int i=n-1 ; i>=0 ; i--){
                c[i]=k[i]-mu[i]*c[i+1];
                b[i]=(a[i+1]-a[i])/h[i]-h[i]*(c[i+1]+2.*c[i])/3.;
                d[i]=(c[i+1]-c[i])/(3.*h[i]);
            }
            vector<vector<double> > constantes;
            /*las constantes a,b,c y d son los coeficientes que acompañan a cada termino de x, recordemos que 
            los splains son funciones cúbicas, asi q las constantes son las del polinomio
            ax³+bx²+cx+d
            y el i-esimo valor a,b,c y d son las constantes del polinomio S(x) de grado 3 que pasa por el i-esimo valor 
            de la interpolacion osea x_i*/
            constantes.push_back(a);
            constantes.push_back(b);
            constantes.push_back(c);
            constantes.push_back(d);
            
            return constantes;

        }





        vector<vector<double> > interpolacion(vector<vector<double>> datos){
            vector<double> t=datos[0];
            vector<double> x=datos[1];

            int n=t.size()-1;

            vector<vector<double>> constant=constantes(t,x,n);//creamos el vector con las constantes para cada x del splain
            vector<double> d= constant[3];
            vector<double> c= constant[2];
            vector<double> b= constant[1];
            vector<double> a= constant[0];

            double t_j=0.;
            double polinomio;
            double puntos_interpolacion=10.;

            vector<vector<double>> interpolacion;

            for(int i=0; i<n; i++){

                for(int j=0; j<puntos_interpolacion;j++){
                    polinomio=d[i]*pow(t_j-t[i],3) + c[i]*pow(t_j-t[i],2) + b[i]*(t_j-t[i])+a[i];


                    interpolacion.push_back(vector<double>{t_j,polinomio});

                    t_j=t_j+(t[i+1]-t[i])/puntos_interpolacion;
                }

            }


            return interpolacion;

        }







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
