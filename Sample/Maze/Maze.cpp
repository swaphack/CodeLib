#include "Maze.h"
#include <cstdlib>

Maze::Maze(int width, int height)
{
	this->init(width, height);
}

Maze::~Maze()
{
	this->dispose();
}

void Maze::init(int width, int height)
{
	this->dispose();

	_width = width;
	_height = height;

	this->alloct();
}

void Maze::toScreen()
{
	printf("Maze map:\r\n");
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			printf("%d ", _cells[i * _height + j] ? 1 : 0);
		}
		printf("\r\n");
	}

	printf("\r\n");
}


void Maze::getEnabledWay(const Position& pos, std::vector<Position>& direction)
{
	direction.clear();

	bool bEnable = false;
	if (checkEnabledCell(pos.x - 1, pos.y))
	{
		direction.push_back(Position(pos.x - 1, pos.y));
	}
	if (checkEnabledCell(pos.x + 1, pos.y))
	{
		direction.push_back(Position(pos.x + 1, pos.y));
	}
	if (checkEnabledCell(pos.x, pos.y + 1))
	{
		direction.push_back(Position(pos.x, pos.y + 1));
	}
	if (checkEnabledCell(pos.x, pos.y - 1))
	{
		direction.push_back(Position(pos.x, pos.y - 1));
	}
}

void Maze::alloct()
{
	_cells = (bool*)malloc(_width * _height * sizeof(bool));

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			_cells[i * _height + j] = rand() % 2 == 1;
		}
	}
}

void Maze::dispose()
{
	if (_cells)
	{
		free(_cells);
		_cells = nullptr;
	}
}

bool Maze::checkEnabledCell(int x, int y)
{
	if (x < 0 || x >= _width || y < 0 || y >= _height)
	{
		return false;
	}

	return _cells[x * _width + y];
}