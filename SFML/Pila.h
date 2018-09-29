// Pila.h
// Declaraci�n de la clase Pila

#ifndef Pila_H
#define Pila_H
#include <iostream>


// Definici�n de la estructura NodoPila
// la cual ser� utlizada en la clase

template <class T>
struct NodoPila {
	T elemento;
	struct NodoPila* next;
};


// Contiene las operaciones de la pila

template <class T>
class Pila {

public:

	Pila();
	~Pila();
	void push(const T);
	T pop();
	T peek();
	bool estaVacia();
	void vaciar();

private:
	struct NodoPila<T>* top;
};

//Se inicializa el tope de la pila apuntando a nullptr
template <class T>
Pila<T>::Pila() {

	top = nullptr;
}

template <class T>
Pila<T>::~Pila() {}

//Se verifica la reserva de memoria exitosa, de ser
//as� se le asigna el valor al nuevo nodo creado
//y despu�s se le asigna el tope de la pila actual
//al nuevo nodo creado, por �ltimo el puntero "top"
//apuntar� al nuevo nodo creado
template <class T>
void Pila<T>::push(const T ite) {

	NodoPila<T>* nuevo;

	try {

		nuevo = new NodoPila<T>;
	}
	catch (std::bad_alloc exception) { return; }

	nuevo->elemento = ite;
	nuevo->next = top;
	top = nuevo;
}

//Verifica si el tope de la pila es igual a "nullptr"
//de serlo as� retorna -1. En caso de no serlo, se almacena
//el valor de "top" en una variable T, despu�s se crea un
//puntero auxiliar el cual apunta a la "top", seguidamente
//"top" pasa a apuntar al siguiente nodo de la pila. Por
//�ltimo la memoria del nodo auxiliar es libera y el valor
//es retornado

template <class T>
T Pila<T>::pop() {

	/*if (top == nullptr)
		continue;*/

	T valor = top->elemento;
	NodoPila<T>* tmp = top;

	top = top->next;
	delete tmp;
	tmp = nullptr;

	return valor;
}

//Retorna el valor del nodo "top" de la pila
template <class T>
T Pila<T>::peek() {

	return top->elemento;
}

//Si la pila est� vac�a retorna "true", de lo contrario retorna "false"
template <class T>
bool Pila<T>::estaVacia() {

	return top == nullptr;
}

//Vacia la pila utizando como m�todo auxiliar a "pop()"
//Realiza un "pop" mientras la pila no est� vac�a o el 
//"top" apunte a "nullptr"
template<class T>
void Pila<T>::vaciar() {

	while (top) { pop(); }
}

#endif