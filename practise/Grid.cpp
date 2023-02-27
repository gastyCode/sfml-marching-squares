#include "Grid.h"

Grid::Grid(sf::RenderWindow* window, sf::Vector2i gridSize, int squareSide, int pointRadius)
{
	this->window = window;
	this->gridSize = gridSize + sf::Vector2i(1, 1);
	this->squareSide = squareSide;
	this->pointRadius = pointRadius;

	this->circle = new Circle * [this->gridSize.x];
	for (int i = 0; i < this->gridSize.x; i++)
	{
		this->circle[i] = new Circle[this->gridSize.y];
		for (int j = 0; j < this->gridSize.y; j++)
		{
			int value = rand() % 2;
			this->circle[i][j] = Circle(this->window, sf::Vector2f(i * this->squareSide, j * this->squareSide), this->pointRadius, value == 1);
		}
	}
}

void Grid::draw()
{
	for (int i = 0; i < this->gridSize.x; i++)
	{
		for (int j = 0; j < this->gridSize.y; j++)
		{
			this->circle[i][j].draw();
		}
	}
}

Grid::~Grid()
{
}
