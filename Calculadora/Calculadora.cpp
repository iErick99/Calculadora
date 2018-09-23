#include "Calculadora.h"
#include <stack>

Calculadora::Calculadora() {
}


Calculadora::~Calculadora() {
}

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