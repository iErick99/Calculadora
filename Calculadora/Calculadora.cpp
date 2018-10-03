#include "Calculadora.h"
#include <iostream>
#include <sstream>

// Constructor de la calculadora
Calculadora::Calculadora() {

	pila.push(0);
}

// Para liberar el valor '0' del tope de la pila
Calculadora::~Calculadora() { pila.pop(); }

// Para normalizar ciertas irregularidades en la expresion
void Calculadora::normalizarExpresion() {

	short int ultimoIndice = expresionInfija.size() - 1;

	if (expresionInfija.size() == 1) { // Para expresiones con exactamente 1 caracter

		switch (expresionInfija[ultimoIndice]) {

		case '-':
			expresionInfija.push_back('(');
			break;

		case '+': case '*': case '/': case '^': case ')':
			expresionInfija.pop_back();
			break;

		default: // Si es numero o alguno de ambos parentesis
			break;
		}
	}
	else if (expresionInfija.size() > 1) { // Para expresiones con mas de 1 caracter

		switch (expresionInfija[ultimoIndice]) {

		case '+':
			if (!isdigit(expresionInfija[ultimoIndice - 1]) && expresionInfija[ultimoIndice - 1] != ')')
				expresionInfija.pop_back();
			break;

		case '-':
			if (!isdigit(expresionInfija[ultimoIndice - 1]) && expresionInfija[ultimoIndice - 1] != ')')
				expresionInfija.push_back('(');
			break;

		case '*': case '/': case '^':
			if (!isdigit(expresionInfija[ultimoIndice - 1]) && expresionInfija[ultimoIndice - 1] != ')')
				expresionInfija.pop_back();
			break;

		case '(':
			if (expresionInfija[ultimoIndice - 1] == ')' || isdigit(expresionInfija[ultimoIndice - 1]))
				expresionInfija.insert(ultimoIndice, "*");
			break;

		case ')':

			if (expresionInfija[ultimoIndice - 1] == '(') {
				expresionInfija.erase(ultimoIndice - 1, 2);
				if (expresionInfija[ultimoIndice - 2] == '-') // En caso de haber un '-' antes del parentesis tambien se eliminara
					expresionInfija.pop_back();
			}
			break;

		default: // Si es numero
			if (expresionInfija[ultimoIndice - 1] == ')')
				expresionInfija.insert(ultimoIndice, "*");
			break;
		}
	}
}

// Se evalua si la expresion es valida para realizar un calculo
void Calculadora::validarExpresion() {

	Pila<char> pilaDeParentesis;
	int indicadorDeElementos = 0; // Si es mayor o igual a 1, la expresion es valida

	for (int i = 0; i < expresionInfija.size(); i++) {

		switch (expresionInfija[i]) {

		case '(':
			pilaDeParentesis.push('(');
			break;

		case ')':
			if (pilaDeParentesis.estaVacia())
				throw std::string("Los parentesis no estan anidados correctamente");

			pilaDeParentesis.pop();
			break;

		case '-':
			if (i == 0 || (!isdigit(expresionInfija[i - 1]) && expresionInfija[i - 1] != ')'))
				continue;

		case '+': case '*': case '/': case '^':
			indicadorDeElementos--;
			break;

		default: // Si es numero
			std::string numero;
			int contadorDeDigitos = 0;

			do
				contadorDeDigitos++;
			while (isdigit(expresionInfija[i + contadorDeDigitos]));

			indicadorDeElementos++;

			i += contadorDeDigitos - 1;
			break;
		}
	}

	if (!pilaDeParentesis.estaVacia())
		throw std::string("Parentesis mal anidados");

	if (indicadorDeElementos < 1)
		throw std::string("Expresion invalida");
}

// Retorna el nivel de prioridad de cada operador
int Calculadora::precedencia(char ope) {

	if (ope == '^')
		return 3;
	else if (ope == '*' || ope == '/')
		return 2;
	else if (ope == '+' || ope == '-')
		return 1;

	return 0;
}

