#include "Circle.h"

Circle::Circle()
{
	this->window = nullptr;
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
	this->shape.setPosition(this->position - sf::Vector2f(this->radius, this->radius));
	this->shape.setFillColor(sf::Color::Red);

	if (isFilled)
	{
		this->shape.setFillColor(sf::Color::Green);
	}
}

bool Circle::getFilled() const
{
	return this->isFilled;
}

void Circle::draw() const
{
	this->window->draw(this->shape);
}
