#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"

class Circle
{
private:
	sf::RenderWindow* window;
	sf::Vector2f position;
	float radius;
	bool isFilled;

	sf::CircleShape shape;

public:
	Circle();
	Circle(sf::RenderWindow* window, sf::Vector2f position, float radius, bool isFilled);
	bool getFilled();
	void draw();
	~Circle();
};

