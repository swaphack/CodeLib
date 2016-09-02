#pragma once

#include "Maze.h"
#include "Ant.h"

#include <vector>

class WayPath
{
public:
	WayPath(Maze* pMaze, Ant* pAnt);
public:
	bool update(Position& position);
private:
	Maze* _maze;
	Ant* _ant;
private:
	typedef std::vector<Position> HistoryPath;

	HistoryPath _path;
};