#include<vector>
#include<cmath>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//defino una funcion compleja y su derivada(la derivada la asumimos conocida xq no c como se divide en C xD)
vector<double> f(vector<double> x){
    return vector<double>{x[0]*x[0]-x[1]*x[1],2*x[0]*x[1]};

}

vector<double> f_der(vector<double> v){
    return vector<double>{2*v[0],2*v[1]};
}


//es una division de complejos, por lo que hay q racionalizar el divisor
vector<double> g(vector<double> v){
    vector<double> arriba=f(v);
    vector<double> abajo=f_der(v);
    double nuevo_arriba_R=arriba[0]*abajo[0]+arriba[1]*abajo[1];
    double nuevo_arriba_c=arriba[1]*abajo[0]-arriba[0]*abajo[1];
    double nuevo_abajo=abajo[0]*abajo[0]+abajo[1]*abajo[1];
    
    return vector<double> {nuevo_arriba_R/nuevo_abajo, nuevo_arriba_c/nuevo_abajo};

}


//funcion que va a evaluar si converge eta vaina
int convergencia(int N, vector<double> v){
    double delta=0.0000001;
    vector<double> iteracion =v;
    for(int i =0; i <N; i++){
        vector<double> temp=g(iteracion);
        vector<double> nueva_iteracion=iteracion;

        nueva_iteracion[0]-=temp[0];
        nueva_iteracion[1]-=temp[1];


//la parte de plotear creo q sale mas facil dividir en 2 archivos, uno q guardo los puntos q convergen y otro los q no y plotearlos 
        if(sqrt((nueva_iteracion[0]-iteracion[0])*(nueva_iteracion[0]-iteracion[0])+(nueva_iteracion[1]-iteracion[1])*(nueva_iteracion[1]-iteracion[1])*(nueva_iteracion[1]-iteracion[1]))<=delta){
            return 1;
            
        }
        
        iteracion[0]=nueva_iteracion[0];
        iteracion[1]=nueva_iteracion[1];

    }



    return 0;
}









//funvion para callcular los elementos de la primera columna
double columna(double x){
    double resultado=0;

    
}







int main (){

    //aca deberia ir como iniciar la cueation demas de guardar los datos de si converge o no el fractal q 
    //le damos

    return 0;
}





