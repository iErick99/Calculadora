#pragma once

class Model;
class View;

class Controller {

private:

	Model* model;
	View* view;

public:
	Controller();
	Controller(Model*, View*);
	~Controller();
	void agregaCaracter(char);
	void borraCaracter();
	void borraExpresion();
};

