#include "Field.h"

using namespace game;

Field::Field()

{

}

Field::~Field()
{

}

bool Field::contains(const Point& point)
{
	if (point.X >= 0 && point.X <= getWidth()
		&& point.Y	>= 0 && point.Y <= getHeight())
	{
		return true;
	}

	return false;
}