#include "DCColor.h"

using namespace render;


DCColor::DCColor()
{

}

DCColor::~DCColor()
{

}

void DCColor::draw()
{
	glColor4b(Color.red, Color.green, Color.blue, Color.alpha);
}
