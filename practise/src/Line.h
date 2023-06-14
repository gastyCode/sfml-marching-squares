#pragma once

#include <SFML/Graphics.hpp>

class Line
{
private:
	sf::RenderWindow* window;
	sf::Vector2f begin;
	sf::Vector2f end;

	sf::Vertex* line;

public:
	Line(sf::RenderWindow* window, sf::Vector2f begin, sf::Vector2f end);
	void draw() const;
};
