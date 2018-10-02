// Pila.h
// Declaraci�n de la clase Pila

#pragma once

// Definici�n de la clase Observer y sus m�todos
// Esta clase formar� parte del patr�n "Observer"

class Observer {

public:
   
	Observer();
	virtual void update() = 0;
   
};