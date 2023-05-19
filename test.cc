#include <iostream>
#include <cmath>
#include<fstream>

#include "complejos.h"
#include "fracciones.h"
#include "dual.h"
#include "matriz.h"
#include"spline.h"

using namespace std;


int main(){
    vector<vector<double> > m1;
    vector<vector<double> > m2;
    for(int i=0; i<5; i++){
        vector<double> fila;
        for(int j =0; j<7; j++){
            fila.push_back(j) ;  
        }
        m1.push_back(fila);
        m2.push_back(fila);
    }
    matriz<double> matriz1(m1);
    matriz<double> matriz2=2*matriz1;
    matriz1.print();
    matriz2.print();

    cout<<"filas= "<<matriz1.get_filas()<<"\nColumnas= "<<matriz1.get_columnas()<<endl;
    
    cout<<"matriz1[1][4]"<<endl;


    matriz<double> matriz_suma= matriz1+matriz2;
    cout<<"matriz1[1][4]"<<endl;

    matriz_suma.print();
    cout<<"estoy aca"<<endl;
    
    spline spline_sin("datos.dat", 1);
    cout<<"estoy aca 2"<<endl;

    spline spline_cos("datos.dat", 2);
    cout<<"estoy aca3"<<endl;

    ofstream archivo_interpolacion;
    cout<<"estoy aca4"<<endl;

    archivo_interpolacion.open("archivo_interpolacion.dat");
    cout<<"estoy aca5"<<endl;

    for(int i=0; i<spline_sin.get_spline().size(); i++){
        archivo_interpolacion<<spline_sin.get_spline()[i][0]<<" "<< spline_sin.get_spline()[i][1]<< " " << spline_cos.get_spline()[i][1]<<endl;
    } 
    cout<<"estoy aca6"<<endl;

    archivo_interpolacion.close();
    return 0;
}