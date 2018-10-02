#include "Controller.h"
#include "Model.h"
#include "View.h"

//Constructor preterminado
Controller::Controller() {}

//Constructor con par�metros
//Recibe 2 par�metros, el primero; es un objeto tipo
//Model el cual ser� asignado como el model de clase,
//el segundo par�metro; es un objeto tipo View el cu�l
//ser� asignado el view de la clase
Controller::Controller(Model* mod, View* vie) {

	model = mod;
	view = vie;

}

//Destructor
Controller::~Controller() {}

//Recibe por par�metro un car�cter, el c�al 
//es enviado por par�metro al m�todo del model
//llamado agregarCaracter
void Controller::agregarCaracter(char car) {

	model->agregarCaracter(car);
}

//Llama al m�todo borrarCaracter del model asignado a la clase

void Controller::borrarCaracter() {

	model->borrarCaracter();

}

//Llama al m�todo reiniciar del model asignado a la clase
void Controller::borrarExpresion() {

	model->reiniciarCalculadora();

}

//Llama al m�todo realizarCalculo del model asignado a la clase
void Controller::realizarCalculo() {

	model->realizarCalculo();

}
