#include "Controller.h"
#include "Model.h"
#include "View.h"

//Constructor preterminado
Controller::Controller() {}

//Constructor con parámetros
//Recibe 2 parámetros, el primero; es un objeto tipo
//Model el cual será asignado como el model de clase,
//el segundo parámetro; es un objeto tipo View el cuál
//será asignado el view de la clase
Controller::Controller(Model* mod, View* vie) {

	model = mod;
	view = vie;

}

//Destructor
Controller::~Controller() {}

//Recibe por parámetro un carácter, el cúal 
//es enviado por parámetro al método del model
//llamado agregarCaracter
void Controller::agregarCaracter(char car) {

	model->agregarCaracter(car);
}

//Llama al método borrarCaracter del model asignado a la clase

void Controller::borrarCaracter() {

	model->borrarCaracter();

}

//Llama al método reiniciar del model asignado a la clase
void Controller::borrarExpresion() {

	model->reiniciarCalculadora();

}

//Llama al método realizarCalculo del model asignado a la clase
void Controller::realizarCalculo() {

	model->realizarCalculo();

}
