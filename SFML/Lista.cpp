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
/*Lista::~Lista() {
	borrarLista();
}*/

Nodo* Lista::getInicio() {
	return inicio;
}

// Primero se verifica que se pueda crear memoria. Una vez creada la memoria, se realiza una 
// inserción simple, asignando el getInfo() al nuevo Nodo<Observer>. Cada Nodo<Observer> recién creado se
// inserta al final de la lista
// La función devuelve como resultado el getInfo() del item en caso de que se insertara correctamente, -1 en caso contrario 
void Lista::insertarElemento(Observer* item) {

	Nodo* nuevo = new Nodo();

	// Manejo de excepciones. Si no hay memoria para crear un Nodo<Observer> nuevo
	// se lanza una excepción

	nuevo->setInfo(item);     // Guardamos el getInfo() en el Nodo<Observer>
	nuevo->setSiguiente(nullptr);   // El puntero siguiente apuntaría a NULL

	// Si la lista está vacía, el Nodo<Observer> creado se convierte en el primer elemento
	if (inicio == nullptr)
		inicio = nuevo;
	else {                      // Si ya existen elementos en la lista, entonces necesitamos
		Nodo* tmp = inicio;     // un auxiliar para recorrer la lista y colocarnos al final
		while (tmp->getSiguiente() != nullptr)
			tmp = tmp->getSiguiente();
		tmp->setSiguiente(nuevo);   // Cuando ya llegamos al final, el último Nodo<Observer> de la lista apuntaría al Nodo<Observer>
	}                      // nuevo                           
  //return;   // Devolvemos el getInfo() actualizado del tamaño de la lista
}

//Primero se verifica si la lista está vacía, en ese caso no se hace nada. En caso contrario, se verifica si el elemento
//se encuentra en el primer nodo de la lista. Si el elemento no está en el primer nodo, entonces se recorre la lista
//utilizando dos punteros: tmp que apunta al nodo anterior mientras que tmp2 apunta al nodo actual. Si el elementro se
//encuentra en tmp2, entonces el nodo anterior debe apuntar al nodo que sigue al actual, y luego se libera la memoria
//La función devuelve como resultado el valor del item en caso de que se borrara correctamente, -1 en caso contrario 
/*int Lista::borrarElemento(int item) {
	// Caso #1: Si la lista está vacía no hay nada qué borrar
	if (listaVacia())
		return -1;

	// Caso #2: Si el elemento a borrar es el primer nodo de la lista
	Nodo* tmp;
	tmp = inicio;
	if (inicio->valor == item) {
		inicio = inicio->next;
		delete tmp;
		return item;
	}

	// Caso #3: Si el elemento a borrar es cualquier otro nodo distinto del primero
	Nodo* tmp2;
	tmp2 = tmp->next;
	while (tmp2 != nullptr) {
		if (tmp2->valor == item) {
			tmp->next = tmp2->next;
			delete tmp2;
			return item;
		}
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	return -1;
}

//Recorre la lista enlazada mostrando el contenido de cada uno de los elementos
void Lista::mostrarLista() {
	if (listaVacia()) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	}
	else
	{
		int i = 1;
		Nodo* tmp;
		tmp = inicio;
		while (tmp != nullptr) {
			std::cout << "Elemento #" << i++ << " " << tmp->valor << std::endl;
			tmp = tmp->next;
		}
	}
}


//Se recorre la lista enlazada de princio a fin, buscando el elemento en cada nodo. Además se cuenta con un contador que lleva la posición
//del nodo donde se está llevando a cabo la búsqueda
//La función devuelve como resultado la posición del nodo donde se encontró el elemento, -1 si el elemento no se encontró
int Lista::buscarElemento(int item) {
	int i = 1;
	Nodo* tmp;
	tmp = inicio;
	while (tmp != nullptr) {
		if (tmp->valor == item) {
			return i;
		}
		++i;
		tmp = tmp->next;
	}
	return -1;
}

//Con ayuda de un puntero auxiliar, se recorre la lista de inicio a fin, eliminando de la memoria cada uno de los nodos
//Esta función no retorna ningún valor
void Lista::borrarLista() {
	Nodo* tmp;
	while (inicio != nullptr) {
		tmp = inicio;
		inicio = inicio->next;
		delete tmp;
	}
	tam = 0;
}

//Función que devuelve "false" si la lista no está vacía, "true" en caso contrario
bool Lista::listaVacia() {
	if (inicio == nullptr)
		return true;
	return false;
}*/