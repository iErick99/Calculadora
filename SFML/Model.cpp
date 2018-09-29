#include "Model.h"

long int Model::resultado = 0;

//Constructor preterminado
//Inicialización del objeto instanciado en la clase
Model::Model() { cal = new Calculadora(); }

//Destructor
//Libera la memoria del objeto instaciado en la clase
Model::~Model() {

	delete cal;

}

// Retorna el objeto instanciado en la clase
Calculadora* Model::getCalculadora() {

	return cal;
}

// Llama al método realizarCalculo del objeto instanciado en la clase, el
// valor retornado se almacena en el atributo de la clase llamada resultado
void Model::realizarCalculo() {

	resultado = cal->realizarCalculo();

}

// Recibe por parámetro un carácter el cúal es enviado al 
// método agregarCaracter del objeto instanciado en la clase
void Model::agregarCaracter(char car) {

	cal->agregarCaracter(car);
	notifyAllObservers();

}

// Llama al método borrarCaracter del objeto instanciado en la clase, el
// cual realiza un borrado del último carácter digitado por el usuario
void Model::borrarCaracter() {

	cal->borrarCaracter();
	notifyAllObservers();

}

// Llama al método reiniciarCalculadora del objeto instanciado en la clase, el
// cual realiza un reinicio completo de toda la calculadora
void Model::reiniciarCalculadora() {

	cal->reiniciar();
	notifyAllObservers();

}