#include "DCColor.h"

using namespace render;


DCColor::DCColor()
:Color(nullptr)
{

}

DCColor::~DCColor()
{

}

void DCColor::draw()
{
	if (Color)
	{
		glColor4b(Color->red, Color->green, Color->blue, Color->alpha);
	}
}
