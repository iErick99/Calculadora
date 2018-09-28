#include "View.h"
#include "Controller.h"
#include "Model.h"

View::View() {

	initComponents();

}

void View::start() {

	sf::RenderWindow window(sf::VideoMode(490, 500), "Calculadora");

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if ((event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed /*|| event.type == sf::Event::MouseEntered*/)) {

			if (sprite1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1))
				controller->agregaCaracter('1');
			else
			if (sprite2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2))
				controller->agregaCaracter('2');
			else	
			if (sprite3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num3 || event.key.code == sf::Keyboard::Numpad3))
				controller->agregaCaracter('3');
			else
			if (sprite4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::Return) {
				controller->agregaCaracter('(');
				controller->agregaCaracter('-');
			}
			else
			if (sprite5.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num4 || event.key.code == sf::Keyboard::Numpad4))
				controller->agregaCaracter('4');
			else
			if (sprite6.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num5 || event.key.code == sf::Keyboard::Numpad5))
				controller->agregaCaracter('5');
			else
			if (sprite7.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num6 || event.key.code == sf::Keyboard::Numpad6))
				controller->agregaCaracter('6');
			else
			if (sprite8.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::Add)
				controller->agregaCaracter('+');
			else
			if (sprite9.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num7 || event.key.code == sf::Keyboard::Numpad7))
				controller->agregaCaracter('7');
			else
			if (sprite10.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num8 || event.key.code == sf::Keyboard::Numpad8))
				controller->agregaCaracter('8');
			else
			if (sprite11.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num9 || event.key.code == sf::Keyboard::Numpad9))
				controller->agregaCaracter('9');
			else
			if (sprite12.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::Subtract)
				controller->agregaCaracter('-');
			else
			if (sprite13.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || (event.key.code == sf::Keyboard::Num0 || event.key.code == sf::Keyboard::Numpad0))
				controller->agregaCaracter('0');
			else
			if (sprite14.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::Divide)
				controller->agregaCaracter('/');
			else
			if (sprite15.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::Multiply)
				controller->agregaCaracter('*');
			else
			if ((sprite16.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::BackSpace) && !model->getCalculadora()->getExpresionInfija().empty())
				controller->borraCaracter();
			else
			if (sprite17.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				controller->agregaCaracter('^');
			else
			if (sprite18.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::LBracket)
				controller->agregaCaracter('(');
			else
			if (sprite19.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) || event.key.code == sf::Keyboard::RBracket)
				controller->agregaCaracter(')');
			else
			if (sprite20.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				controller->borraExpresion();

				std::string expresion = model->getCalculadora()->getExpresionInfija();

				text.setString(expresion);

				if (!model->getCalculadora()->getExpresionInfija().empty()) {

					try {

						text1.setString(std::to_string(model->getCalculadora()->realizarCalculo()));
						text2.setString(model->getCalculadora()->crearNotacionPostfija());

					}
					catch (std::string ex) {

						text2.setString(ex);

					}

				}
				else {

					text1.setString("");

					text2.setString("");

				}

			}

			if (event.type == sf::Event::Closed)
				window.close();



		}

		window.clear();
		window.draw(sprite);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);
		window.draw(sprite8);
		window.draw(sprite9);
		window.draw(sprite10);
		window.draw(sprite11);
		window.draw(sprite12);
		window.draw(sprite13);
		window.draw(sprite14);
		window.draw(sprite15);
		window.draw(sprite16);
		window.draw(sprite17);
		window.draw(sprite18);
		window.draw(sprite19);
		window.draw(sprite20);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.draw(numero1);
		window.draw(numero2);
		window.draw(numero3);
		window.draw(plus_minus);
		window.draw(numero4);
		window.draw(numero5);
		window.draw(numero6);
		window.draw(plus);
		window.draw(numero7);
		window.draw(numero8);
		window.draw(numero9);
		window.draw(minus);
		window.draw(numero0);
		window.draw(multiply);
		window.draw(division);
		window.draw(clear);
		window.draw(exponent);
		window.draw(bracket_open);
		window.draw(bracket_close);
		window.draw(trash);
		window.display();
	}

}

View::~View() {}

void View::setModel(Model* model) {

	this->model = model;
	model->attach(this);

}

void View::setController(Controller* controller) {	this->controller = controller;	}

