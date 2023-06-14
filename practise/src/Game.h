#pragma once

#include <SFML/Graphics.hpp>

#include "Grid.h"

class Grid;

class Game
{
private:
	sf::RenderWindow* window;
	sf::Vector2<int> size;
	int fps{};

	Grid* grid;

	void events() const;

public:
	Game(sf::Vector2<int> size, const std::string& title);
	void changeFPS(int value);
	bool running() const;
	void update() const;
	void render() const;
	~Game();
};
