#include "Model.h"

Model::Model() {	cal = new Calculadora();	}

Model::~Model() {}

Calculadora* Model::getCalculadora() {	return cal;	}
