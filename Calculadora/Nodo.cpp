#include "Nodo.h"


//Constructor preterminado
//Se le asigna el valor de "nullptr" a los 
//atributos del Nodo
Nodo::Nodo() : sig(nullptr), info(nullptr) {}
 
//Constructor con parámetros
//Recibe 2 parámetros, el primero; es un nodo
//el cual será asignado como "siguiente nodo",
//el segundo parámetro; es la información que se le 
//asignará al nodo creado
Nodo::Nodo(Nodo* sig, Observer* info) : sig(sig), info(info) {}

//Destructor 
//Libera la información almacenada en el nodo
Nodo::~Nodo() {

	delete info;
}

//Recibe por parámetro un nodo
//el cual será asignado como "siguiente nodo"
void Nodo::setSiguiente(Nodo* sig) {

	this->sig = sig;
}

//Retorna el valor del siguiente nodo
Nodo* Nodo::getSiguiente() {

	return sig;
}

//Recibe por parámetro un Observer
//el cual será asignado como la información
//del nodo
void Nodo::setInfo(Observer* inf) {

	this->info = inf;
}

//Retorna la información almacenado en el nodo
Observer* Nodo::getInfo() {

	return info;
}