void View::initComponents() {

	if (!texture.loadFromFile("fondo.jpg"))
		return;

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 490, 500));

	if (!icon1.loadFromFile("icons8-1-50.png"))
		return;

	numero1.setTexture(icon1);
	numero1.setPosition(55, 440);

	if (!icon2.loadFromFile("icons8-2-50.png"))
		return;

	numero2.setTexture(icon2);
	numero2.setPosition(165, 440);

	if (!icon3.loadFromFile("icons8-3-50.png"))
		return;

	numero3.setTexture(icon3);
	numero3.setPosition(275, 440);

	if (!icon_plus_minus.loadFromFile("icons8-plus-and-minus-50.png"))
		return ;

	plus_minus.setTexture(icon_plus_minus);
	plus_minus.setPosition(385, 440);

	if (!icon4.loadFromFile("icons8-4-50.png"))
		return;

	numero4.setTexture(icon4);
	numero4.setPosition(55, 400);

	if (!icon5.loadFromFile("icons8-5-50.png"))
		return;

	numero5.setTexture(icon5);
	numero5.setPosition(165, 400);

	if (!icon6.loadFromFile("icons8-6-50.png"))
		return;

	numero6.setTexture(icon6);
	numero6.setPosition(275, 400);

	if (!icon_plus.loadFromFile("icons8-add-new-50.png"))
		return;

	plus.setTexture(icon_plus);
	plus.setPosition(385, 400);

	if (!icon7.loadFromFile("icons8-7-50.png"))
		return;

	numero7.setTexture(icon7);
	numero7.setPosition(55, 360);

	if (!icon8.loadFromFile("icons8-8-50.png"))
		return;

	numero8.setTexture(icon8);
	numero8.setPosition(165, 360);

	if (!icon9.loadFromFile("icons8-9-50.png"))
		return;

	numero9.setTexture(icon9);
	numero9.setPosition(275, 360);

	if (!icon_minus.loadFromFile("icons8-reduce-50.png"))
		return;

	minus.setTexture(icon_minus);
	minus.setPosition(385, 360);

	if (!icon0.loadFromFile("icons8-0-50.png"))
		return;

	numero0.setTexture(icon0);
	numero0.setPosition(55, 320);

	if (!icon_division.loadFromFile("icons8-division-50.png"))
		return;

	division.setTexture(icon_division);
	division.setPosition(165, 320);

	if (!icon_multiply.loadFromFile("icons8-multiplication-50.png"))
		return;

	multiply.setTexture(icon_multiply);
	multiply.setPosition(275, 320);

	if (!icon_clear.loadFromFile("icons8-clear-symbol-50.png"))
		return;

	clear.setTexture(icon_clear);
	clear.setPosition(385, 320);

	if (!icon_exponent.loadFromFile("icons8-exponent-200.png"))
		return;

	exponent.setTexture(icon_exponent);
	exponent.setScale(0.20, 0.20);
	exponent.setPosition(60, 285);

	if (!icon_bracket_open.loadFromFile("icons8-brackets-open.png"))
		return;

	bracket_open.setTexture(icon_bracket_open);
	bracket_open.setScale(0.1113, 0.06);
	bracket_open.setPosition(165, 290);

	if (!icon_bracket_close.loadFromFile("icons8-brackets-close.png"))
		return;

	bracket_close.setTexture(icon_bracket_close);
	bracket_close.setScale(0.1113, 0.06);
	bracket_close.setPosition(275, 290);

	if (!icon_trash.loadFromFile("icons8-empty-trash-50.png"))
		return;

	trash.setTexture(icon_trash);
	trash.setScale(1, 0.85);
	trash.setPosition(385, 280);

	if (!texture1.loadFromFile("fondo_boton.jpg"))
		return;

	
	sprite1.setTexture(texture1);
	sprite1.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite1.setPosition(30, 450);

	sprite2.setTexture(texture1);
	sprite2.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite2.setPosition(140, 450);

	sprite3.setTexture(texture1);
	sprite3.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite3.setPosition(250, 450);

	sprite4.setTexture(texture1);
	sprite4.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite4.setPosition(360, 450);

	sprite5.setTexture(texture1);
	sprite5.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite5.setPosition(30, 410);

	sprite6.setTexture(texture1);
	sprite6.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite6.setPosition(140, 410);

	sprite7.setTexture(texture1);
	sprite7.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite7.setPosition(250, 410);

	sprite8.setTexture(texture1);
	sprite8.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite8.setPosition(360, 410);

	sprite9.setTexture(texture1);
	sprite9.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite9.setPosition(30, 370);

	sprite10.setTexture(texture1);
	sprite10.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite10.setPosition(140, 370);

	sprite11.setTexture(texture1);
	sprite11.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite11.setPosition(250, 370);

	sprite12.setTexture(texture1);
	sprite12.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite12.setPosition(360, 370);

	sprite13.setTexture(texture1);
	sprite13.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite13.setPosition(30, 330);

	sprite14.setTexture(texture1);
	sprite14.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite14.setPosition(140, 330);

	sprite15.setTexture(texture1);
	sprite15.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite15.setPosition(250, 330);

	sprite16.setTexture(texture1);
	sprite16.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite16.setPosition(360, 330);

	sprite17.setTexture(texture1);
	sprite17.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite17.setPosition(30, 290);

	sprite18.setTexture(texture1);
	sprite18.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite18.setPosition(140, 290);

	sprite19.setTexture(texture1);
	sprite19.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite19.setPosition(250, 290);

	sprite20.setTexture(texture1);
	sprite20.setTextureRect(sf::IntRect(0, 0, 100, 30));
	sprite20.setPosition(360, 290);

	font.loadFromFile("OpenSans-Light.ttf");

	text.setString("");
	text.setFont(font);
	text.setPosition(30, 30);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);

	text1.setString("");
	text1.setFont(font);
	text1.setPosition(30, 130);
	text1.setCharacterSize(30);
	text1.setStyle(sf::Text::Bold);
	text1.setFillColor(sf::Color::Red);

	text2.setString("");
	text2.setFont(font);
	text2.setPosition(30, 230);
	text2.setCharacterSize(30);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::Red);

}

void View::update() {
	


}