#pragma once

#include "common.h"

class Ant
{
public:
	Ant();
	~Ant();
public:
	const Position& getPosition();
	void setPosition(const Position& pos);
	void setPosition(int x, int y);
private:
	Position _pos;
};