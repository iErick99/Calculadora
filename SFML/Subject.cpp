#include "Subject.h"

//Recibe por par�metro un objeto observer el
//cual ser� agregado a la lista de "observers"
void Subject::attach(Observer* observer) {

	observers->insertarElemento(observer);

}

//Recorre la lista de "observers" y seguidamente
//invocando el m�todo "update" de cada "observer"
//en la lista
void Subject::notifyAllObservers() {

	Nodo* tmp;

	tmp = observers->getInicio();

	while (tmp != nullptr) {

		tmp->getInfo()->update();

		tmp = tmp->getSiguiente();

	}
}