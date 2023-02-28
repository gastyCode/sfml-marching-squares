#include "Line.h"

Line::Line(sf::RenderWindow* window, sf::Vector2f begin, sf::Vector2f end)
{
	this->window = window;
	this->begin = begin;
	this->end = end;

	this->line = new sf::Vertex[2]
	{
		sf::Vertex(begin),
		sf::Vertex(end)
	};
}

void Line::draw()
{
	this->window->draw(this->line, 2, sf::Lines);
}
