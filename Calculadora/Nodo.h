// Nodo.h
// Declaraci�n de la clase Nodo

#pragma once
#include "Observer.h"

// Definici�n de la clase Nodo
// la cual ser� utlizada en una
// lista de Observers, esta misma
// ser� asignada como atributo a la 
// clase Subject, completando as�
// el patr�n Observer

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
