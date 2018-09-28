#pragma once
#include <iostream>
#include <sstream>
#include "Observer.h"
using namespace std;

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
