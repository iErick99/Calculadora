// lista.h
// Declaración de la clase Lista

#include <iostream>
#include "Nodo.h"

// Contiene las operaciones de la Lista Enlazada
// Note que el puntero al primer nodo de la lista
// se mantiene oculto al usuario (privado)
class Lista {
private:

	int tam;
	Nodo* inicio;

public:

	Lista();
	~Lista();
	void insertarElemento(Observer*);
	Nodo* getInicio();
	int borrarElemento(Observer*);
	void borrarLista();
	bool listaVacia();

};
