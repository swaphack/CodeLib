#include "common.h"
#include "Maze.h"
#include "Ant.h"
#include "Path.h"

#include <ctime>
#include <windows.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define DELAY_MILLSECOND 1000

int main(int argc, char** argv)
{
	srand(time(NULL));

	Maze* pMaze = new Maze(MAZE_WIDTH, MAZE_HEIGHT);
	pMaze->toScreen();

	Ant* pAnt = new Ant();

	WayPath* pPathWay = new WayPath(pMaze, pAnt);
	
	Position pos;
	while (pPathWay->update(pos))
	{
		printf("ant walk to (%d,%d)\r\n", pos.x, pos.y);
		Sleep(DELAY_MILLSECOND);
	}

	delete pMaze;
	delete pAnt;
	delete pPathWay;

	getchar();

	return 0;
}