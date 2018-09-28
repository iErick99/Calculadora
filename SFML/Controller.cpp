#include "Controller.h"
#include "Model.h"
#include "View.h"


Controller::Controller() {
}

Controller::Controller(Model* mod, View* vie) {

	model = mod;
	view = vie;

}


Controller::~Controller() {
}

void Controller::agregaCaracter(char car) {

	model->getCalculadora()->agregarCaracter(car);

}

void Controller::borraCaracter() {

	model->getCalculadora()->borrarCaracter();

}

void Controller::borraExpresion() {

	model->getCalculadora()->borrarExpresion();

}
