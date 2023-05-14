#include <iostream>
#include <cmath>
#include "complejos.h"
#include "fracciones.h"
#include "dual.h"

using namespace std;


int main(){
    dual<double> d(1,1,0,0);
    dual<double> d2(7,1,0,0);
    // cout<<d<<endl;
    // cout<<d2<<endl;
    // cout<<d+d2<<endl;
    // cout<<d*d2<<endl;
    // cout<<d/d2<<endl;
    // dual<double> x^4(dual<double> x){
    //     return dual
    // }
    dual<double> x(2,1,0,0);
    cout<<x*x*x*x<<endl;
    dual<double> y(M_PI,1,0,0);
    cout<<sin(y)<<endl;
    //no alcance a evaluar la funcion, me complica ver como lo escribo para su cuarta derivada
    // complejo<int> num(-3,-1);
    // complejo<int> den(-5,2);
    // dual<complejo<int>> frac(num,den);
    // complejo<int> uno1(1,0);
    // complejo<int> uno(1,0);
    // dual<complejo<int>> uno2(uno,uno1);

    
    // fraccion<dual<complejo<int> > > f(frac,uno2, uno2,uno2);





    return 0;
}