#include "DCDraw.h"

using namespace render;

DCDraw::DCDraw()
{

}

DCDraw::~DCDraw()
{

}

void DCDraw::draw()
{
	glEnable(GL_BLEND);
	glBlendFunc(Blend.src, Blend.dest);

	glColor4f(Color.red, Color.green, Color.blue, Color.alpha);
	
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

	glDisable(GL_BLEND);
}

DCDraw* DCDraw::create(int type, const std::vector<math::Vector3>& points, float width, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend)
{
	DCDraw* pDraw = sys::Instance<DCDraw>::getInstance();
	pDraw->Type = type;
	pDraw->Width = width;
	pDraw->Blend = blend;

	convertColor4BTo4F(color, pDraw->Color);
	pDraw->Color.red *= opacity / COLOR_FLOAT_VALUE;
	pDraw->Color.green *= opacity / COLOR_FLOAT_VALUE;
	pDraw->Color.blue *= opacity / COLOR_FLOAT_VALUE;
	pDraw->Color.alpha *= opacity / COLOR_FLOAT_VALUE;

	pDraw->Points.assign(points.begin(), points.end());

	return pDraw;
}

