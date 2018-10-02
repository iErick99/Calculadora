#include <iostream>
#include "SFML/Graphics.hpp"
#include "Controller.h"
#include "Model.h"
#include "View.h"


int main(){

	Model* model = new Model();
	View* view = new View();
	Controller* controller = new Controller(model, view);
	view->setModel(model);
	view->setController(controller);
	view->start();

	system("pause");
	return 0;
}