// lista.h
// Declaración de la clase Lista

#include <iostream>
#include "Nodo.h"

// Contiene las operaciones de la Lista Enlazada
// Note que el puntero al primer nodo de la lista
// se mantiene oculto al usuario (privado)
class Lista {
	public:
		Lista();
		//~Lista();
		void insertarElemento(Observer* item);
		Nodo* getInicio();
		/*int borrarElemento(int item);
		int buscarElemento(int item);
		void mostrarLista();
		void borrarLista();
		bool listaVacia();*/
	private:
		int tam;
		Nodo* inicio;
};
