#include "../templates/dual.h"  //<>
#include <cmath>
#include "../templates/complejos.h"
#include "../templates/fracciones.h"


int main()
{
  complejo<double> c1(1000,1);
  cout<<c1(0)<<endl;
  cout<<1/c1<<endl;
  dual<double> a(1,2);
  
  dual<double> b=2*a;
  cout<<a<<"\t"<<b<<endl;
  cout<<"hola"<<a<<endl;
  cout<<1/tan(a)<<endl;
  cout<<cos(a)/sin(a)<<endl;





  fraccion<int>f1(2,5);
  cout<<"fracción 1:\t"<<f1<<"\nnumerador:\t"<<f1.get_numerador()<<"\ndenominador:\t"<<f1.get_denominador()<<endl;

  fraccion<int>f2(69,21);
  cout<<"\n\n\nfracción 2:\t"<<f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  f2.simplificar();
  cout<<"fracción 2 prima:\t"<<f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<f2*2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<f2/2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<f2-2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<f2+2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  

  cout<<"\n\n\n"<<endl;
  cout<<"fracción 2 prima:\t"<<f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<2*f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<2/f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<2-f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  cout<<"fracción 2 prima:\t"<<2+f2<<"\nnumerador:\t"<<f2.get_numerador()<<"\ndenominador:\t"<<f2.get_denominador()<<endl;
  
  //cout<<1+f1<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}


