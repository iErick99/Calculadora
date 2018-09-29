// Model.h
// Declaración de la clase Model

#pragma once
#include "Subject.h"
#include "Calculadora.h"

// Definición de la clase Model y sus métodos
// Esta misma hereda de la clase "Subject"
// La cual es la parte del patrón "Observer"
// Está clase será utilizada para el ensamblaje
// del patrón MVC(Model View Controller)

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