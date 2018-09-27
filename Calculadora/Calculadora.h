#pragma once
#include <sstream>
#include <string>
#include "Pila.h"

class Calculadora {

private:
	std::string expresionInfija;
	Pila<int> pila;

public:
	Calculadora();
	~Calculadora();
	bool validarExpresion();
	int precedencia(char);
	std::string convertirNotacion();
	int evaluarExpresion(char,int,int);
	int realizarCalculo();
};

