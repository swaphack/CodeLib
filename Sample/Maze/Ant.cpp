#include "Ant.h"


Ant::Ant()
{

}

Ant::~Ant()
{

}

const Position& Ant::getPosition()
{
	return _pos;
}

void Ant::setPosition(const Position& pos)
{
	_pos.x = pos.x;
	_pos.y = pos.y;
}

void Ant::setPosition(int x, int y)
{
	_pos.x = x;
	_pos.y = y;
}
