#include "WayPath.h"


WayPath::WayPath(Maze* pMaze, Ant* pAnt)
:_maze(pMaze)
, _ant(pAnt)
{

}

bool WayPath::update(Position& position)
{

	std::vector<Position> direction;

	_maze->getEnabledWay(_ant->getPosition(), direction);

	int count = direction.size();

	if (count == 0)
	{
		return false;
	}

	int i = rand() % count;

	position.x = direction[i].x;
	position.y = direction[i].y;

	_ant->setPosition(position);

	return true;
}
