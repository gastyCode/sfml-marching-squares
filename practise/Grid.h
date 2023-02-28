#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Circle.h"
#include "Line.h"

class Circle;
class Line;

class Grid
{
private:
	sf::RenderWindow* window;
	sf::Vector2i gridSize;
	int squareSide;
	int pointRadius;
	float halfSide;

	Circle** circles;
	std::vector<Line> lines;

	int getSquareValue(bool a, bool b, bool c, bool d);
	void createLines();
	void addLineToSquare(int value, sf::Vector2f squarePos);

public:
	Grid(sf::RenderWindow* window, sf::Vector2i gridSize, int squareSide, int pointRadius);
	Grid(sf::RenderWindow* window, int squareSide, int pointRadius);
	void draw();
	~Grid();
};

