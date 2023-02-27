#include "Circle.h"

Circle::Circle()
{
	this->window = NULL;
	this->position = sf::Vector2f();
	this->radius = 0;
}

Circle::Circle(sf::RenderWindow* window, sf::Vector2f position, float radius)
{
	this->window = window;
	this->position = position;
	this->radius = radius;

	this->shape.setRadius(this->radius);
	this->shape.setFillColor(sf::Color::Blue);
	this->shape.setPosition(this->position);
}

void Circle::draw()
{
	this->window->draw(this->shape);
}
