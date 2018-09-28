#pragma once
#include <string>
#include "Pila.h"

class Calculadora {

private:
	std::string expresionInfija;
	Pila<int> pila;


public:
	Calculadora();
	Calculadora(std::string);
	~Calculadora();
	void normalizarExpresion();
	void validarExpresion();
	int precedencia(char);
	std::string crearNotacionPostfija();
	int evaluarExpresion(char, int, int);
	int realizarCalculo();
	std::string getExpresionInfija();
	void setExpresion(std::string);
	void agregarCaracter(char);
	void borrarCaracter();
	void borrarExpresion();
};