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




        spline(string name_archivo, int n_columna=1){
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









        vector<vector<double>> get_spline(){
            return datos_interpolados;
        };






        vector<vector<double> > constantes(vector<double> t, vector<double> x ,int n){
            vector<double> a(n+1);
            for(int i=0; i<=n;i++){
                a[i]=x[i];
            }

            vector<double> b(n,0.);
            vector<double> c(n,0.);
            vector<double> d(n,0.);
            

            vector<double> h(n);

            for(int i=0;i<=n-1; i++){
                h[i]=t[i+1]-t[i];
            }
            
            vector<double> r(n);

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

            vector<vector<double>> constant=constantes(t,x,n);
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