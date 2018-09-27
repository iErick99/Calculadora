#include <iostream>
#include <sstream>
#include "Calculadora.h"
#include "Pila.h"

int main() {

	Calculadora cal;

	std::string expInf = "((20^2)/2)*3^2";

	std::cout << "Expresion infija: " << expInf << std::endl;
	std::cout << "Expresion posfija: " << cal.convertirNotacion(expInf) << std::endl;
	std::cout << "Resultado con calcu: " << cal.realizarCalculo() << std::endl;

	system("pause");
	return 0;
}