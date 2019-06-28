#include "Field.h"

#include "../struct/Point.h"

using namespace game;


Field::Field(float width, float height)
:m_width(width),
m_height(height)
{

}

float Field::getWidth() const
{
	return m_width;
}

float Field::getHeight() const
{
	return m_height;
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
