#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Circle.h"

class Circle;

class Grid
{
private:
	sf::RenderWindow* window;
	sf::Vector2i gridSize;
	int squareSide;
	int pointRadius;

	Circle** circle;
public:
	Grid(sf::RenderWindow* window, sf::Vector2i gridSize, int squareSide, int pointRadius);
	void draw();
	~Grid();
};

