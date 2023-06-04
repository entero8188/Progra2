#include <iostream>
#include "Rls.h"
using namespace std;

int main(){
	cout << "Con error asociado: " << endl;
	// creamos un objeto en donde consideramos en los calculos el error.
	// el dos indica la columna donde esta el error en los datos
	Rls datos_error("datos_regresion.dat", 1, 2);
	datos_error.regresion();
	cout << "Error pendiente: " << datos_error.error(2) << endl;
	cout << "Error intercepto: " << datos_error.error(1) << endl << endl;
	cout << "Si a una particula se le suministra 14[Gev], su energia será: ";
	cout << datos_error.a(2)*14+datos_error.a(1) << endl;
	cout << "# --------------------------------------------- #" << endl;



	cout << "Sin error asociado: " << endl;
	// consideramos el error asociado sigma_i constante = 1 (funciona bien, lo comprobe 
	// con gnuplot), aca no es necesario especificar la columna de error
	Rls datos("datos_regresion.dat", 1);
	datos.regresion();
	cout << "Error pendiente: " << datos.error(2) << endl;
	cout << "Error intercepto: " << datos.error(1) << endl << endl;
	cout << "Si a una particula se le suministra 14[Gev], su energia será: ";
	cout << datos.a(2)*14+datos.a(1) << endl;
	cout << "# --------------------------------------------- #" << endl;


	// La que se supone que responde la 2 de la tarea (incluido el puntaje extra), es 
	// la de datos_error, la segunda se puede usar solo cuando no sabemos el error
	// asociado (muy util pa meto2)



	return 0;
}



