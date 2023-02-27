#include "Circle.h"

Circle::Circle()
{
	this->window = NULL;
	this->position = sf::Vector2f();
	this->radius = NULL;
	this->isFilled = NULL;
}

Circle::Circle(sf::RenderWindow* window, sf::Vector2f position, float radius, bool isFilled)
{
	this->window = window;
	this->position = position;
	this->radius = radius;
	this->isFilled = isFilled;

	this->shape.setRadius(this->radius);
	this->shape.setPosition(this->position);
	this->shape.setFillColor(sf::Color::White);

	if (isFilled)
	{
		this->shape.setFillColor(sf::Color::Black);
	}
}

void Circle::draw()
{
	this->window->draw(this->shape);
}

Circle::~Circle()
{
}
