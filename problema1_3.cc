#include "../templates/dual.h"  //<>
#include <cmath>
#include "../templates/complejos.h"
#include "../templates/fracciones.h"


int main(){
    complejo<double>num1(1,-2);
    complejo<double>den1(1,1);

    fraccion<complejo<double>> Z1_f(num1,den1);
    complejo<double> Z1_z=num1/den1;

    fraccion<complejo<double>> Z2_f(complejo<double>(4,3),complejo<double>(1,0));
    complejo<double> Z2_z=complejo<double>(4,3);

    fraccion<complejo<double>> I(5*exp(complejo<double>(0,4)),complejo<double>(1,0));
    

    fraccion<complejo<double>>V1_f=Z1_f*I;
    complejo<double> V1_z=V1_f.get_numerador()/V1_f.get_denominador();

    fraccion<complejo<double>>V2_f=Z2_f*I;
    complejo<double> V2_z=V2_f.get_numerador()/V2_f.get_denominador();
   





















    cout<<"Primer voltaje:\t"<<V1_f<<endl;
    cout<<"Primer voltaje:\t"<<V1_z<<endl;
    cout<<"Su módulo es :\t"<<V1_z.modulo()<<"\n\n"<<endl;
    cout<<"Segundo voltaje:\t"<<V2_f<<endl;
    cout<<"Segundo voltaje:\t"<<V2_z<<endl;
    cout<<"Su módulo es :\t"<<V2_z.modulo()<<"\n\n"<<endl;
    


    
    
    





    return 0;
}