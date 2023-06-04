#include <iostream>
#include "Rls.h"
using namespace std;

int main(){
	cout << "Con error asociado: " << endl;
	// creamos un objeto en donde consideramos en los calculos el error.
	// el dos indica la columna donde esta el error en los datos
	Rls datos_error("datos_regresion.dat", 1, 2);
	datos_error.regresion();

	cout << "Sin error asociado: " << endl;
	// consideramos el error asociado sigma_i constante = 1 (funciona bien, lo comprobe 
	// con gnuplot), aca no es necesario especificar la columna de error
	Rls datos("datos_regresion.dat", 1);
	datos.regresion();



	return 0;
}


