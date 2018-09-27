#include "Calculadora.h"
#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

Calculadora::Calculadora() {}

Calculadora::~Calculadora() {}

bool Calculadora::validarExpresion() {

	std::stack<char> pila;

	for (char cha : expresionInfija) {
		if (cha == '(')
			pila.push(cha);
		else if (cha == ')') {
			if (pila.empty())
				return 0;

			pila.pop();
		}
	}

	return pila.empty();
}

int Calculadora::precedencia(char ope) {

	if (ope == '^')
		return 3;
	else if (ope == '*' || ope == '/')
		return 2;
	else if (ope == '+' || ope == '-')
		return 1;

	return 0;
}

std::string Calculadora::convertirNotacion() {

	Pila<std::string> pilaDeOperadores;
	std::stringstream expresionPostfija;

	for (int i = 0; i < expresionInfija.size(); i++)
		if (isdigit(expresionInfija[i])) {
			int contadorDeDigitos = 0;

			do
				expresionPostfija << expresionInfija[i + contadorDeDigitos++];
			while (isdigit(expresionInfija[i + contadorDeDigitos]));

			i += contadorDeDigitos - 1;

			if (pilaDeOperadores.estaVacia() || precedencia(expresionInfija[i + 1]) > precedencia(pilaDeOperadores.peek()[0]))
				expresionPostfija << " ";
		}
		else if (expresionInfija[i] == '(')
			pilaDeOperadores.push("(");
		else if (expresionInfija[i] == ')') {
			while (pilaDeOperadores.peek() != "(")
				expresionPostfija << pilaDeOperadores.pop();

			pilaDeOperadores.pop();
		}
		else {
			while (!pilaDeOperadores.estaVacia() && precedencia(expresionInfija[i]) <= precedencia(pilaDeOperadores.peek()[0]))
				expresionPostfija << pilaDeOperadores.pop();

			pilaDeOperadores.push(std::string(1, expresionInfija[i]));
		}

	while (!pilaDeOperadores.estaVacia())
		expresionPostfija << pilaDeOperadores.pop();

	return expresionPostfija.str();
}

int Calculadora::evaluarExpresion(char ope, int pri, int seg) {

	switch (ope) {

	case '+': return pri + seg;
	case '-': return pri - seg;
	case '*': return pri * seg;
	case '/': return pri / seg;
	
	default: return static_cast<int>(pow(pri, seg));
	}
}

int Calculadora::realizarCalculo() {

	//Método de validar

	int primerOperando, segundoOperando;
	std::string expresionPosfija = convertirNotacion();

	for (int i = 0; i < expresionPosfija.size(); i++)
		if (isdigit(expresionPosfija[i])) {
			std::string numero;

			do
				numero.push_back(expresionPosfija[i++]);
			while (isdigit(expresionPosfija[i]));

			if (!isspace(expresionPosfija[i]))
				i--;

			pila.push(stoi(numero));
		}
		else {
			segundoOperando = pila.pop();
			primerOperando = pila.pop();

			pila.push(evaluarExpresion(expresionPosfija[i], primerOperando, segundoOperando));
		}

	return pila.peek();
}

void Calculadora::setExpresion(std::string expresionInfija) {

	this->expresionInfija = expresionInfija;

}

std::string Calculadora::getExpresion() {

	return expresionInfija;

}

void Calculadora::agregarCaracter(char car) {

	expresionInfija.push_back(car);

}

void Calculadora::borrarCaracter() {

	expresionInfija.pop_back();

}

void Calculadora::borrarExpresion() {

	expresionInfija.clear();
}

