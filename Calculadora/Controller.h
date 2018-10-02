// Controller.h
// Declaración de la clase Controller

#pragma once


//Declaración de la clase model y view

class Model;
class View;

// Definición de la clase Controller y sus métodos
// Está clase será utilizada para completar
// el patrón MVC(Model View Controller)

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