#pragma once

struct Position
{
	int x;
	int y;

	Position()
	{
		reset();
	}

	Position(int x, int y)
		:x(x)
		, y(y)
	{
	}

	void reset()
	{
		x = 0;
		y = 0;
	}
};