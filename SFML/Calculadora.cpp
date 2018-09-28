#include "Calculadora.h"
#include <iostream>
#include <sstream>

Calculadora::Calculadora() {}

Calculadora::Calculadora(std::string inf) {

	this->expresionInfija = inf;

	normalizarExpresion();
}

Calculadora::~Calculadora() {}

// Para normalizar la expresion (los pares de signos '+' y '-')
void Calculadora::normalizarExpresion() {

	for (int i = 1; i < expresionInfija.size(); i++)
		if (expresionInfija[i] == '+') {
			if (expresionInfija[i - 1] == '-')
				expresionInfija.pop_back();
		}
		else if (expresionInfija[i] == '-')
			if (expresionInfija[i - 1] == '-') {
				expresionInfija.erase(i - 1, 2);

				expresionInfija.push_back('+');
			}
			else if (expresionInfija[i - 1] == '+')
				expresionInfija.erase(i - 1, 1);
}

void Calculadora::validarExpresion() {

	normalizarExpresion();

	Pila<char> pilaDeParentesis;
	int indicadorDeElementos = 0; // Si es mayor o igual a 1 la expresion es valida

	for (int i = 0; i < expresionInfija.size(); i++) {
		if (expresionInfija[i] == '(') {
			if (expresionInfija[i + 1] == '-' || expresionInfija[i + 1] == '+')
				i++;

			pilaDeParentesis.push('(');
		}
		else if (expresionInfija[i] == ')') {
			if (pilaDeParentesis.estaVacia())
				throw std::string("Los parentesis no estan anidados correctamente");

			pilaDeParentesis.pop();
		}
		else if (isdigit(expresionInfija[i])) {
			std::string numero;
			int contadorDeDigitos = 0;

			do
				contadorDeDigitos++;
			while (isdigit(expresionInfija[i + contadorDeDigitos]));

			indicadorDeElementos++;

			i += contadorDeDigitos - 1;
		}
		else
			indicadorDeElementos--;
	}

	if (!pilaDeParentesis.estaVacia())
		throw std::string("Los parentesis no estan anidados correctamente");

	if (indicadorDeElementos < 1)
		throw std::string("La expresion no es valida");
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

std::string Calculadora::crearNotacionPostfija() {

	Pila<std::string> pilaDeOperadores;
	std::stringstream expresionPostfija;

	for (int i = 0; i < expresionInfija.size(); i++)
		if (isdigit(expresionInfija[i])) {
			int contadorDeDigitos = 0;

			do
				expresionPostfija << expresionInfija[i + contadorDeDigitos++];
			while (isdigit(expresionInfija[i + contadorDeDigitos]));

			if (!pilaDeOperadores.estaVacia() && pilaDeOperadores.peek() == "(-") {
				expresionPostfija << ")";

				pilaDeOperadores.pop();
				contadorDeDigitos++;
			}

			i += contadorDeDigitos - 1;

			if (pilaDeOperadores.estaVacia() || precedencia(expresionInfija[i + 1]) > precedencia(pilaDeOperadores.peek()[0]))
				expresionPostfija << " ";
		}
		else if (expresionInfija[i] == '(') {
			if (isdigit(expresionInfija[i + 1]))
				pilaDeOperadores.push("(");
			else if (expresionInfija[++i] == '-') {
				expresionPostfija << "(-";
				pilaDeOperadores.push("(-");
			}
		}
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

	validarExpresion();

	int primerOperando, segundoOperando;
	std::string expresionPostfija = crearNotacionPostfija();
	int multiplicadorDeNumeroNegativo;

	for (int i = 0; i < expresionPostfija.size(); i++)
		if (isdigit(expresionPostfija[i]) || expresionPostfija[i] == '(') {
			std::string numero;

			if (expresionPostfija[i] == '(') {
				multiplicadorDeNumeroNegativo = -1;
				i += 2; // Para saltarnos al '(-'
			}
			else
				multiplicadorDeNumeroNegativo = 1;

			do
				numero.push_back(expresionPostfija[i++]);
			while (isdigit(expresionPostfija[i]));

			pila.push(stoi(numero) * multiplicadorDeNumeroNegativo);

			if (multiplicadorDeNumeroNegativo < 0)
				i++;

			if (isspace(expresionPostfija[i]))
				continue;

			i--;
		}
		else {
			segundoOperando = pila.pop();
			primerOperando = pila.pop();

			pila.push(evaluarExpresion(expresionPostfija[i], primerOperando, segundoOperando));
		}

	return pila.pop();
}

std::string Calculadora::getExpresionInfija() {

	return expresionInfija;
}

void Calculadora::setExpresion(std::string expresionInfija) {

	this->expresionInfija = expresionInfija;

}

void Calculadora::agregarCaracter(char car) {

	if (expresionInfija.size() < 24)

		expresionInfija.push_back(car);

}

void Calculadora::borrarCaracter() {

	if(expresionInfija.size() > 0)

		expresionInfija.pop_back();

}

void Calculadora::borrarExpresion() {

	expresionInfija.clear();
}