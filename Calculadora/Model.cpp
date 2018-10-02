#include "Model.h"

long int Model::resultado = 0;

//Constructor preterminado
//Inicializaci�n del objeto instanciado en la clase
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

// Llama al m�todo realizarCalculo del objeto instanciado en la clase, el
// valor retornado se almacena en el atributo de la clase llamada resultado
void Model::realizarCalculo() {

	resultado = cal->realizarCalculo();

}

// Recibe por par�metro un car�cter el c�al es enviado al 
// m�todo agregarCaracter del objeto instanciado en la clase
void Model::agregarCaracter(char car) {

	cal->agregarCaracter(car);
	notifyAllObservers();

}

// Llama al m�todo borrarCaracter del objeto instanciado en la clase, el
// cual realiza un borrado del �ltimo car�cter digitado por el usuario
void Model::borrarCaracter() {

	cal->borrarCaracter();
	notifyAllObservers();

}

// Llama al m�todo reiniciarCalculadora del objeto instanciado en la clase, el
// cual realiza un reinicio completo de toda la calculadora
void Model::reiniciarCalculadora() {

	cal->reiniciar();
	notifyAllObservers();

}