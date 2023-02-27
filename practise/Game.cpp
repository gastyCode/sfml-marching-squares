#include "Game.h"

Game::Game(sf::Vector2<int> size, std::string title)
{
	this->size = size;
	this->window = new sf::RenderWindow(sf::VideoMode(this->size.x, this->size.y), title);

	this->changeFPS(60);

	this->grid = new Grid(this->window, sf::Vector2i(15, 11), 50, 7);
}

void Game::changeFPS(int value)
{
	this->fps = value;
	(*this->window).setFramerateLimit(this->fps);
}

bool Game::running()
{
	return (*this->window).isOpen();
}

void Game::events()
{
	sf::Event event;
	while ((*this->window).pollEvent(event))
	{
		switch (event.type)
		{
		default:
			break;

		case sf::Event::Closed:
			(*this->window).close();
			break;
		}
	}
}

void Game::update()
{
	this->events();
}

void Game::render()
{
	(*this->window).clear(sf::Color(128, 128, 128));
	(*this->grid).draw();
	(*this->window).display();
}

Game::~Game()
{
	delete[] this->window;
	delete[] this->grid;
}
