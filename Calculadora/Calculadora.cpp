#include "Calculadora.h"
#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

Calculadora::Calculadora() { }

Calculadora::~Calculadora() { }

bool Calculadora::validaParentesis(std::string expresion) {

	std::stack<char> pila;
	bool esValida = true;
	char c, aux;

	for (std::string::size_type i = 0; i < expresion.size(); ++i) {

		c = expresion[i];

		if (c == '(' || c == '[' || c == '{')
			pila.push(c);
		else if (c == ')' || c == ']' || c == '}')
			if (pila.empty())
				esValida = false;
			else {
				aux = pila.top();
				pila.pop();
				if ((c == '(' && aux != ')') || (c == '[' && aux != ']') || (c == '{' && aux != '}'))
					esValida = false;
			}
	}

	if (!pila.empty())
		return false;

	return esValida;

}

std::istream& Calculadora::capturarExpresion(std::istream& entrada, std::string& exp){

	std::cout << "Digite una expresion interfija y presione <ENTER>: " << std::endl;

	if (entrada) {
		exp.clear();
		std::getline(entrada, exp);

		entrada.clear();
	}
	return entrada;

}

std::string Calculadora::convertirNotacion(const std::string& exp){

	char c;
	int pos = 0;
	std::string temp;
	std::stack<char> pila;

	for (std::string::size_type i = 0; i < exp.size(); ++i) {
		if (isdigit(exp[i]))
			temp.append(1, exp[i]);
		else if (exp[i] == '(')
			pila.push(exp[i]);
		else if (exp[i] == ')')
			while ((c = pila.top()) != '(') {
				pila.pop();
				temp.append(1, c);
			}
		else {
			while (!pila.empty() && precedencia(pila.top()) >= precedencia(exp[i])) {
				temp.append(1, pila.top());
				pila.pop();
			}
			pila.push(exp[i]);
		}
	}
	while (!pila.empty()) {
		temp.append(1, pila.top());
		pila.pop();
	}
	return temp;

}

void Calculadora::removerEspacios(std::string& exp){

	for (std::string::size_type i = 0; i < exp.size(); ++i)
		if (isspace(exp[i])) {
			exp.erase(i, 1);
			--i;
		}

}

int Calculadora::precedencia(char c){

	if (c == '(')
		return 1;
	if (c == '+' || c == '-')
		return 2;
	if (c == '*' || c == '/')
		return 3;
	return -1;

}