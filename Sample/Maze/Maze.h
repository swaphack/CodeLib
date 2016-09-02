#pragma once

#include "common.h"

#include <vector>

class Maze
{
public:
	Maze(int width, int height);
	~Maze();
public:
	void init(int width, int height);
	void toScreen();
	void getEnabledWay(const Position& pos, std::vector<Position>& direction);
protected:
	void alloct();
	void dispose();
	bool checkEnabledCell(int x, int y);
private:
	int _width;
	int _height;
	bool* _cells;
};