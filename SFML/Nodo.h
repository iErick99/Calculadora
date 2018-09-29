// Nodo.h
// Declaración de la clase Nodo

#pragma once
#include "Observer.h"

// Definición de la clase Nodo
// la cual será utlizada en una
// lista de Observers, esta misma
// será asignada como atributo a la 
// clase Subject, completando así
// el patrón Observer

class Nodo {

private:

	Nodo* sig;
	Observer* info;

public:

	Nodo();
	Nodo(Nodo* sig, Observer* info);
	~Nodo();
	void setSiguiente(Nodo* sig);
	Nodo* getSiguiente();
	void setInfo(Observer* inf);
	Observer* getInfo();

};
