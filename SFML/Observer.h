// Pila.h
// Declaración de la clase Pila

#pragma once

// Definición de la clase Observer y sus métodos
// Esta clase formará parte del patrón "Observer"

class Observer {

public:
   
	Observer();
	virtual void update() = 0;
   
};