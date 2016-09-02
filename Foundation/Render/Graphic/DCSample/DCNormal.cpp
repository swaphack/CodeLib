#include "DCNormal.h"

using namespace render;

DCNormal::DCNormal()
{

}

DCNormal::~DCNormal()
{

}

void DCNormal::draw()
{
	if (Normal)
	{
		glNormal3f(Normal->x, Normal->y, Normal->z);
	}
}

