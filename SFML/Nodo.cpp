#include "Nodo.h"

Nodo::Nodo() {}

Nodo::Nodo(Nodo* sig, Observer* info) : sig(sig), info(info) {}

Nodo::~Nodo() {

	delete info;
}

void Nodo::setSiguiente(Nodo* sig) {

	this->sig = sig;
}

Nodo* Nodo::getSiguiente() {

	return sig;
}

void Nodo::setInfo(Observer* inf) {

	this->info = inf;
}

Observer* Nodo::getInfo() {

	return info;
}