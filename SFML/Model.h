// Model.h
// Declaraci�n de la clase Model

#pragma once
#include "Subject.h"
#include "Calculadora.h"

// Definici�n de la clase Model y sus m�todos
// Esta misma hereda de la clase "Subject"
// La cual es la parte del patr�n "Observer"
// Est� clase ser� utilizada para el ensamblaje
// del patr�n MVC(Model View Controller)

class Model : public Subject { 

private:

	Calculadora* cal;

public:

	static long int resultado;

	Model();
	~Model();
	Calculadora* getCalculadora();
	void realizarCalculo();
	void agregarCaracter(char);
	void borrarCaracter();
	void reiniciarCalculadora();
};