// lista.cpp
// Definición de la clase Lista

#include "Lista.h"

// Inicializa la lista enlazada, con el nodo inicial apuntando a nullptr, el tamaño de la lista
// con cero elementos
Lista::Lista() {
	int tam = 0;
	inicio = nullptr;
}

// Llama a la función borrarLista() para eliminar todos los elementos
Lista::~Lista() {
	borrarLista();
}


//Retorna el nodo inicial de la lista
Nodo* Lista::getInicio() {

	return inicio;

}

// Se realiza una inserción simple, asignando el item como valor al nuevo Nodo. Cada Nodo recién creado se
// inserta al final de la lista

void Lista::insertarElemento(Observer* item) {

	Nodo* nuevo = new Nodo();

	nuevo->setInfo(item);     // Se guarda el item en Nodo nuevo
	nuevo->setSiguiente(nullptr);   // El siguiente nodo apuntará a NULL

	// Si la lista está vacía, el Nodo creado se convierte en el primer elemento
	if (inicio == nullptr) {

		tam++;				//Se incrementa la cantidad de elementos en la lista 
		inicio = nuevo;

	}
	else {                
		Nodo* tmp = inicio;     
		while (tmp->getSiguiente() != nullptr)  // Se recorre hasta el final de la lista
			tmp = tmp->getSiguiente();

		tam;;
		tmp->setSiguiente(nuevo);  //Al último nodo de la lista se le asinga como siguiente al nuevo Nodo creado
	}                                           

}

//Primero se verifica si la lista está vacía, en ese caso no se hace nada. En caso contrario, se verifica si el elemento
//se encuentra en el primer nodo de la lista. Si el elemento no está en el primer nodo, entonces se recorre la lista
//utilizando dos punteros: tmp que apunta al nodo anterior mientras que tmp2 apunta al nodo actual. Si el elementro se
//encuentra en tmp2, entonces el nodo anterior debe apuntar al nodo que sigue al actual, y luego se libera la memoria
//La función devuelve como resultado el valor del item en caso de que se borrara correctamente, -1 en caso contrario

int Lista::borrarElemento(Observer* item) {
	// Caso #1: Si la lista está vacía no hay nada qué borrar
	if (listaVacia())
		return -1;

	// Caso #2: Si el elemento a borrar es el primer nodo de la lista
	Nodo* tmp;
	tmp = inicio;

	if (inicio->getInfo() == item) {

		--tam;
		inicio = inicio->getSiguiente();
		delete tmp;
		return 1;

	}

	// Caso #3: Si el elemento a borrar es cualquier otro nodo distinto del primero
	Nodo* tmp2;
	tmp2 = tmp->getSiguiente();

	while (tmp2 != nullptr) {

		if (tmp2->getInfo() == item) {

			tam--;
			tmp->setSiguiente(tmp2->getSiguiente());
			delete tmp2;
			return 1;

		}

		tmp = tmp2;
		tmp2 = tmp2->getSiguiente();
	}

	return -1;

}

//Con ayuda de un puntero auxiliar, se recorre la lista de inicio a fin, eliminando de la memoria cada uno de los nodos
//Esta función no retorna ningún valor
void Lista::borrarLista() {

	Nodo* tmp;
	while (inicio != nullptr) {

		tmp = inicio;
		inicio = inicio->getSiguiente();
		delete tmp;

	}

	tam = 0;

}

//Función que devuelve "false" si la lista no está vacía, "true" en caso contrario
bool Lista::listaVacia() {

	if (inicio == nullptr)
		return true;
	return false;

}