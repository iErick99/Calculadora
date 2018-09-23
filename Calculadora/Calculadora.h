#pragma once
#include <string>

class Calculadora {

public:

	Calculadora();
	~Calculadora();
	bool validaParentesis(std::string);
	std::istream& capturarExpresion(std::istream&, std::string&);
	std::string convertirNotacion(const std::string&);
	void removerEspacios(std::string&);
	int precedencia(char);
};

