#include <iostream>
#include <cmath>
#include<fstream>



using namespace std;

long double g(long double x){//sumatoria rara
    long double delta =0.5;
    long double sum_anterior =0;
    long double sum_siguiente =0;


    
    for(int i =2;;i++){
        long double I=i;
        
        sum_siguiente+=sum_anterior+(i-1)/pow(i, x+1);
        
        
        
        if(abs(sum_siguiente-sum_anterior)<delta){

            return sum_siguiente;

        }   

        sum_anterior=sum_siguiente;

    }

}


class integrador{
    public:
        long double x_i;
        long double x_f;
        int n;
        long double dx;
        vector<long double> lista_f;
        vector<long double> lista_f_1;
        vector<long double> x;
        
        integrador(long double x_i, long double x_f, int n){
            this->x_i=x_i;
            this->x_f=x_f;
            this->n=n;
            this->dx=(x_f-x_i)/n;

        }


        long double f_1(int i){
            
            long double x=this->x_i+i*this->dx;
            
            return -x*this->lista_f[i]+x*g(x);
        }

        long double f_2(int i){//segunda derivada
            long double x=this->x_i+i*this->dx;
            return this->lista_f_1[i]*((1/x)-x)-x*(x+1)*g(x+1);
        }



        void guardar_integracion(){
            string path= "./datos.dat";
            ofstream salida;
            salida.open(path);
            for(int i=0;i<this-> lista_f.size();i++ ){
            salida<<to_string(lista_f[i])<<" "<<to_string(lista_f_1[i])<<"\n";
            }
            salida.close();
        }





        void calcular(long double phi){
            
            this->lista_f.push_back(phi);
            

            long double phi_1=f_1(0);
            
            this->x.push_back(x_i+this->dx);

            
            this->lista_f_1.push_back(phi_1);
            
            this->lista_f.push_back(phi+phi_1*this->dx);
            
            this->lista_f_1.push_back(f_1(1));
            

            for(int i = 1; i<this->n; i++){
                long double step=2*this->lista_f[i]-lista_f[i-1]+this->f_2(i)*this->dx*this->dx;
                this->x.push_back(this->x_i+(i+1)*this->dx);
                this->lista_f.push_back(step);
                this->lista_f_1.push_back(this->f_1(step));

            }

        }






};





int main(){

    
    srand(time(0));
    

    integrador A=integrador(2,3,10);

    int a=A.lista_f.size()==A.lista_f_1.size();
    

    A.calcular(1.20205);
   
    A.guardar_integracion();



    return 0;
}