// Se crea la notacion postfija, despues de haberse normalizado y validado
void Calculadora::crearNotacionPostfija() {

	Pila<std::string> pilaDeOperadores;
	std::stringstream expresionPostFijaTemporal;

	for (int i = 0; i < expresionInfija.size(); i++)

		switch (expresionInfija[i]) {

		case '(':
			pilaDeOperadores.push("(");
			break;

		case ')':
			while (pilaDeOperadores.peek() != "(")
				expresionPostFijaTemporal << pilaDeOperadores.pop();

			pilaDeOperadores.pop();

			if (!pilaDeOperadores.estaVacia() && pilaDeOperadores.peek() == "-(") { //Se chequea si el numero/expresion evaluado tiene signo negativo
				expresionPostFijaTemporal << ")";
				pilaDeOperadores.pop();
			}

			if (pilaDeOperadores.estaVacia() || precedencia(expresionInfija[i + 1]) > precedencia(pilaDeOperadores.peek()[0]))
				expresionPostFijaTemporal << " ";
			break;

		case '-':
				if (i == 0 || (!isdigit(expresionInfija[i - 1]) && expresionInfija[i - 1] != ')')) { //Se chequea si el numero/expresion ha evaluar tiene signo negativo
					expresionPostFijaTemporal << "-(";
					pilaDeOperadores.push("-(");

					continue;
				}

		case '+': case '*': case '/': case '^':
			while (!pilaDeOperadores.estaVacia() && precedencia(expresionInfija[i]) <= precedencia(pilaDeOperadores.peek()[0]))
				expresionPostFijaTemporal << pilaDeOperadores.pop();

			pilaDeOperadores.push(std::string(1, expresionInfija[i]));
			break;

		default: // Si es numero
			int contadorDeDigitos = 0;

			do
				expresionPostFijaTemporal << expresionInfija[i + contadorDeDigitos++];
			while (isdigit(expresionInfija[i + contadorDeDigitos]));

			i += contadorDeDigitos - 1;

			if (pilaDeOperadores.estaVacia() || precedencia(expresionInfija[i + 1]) > precedencia(pilaDeOperadores.peek()[0]))
				expresionPostFijaTemporal << " ";
			break;
		}

	while (!pilaDeOperadores.estaVacia())
		expresionPostFijaTemporal << pilaDeOperadores.pop();

	expresionPostfija = expresionPostFijaTemporal.str();
}

// Para insertar valores a la pila de la calculadora
long long Calculadora::evaluarExpresion(char ope, long long pri, long long seg) {

	switch (ope) {

	case '+': return pri + seg;

	case '-': return pri - seg;

	case '*': return pri * seg;

	case '/':
		if (seg == 0)
			throw std::string("No se puede dividir entre cero");

		return pri / seg;

	default: return static_cast<long long>(pow(pri, seg));
	}
}

// Se evalua la notacion postfija y se retorna su resultado
long long Calculadora::realizarCalculo() {

	if (expresionInfija.empty())
		return pila.peek();

	validarExpresion();
	crearNotacionPostfija();

	long long primerOperando, segundoOperando;

	for (int i = 0; i < expresionPostfija.size(); i++) {

		switch (expresionPostfija[i]) {

		case ' ':
			continue;

		case '(':
			pila.push(-1);
			break;

		case ')':
			pila.push(pila.pop() * pila.pop()); // El tope se volvera negativo, pues se multiplicara por el -1 insertado anteriormente
			break;

		case '-':
			if (expresionPostfija[i + 1] == '(') //Se chequea si el numero/expresion ha evaluar tiene signo negativo
				continue;

		case '+': case '*': case '/': case '^':
			segundoOperando = pila.pop();
			primerOperando = pila.pop();

			pila.push(evaluarExpresion(expresionPostfija[i], primerOperando, segundoOperando));
			break;

		default: // Si es numero
			std::string numero;

			do
				numero.push_back(expresionPostfija[i++]);
			while (isdigit(expresionPostfija[i]));

			pila.push(stoll(numero));

			i--; // Esto para volver a la posicion donde esta el ultimo digito del numero
			break;
		}
	}

	return pila.pop();
}

std::string Calculadora::getExpresionInfija() {

	return expresionInfija;
}

std::string Calculadora::getExpresionPostfija() {

	return expresionPostfija;
}

void Calculadora::agregarCaracter(char car) {

	expresionInfija.push_back(car);

	normalizarExpresion();
}

void Calculadora::borrarCaracter() {

	if (!expresionInfija.empty()) {
		if (expresionInfija.size() > 1 && expresionInfija.substr(expresionInfija.size() - 2, 2) == "-(") // Si se inserto la cadena "-(" y se quiere borrar un
			expresionInfija.pop_back();																	 // caracter, se hara un 'pop' extra para borrar ambos

		expresionInfija.pop_back();

		if (expresionInfija.empty())
			reiniciar();
	}
}

// Reinicia, a los valores de inicio, a la calculadora
void Calculadora::reiniciar() {

	expresionInfija.clear();
	expresionPostfija.clear();

	pila.vaciar();
	pila.push(0);
}