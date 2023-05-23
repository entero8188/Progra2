#include <iostream>
#include <cmath>
#include<fstream>

#include "spline.h"
#include"lagrange.h"
using namespace std;


int main(){

    lagrange lagrange_sin("datos.dat",1);
    spline spline_sin("datos.dat", 1);
    

    
    

    ofstream archivo_interpolacion;
    ofstream archivo_interpolacion2;

    

    archivo_interpolacion.open("archivo_interpolacion.dat");
    archivo_interpolacion2.open("archivo_interpolacion2.dat");

    

    for(uint i=0; i<spline_sin.get_spline().size(); i++){
        archivo_interpolacion<<spline_sin.get_spline()[i][0]<<" "<< spline_sin.get_spline()[i][1]<<endl;
    } 
    
    for(uint i=0; i<lagrange_sin.get_lagrange().size(); i++){
        archivo_interpolacion2<<lagrange_sin.get_lagrange()[i][0]<<" "<< lagrange_sin.get_lagrange()[i][1]<<endl;
    } 
    

    archivo_interpolacion.close();
    archivo_interpolacion2.close();





   

    
    return 0;

}
