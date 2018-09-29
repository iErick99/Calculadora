// View.h
// Declaración de la clase View

#pragma once
#include "Observer.h"
#include "SFML/Graphics.hpp"


//Declaración de la clase model y view


class Controller;
class Model;

// Definición de la clase View y sus métodos
// Esta misma hereda de la clase "Observer"
// e implmenta el método "update" de esta misma
// Está clase será utilizada para el ensamblaje
// del patrón MVC(Model View Controller)

class View : public Observer {

private:

	Model* model;
	Controller* controller;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture icon1;
	sf::Sprite numero1;
	sf::Texture icon2;
	sf::Sprite numero2;
	sf::Texture icon3;
	sf::Sprite numero3;
	sf::Texture icon_plus_minus;
	sf::Sprite plus_minus;
	sf::Texture icon4;
	sf::Sprite numero4;
	sf::Texture icon5;
	sf::Sprite numero5;
	sf::Texture icon6;
	sf::Sprite numero6;
	sf::Texture icon_plus;
	sf::Sprite plus;
	sf::Texture icon7;
	sf::Sprite numero7;
	sf::Texture icon8;
	sf::Sprite numero8;
	sf::Texture icon9;
	sf::Sprite numero9;
	sf::Texture icon_minus;
	sf::Sprite minus;
	sf::Texture icon0;
	sf::Sprite numero0;
	sf::Texture icon_division;
	sf::Sprite division;
	sf::Texture icon_multiply;
	sf::Sprite multiply;
	sf::Texture icon_clear;
	sf::Sprite clear;
	sf::Texture icon_exponent;
	sf::Sprite exponent;
	sf::Texture icon_bracket_open;
	sf::Sprite bracket_open;
	sf::Texture icon_bracket_close;
	sf::Sprite bracket_close;
	sf::Texture icon_trash;
	sf::Sprite trash;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sf::Sprite sprite6;
	sf::Sprite sprite7;
	sf::Sprite sprite8;
	sf::Sprite sprite9;
	sf::Sprite sprite10;
	sf::Sprite sprite11;
	sf::Sprite sprite12;
	sf::Sprite sprite13;
	sf::Sprite sprite14;
	sf::Sprite sprite15;
	sf::Sprite sprite16;
	sf::Sprite sprite17;
	sf::Sprite sprite18;
	sf::Sprite sprite19;
	sf::Sprite sprite20;
	sf::Font font; 
	sf::Font font1;
	sf::Text texto_notacionInfija;
	sf::Text texto_resultado;
	sf::Text texto_notacionPostfija;
	sf::Text notacionInfija;
	sf::Text resultado;
	sf::Text notacionPostfija;
	sf::Texture texture1;

public:

	View();
	~View();
	void setModel(Model*);
	void setController(Controller*);
	void initComponents();
	void start();
	void update();
};

