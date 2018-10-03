#pragma once
#include <string>
#include "Pila.h"

class Calculadora {

private:
	std::string expresionInfija;
	std::string expresionPostfija;
	Pila<long long> pila;

public:
	Calculadora();
	~Calculadora();
	void normalizarExpresion();
	void validarExpresion();
	int precedencia(char);
	void crearNotacionPostfija();
	long long evaluarExpresion(char,long long,long long);
	long long realizarCalculo();
	std::string getExpresionInfija();
	std::string getExpresionPostfija();
	void agregarCaracter(char car);
	void borrarCaracter();
	void reiniciar();
};