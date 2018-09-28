#pragma once
#include "Subject.h"
#include "Calculadora.h"

class Model : public Subject { 

private:

	Calculadora* cal;

public:

	Model();
	~Model();
	Calculadora* getCalculadora();


};

