#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Circle.h"

class Circle;

class Game
{
private:
	sf::Vector2<int> size;
	sf::RenderWindow* window;
	int fps;
	Circle** circle;

	void events();

public:
	Game(sf::Vector2<int> size, std::string title);
	void changeFPS(int value);
	bool running();
	void update();
	void render();
	~Game();
};

