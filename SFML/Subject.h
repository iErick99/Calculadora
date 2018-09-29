// Subject.h
// Declaración de la clase Subject

#pragma once

#include "lista.h"

// Definición de la clase Subject y sus métodos
// Esta clase formará parte del patrón "Observer"

class Subject {

private:

	Lista* observers = new Lista();

public:

	void attach(Observer* observer);
	void notifyAllObservers();

};