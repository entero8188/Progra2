#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

int donde_estoy(double x, double y, double z){
    /* Lo que hacemos es, dado un volumen que podemos parametrizar, onda una esfera, cajita, etc.
    devolver un 1 si se encuentra dentro del volumen o bien un cero si no se encuentra dentro del volumen
     */
    if (x*x+y*y<=1.){
        return 1;
    }

    else{
        return 0;
    }

}
/* 
La idea del metodo monte carlo es lanzar demasiados intentos y ver que estos 
caigan dentro del area/volumen que queremos. Supongamos que conocemos una región
cuya área/volumen es S, S es bien conocido, BIEN CONOCIDO, sabemos exactamente su 
valor. Si A es el área que queremos aproximar, y dicha área esta contenida dentro de
S, si lanzamos puntos aleatorios dentro de S, la cantidad de puntos que caen dentro 
de la superficie A, osea, la probabilidad que el punto cae dentro de A(p(caer dentro de A)),
es proporcional a la relación entre el área A y el área S(A/S).
Luego A es más o menos
A=p(caer dentro de A)*S

pero la probabilidad de caer dentro de A la podemos obtener lanzando un número ridiculo
de puntos, sean n los puntos totales que lanzamos y dentro la cantidad de puntos que 
efectivamente cayeron dentro, podemos aproximar A como

A=S*(dentro/n)


 */


int main(){
    int n_evaluaciones= 1000000;//numero de veces que vamos ha ver si esta o no dentro
    int dentro=1;//contador de cuantos puntitos caen dentro de nuestro volumen

    srand(time(0));

    for(int i =0; i<=n_evaluaciones; i++){
        double x=-1.+2. *rand()/RAND_MAX;
        double y=-1.+2. *rand()/RAND_MAX;
        double z=-1.+2. *rand()/RAND_MAX;

        dentro+=donde_estoy(x,y,z);

    }
    cout<<dentro<<endl;
    double area=(double(dentro)/double(n_evaluaciones))*2.*2.;//debemos pasar las cantidades a doubles o nos da cero ya q es una division entera y no aguanta los decimales
    cout<<"el área de la circunferencia de radio 1 es: "<<area<<endl;


    return 0;
}