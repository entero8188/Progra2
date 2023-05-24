#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;


double derivada(double t, double x, double v){
    double F= 1.;
    double w= .75;
    double m= 10.;
    double k= .5;
    double b= 1.75;

    return (F*sin(w*t)/m)-(v*b/m)-(x*k);
}

int main(){
    //paso n+1
    double x=0;
    double x_punto=0;
    double x_2punto=0;

    //paso n
    double x_n=0;
    double x_punto_n=0;
    double x_2punto_n=0;



    double dt=0.01;

    double t_f=100;


    //en este problema la variable independiente es t
    double t=0;



    ////////////////EULER////////////////////////
    ofstream pefrl;
    pefrl.open("pefrl.dat");

    double e = +0.1786178958448091;
    double lambda= -0.2123418310626054;
    double xhi= -0.06626458266981849;

    double m=1;

    while(t<t_f){

        pefrl<<t<<" "<<x_2punto<<" "<<x_punto<<" "<<x<<endl;

        double y_1= x_punto+e*derivada(t,x,x_punto)*dt;
        double dy_1=derivada(t,x,x_punto)+((1.-2.*lambda)/(2.*m))*dt*derivada(t,x,y_1);


        double y_2= y_1+xhi*dy_1*dt;
        double dy_2=dy_1+(lambda/m)*dt*derivada(t,x,y_2);

        double y_3=y_2+(1.-2.*(xhi+e))*dy_2*dt;
        double dy_3=dy_2+(lambda/m)*dt*derivada(t,x,y_3);

        double y_4=y_3+xhi*dy_3*dt;


        x_2punto=dy_3+((1.-2.*lambda)/(2.*m))*dt*derivada(t,x,y_4);
        x_punto=y_4+e*x_2punto*dt;
        x=x+x_punto*dt;
        t=t+dt;

    }

    pefrl.close();



    return 0;
}