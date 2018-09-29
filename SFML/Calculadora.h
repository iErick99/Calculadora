#pragma once
#include <string>
#include "Pila.h"

class Calculadora {

private:
	std::string expresionInfija;
	std::string expresionPostfija;
	Pila<int> pila;

public:
	Calculadora();
	~Calculadora();
	void normalizarExpresion();
	void validarExpresion();
	int precedencia(char);
	void crearNotacionPostfija();
	int evaluarExpresion(char,int,int);
	int realizarCalculo();
	std::string getExpresionInfija();
	std::string getExpresionPostfija();
	void agregarCaracter(char car);
	void borrarCaracter();
	void reiniciar();
};