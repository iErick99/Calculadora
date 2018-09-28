#pragma once
#include "lista.h"
//#include "Nodo.h"

class Subject {
	
	private:
   
	Lista* observers = new Lista();
	int state;

	public:
	
	int getState() {return state;}

	void setState(int state) {
	   
		this->state = state;
		notifyAllObservers();
	  
	}

	void attach(Observer* observer){
	   
		observers->insertarElemento(observer);
	  
	}

	void notifyAllObservers(){
	   
		Nodo* tmp;

		tmp = observers->getInicio();

		while (tmp != nullptr) {

			tmp->getInfo()->update();

			tmp = tmp->getSiguiente();

		}
      
	} 	
};