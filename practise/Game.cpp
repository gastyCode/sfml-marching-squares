#include "Game.h"

Game::Game(sf::Vector2<int> size, std::string title)
{
	this->size = size;
	this->window = new sf::RenderWindow(sf::VideoMode(this->size.x, this->size.y), title);

	this->changeFPS(60);

	this->circle = new Circle*[10];
	for (int i = 0; i < 10; i++)
	{
		this->circle[i] = new Circle[10];
		for (int j = 0; j < 10; j++)
		{
			this->circle[i][j] = Circle(this->window, sf::Vector2f(i * 60, j * 60), 10);
		}
	}
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
	(*this->window).clear(sf::Color::Black);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			this->circle[i][j].draw();
		}
	}
	(*this->window).display();
}

Game::~Game()
{
	delete[] window;
}
