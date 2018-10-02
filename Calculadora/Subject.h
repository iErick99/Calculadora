// Subject.h
// Declaraci�n de la clase Subject

#pragma once

#include "lista.h"

// Definici�n de la clase Subject y sus m�todos
// Esta clase formar� parte del patr�n "Observer"

class Subject {

private:

	Lista* observers = new Lista();

public:

	void attach(Observer* observer);
	void notifyAllObservers();

};