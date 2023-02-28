#include "Grid.h"

int Grid::getSquareValue(bool a, bool b, bool c, bool d)
{
	return (int)a * 8 + (int)b * 4 + (int)c * 2 + (int)d;
}

void Grid::createLines()
{
	for (int i = 0; i < this->gridSize.x - 1; i++)
	{
		for (int j = 0; j < this->gridSize.y - 1; j++)
		{
			Circle a = this->circles[i][j];
			Circle b = this->circles[i + 1][j];
			Circle c = this->circles[i + 1][j + 1];
			Circle d = this->circles[i][j + 1];

			int value = this->getSquareValue(a.getFilled(), b.getFilled(), c.getFilled(), d.getFilled());
			this->addLineToSquare(value, sf::Vector2f(i * this->squareSide, j * this->squareSide));
		}
	}
}

void Grid::addLineToSquare(int value, sf::Vector2f squarePos)
{
	switch (value)
	{
	default:
		break;
	case 1:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(0, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 2:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->squareSide, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 3:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(0, this->halfSide), squarePos + sf::Vector2f(this->squareSide, this->halfSide)));
		break;
	case 4:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(this->squareSide, this->halfSide)));
		break;
	case 5:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(this->squareSide, this->halfSide)));
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(0, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 6:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 7:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(0, this->halfSide)));
		break;
	case 8:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(0, this->halfSide)));
		break;
	case 9:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 10:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(0, this->halfSide)));
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->squareSide, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 11:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->halfSide, 0), squarePos + sf::Vector2f(this->squareSide, this->halfSide)));
		break;
	case 12:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(0, this->halfSide), squarePos + sf::Vector2f(this->squareSide, this->halfSide)));
		break;
	case 13:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(this->squareSide, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	case 14:
		this->lines.push_back(Line(this->window, squarePos + sf::Vector2f(0, this->halfSide), squarePos + sf::Vector2f(this->halfSide, this->squareSide)));
		break;
	}
}

Grid::Grid(sf::RenderWindow* window, sf::Vector2i gridSize, int squareSide, int pointRadius)
{
	this->window = window;
	this->gridSize = gridSize + sf::Vector2i(1, 1);
	this->squareSide = squareSide;
	this->pointRadius = pointRadius;
	this->halfSide = this->squareSide / 2.0;

	this->circles = new Circle * [this->gridSize.x];
	for (int i = 0; i < this->gridSize.x; i++)
	{
		this->circles[i] = new Circle[this->gridSize.y];
		for (int j = 0; j < this->gridSize.y; j++)
		{
			int value = rand() % 2;
			this->circles[i][j] = Circle(this->window, sf::Vector2f(i * this->squareSide, j * this->squareSide), this->pointRadius, value == 1);
		}
	}

	this->createLines();
}

Grid::Grid(sf::RenderWindow* window, int squareSide, int pointRadius)
{
	this->window = window;
	this->gridSize = sf::Vector2i(1, 1);
	this->squareSide = squareSide;
	this->pointRadius = pointRadius;
	this->halfSide = this->squareSide / 2.0;

	int x = (this->window->getSize().x / this->squareSide) + 1;
	int y = (this->window->getSize().y / this->squareSide) + 1;
	this->gridSize = sf::Vector2i(x, y);

	this->circles = new Circle * [this->gridSize.x];
	for (int i = 0; i < this->gridSize.x; i++)
	{
		this->circles[i] = new Circle[this->gridSize.y];
		for (int j = 0; j < this->gridSize.y; j++)
		{
			int value = rand() % 2;
			this->circles[i][j] = Circle(this->window, sf::Vector2f(i * this->squareSide, j * this->squareSide), this->pointRadius, value == 1);
		}
	}

	this->createLines();
}

void Grid::draw()
{
	for (Line line : this->lines) {
		line.draw();
	}

	for (int i = 0; i < this->gridSize.x; i++)
	{
		for (int j = 0; j < this->gridSize.y; j++)
		{
			this->circles[i][j].draw();
		}
	}
}

Grid::~Grid()
{
}
