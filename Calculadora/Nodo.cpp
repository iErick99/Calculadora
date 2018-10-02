#include "Nodo.h"


//Constructor preterminado
//Se le asigna el valor de "nullptr" a los 
//atributos del Nodo
Nodo::Nodo() : sig(nullptr), info(nullptr) {}
 
//Constructor con par�metros
//Recibe 2 par�metros, el primero; es un nodo
//el cual ser� asignado como "siguiente nodo",
//el segundo par�metro; es la informaci�n que se le 
//asignar� al nodo creado
Nodo::Nodo(Nodo* sig, Observer* info) : sig(sig), info(info) {}

//Destructor 
//Libera la informaci�n almacenada en el nodo
Nodo::~Nodo() {

	delete info;
}

//Recibe por par�metro un nodo
//el cual ser� asignado como "siguiente nodo"
void Nodo::setSiguiente(Nodo* sig) {

	this->sig = sig;
}

//Retorna el valor del siguiente nodo
Nodo* Nodo::getSiguiente() {

	return sig;
}

//Recibe por par�metro un Observer
//el cual ser� asignado como la informaci�n
//del nodo
void Nodo::setInfo(Observer* inf) {

	this->info = inf;
}

//Retorna la informaci�n almacenado en el nodo
Observer* Nodo::getInfo() {

	return info;
}