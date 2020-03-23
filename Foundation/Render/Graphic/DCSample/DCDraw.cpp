#include "DCDraw.h"

using namespace render;

DCDraw::DCDraw()
{

}

DCDraw::~DCDraw()
{

}

void DCDraw::drawDC()
{	
	if (Type == EBM_POINTS)
	{
		glPointSize(Width);
	}
	else
	{
		glLineWidth(Width);
	}

	glBegin(Type);

	std::vector<math::Vector3>::const_iterator iter = Points.begin();
	while (iter != Points.end())
	{
		glVertex3f((*iter).getX(), (*iter).getY(), (*iter).getZ());
		iter++;
	}

	glEnd();
}

DCDraw* DCDraw::create(int type, const std::vector<math::Vector3>& points, float width, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCDraw* pDraw = sys::Instance<DCDraw>::getInstance();
	pDraw->initColor(color, opacity, blend);

	pDraw->Type = type;
	pDraw->Width = width;
	pDraw->Blend = blend;

	pDraw->Points.assign(points.begin(), points.end());

	return pDraw;
}

