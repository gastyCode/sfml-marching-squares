#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Grid.h"

class Grid;

class Game
{
private:
	sf::RenderWindow* window;
	sf::Vector2<int> size;
	int fps;

	Grid* grid;

	void events();

public:
	Game(sf::Vector2<int> size, std::string title);
	void changeFPS(int value);
	bool running();
	void update();
	void render();
	~Game();
};

