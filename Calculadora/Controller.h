// Controller.h
// Declaraci�n de la clase Controller

#pragma once


//Declaraci�n de la clase model y view

class Model;
class View;

// Definici�n de la clase Controller y sus m�todos
// Est� clase ser� utilizada para completar
// el patr�n MVC(Model View Controller)

class Controller {

private:

	Model* model;
	View* view;

public:
	Controller();
	Controller(Model*, View*);
	~Controller();
	void realizarCalculo();
	void agregarCaracter(char);
	void borrarCaracter();
	void borrarExpresion();
};