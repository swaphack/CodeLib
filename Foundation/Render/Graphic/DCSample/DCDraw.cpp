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

	std::vector<sys::Vector3>::const_iterator iter = Points.begin();
	while (iter != Points.end())
	{
		glVertex3f((*iter).x, (*iter).y, (*iter).z);
		iter++;
	}

	glEnd();

	glDisable(GL_BLEND);
}

DCDraw* DCDraw::create(int type, const std::vector<sys::Vector3>& points, float width, const sys::Color4B& color, uchar opacity, const BlendParam& blend)
{
	DCDraw* pDraw = sys::Instance<DCDraw>::getInstance();
	pDraw->Type = type;
	pDraw->Width = width;
	pDraw->Blend = blend;

	convertColor4BTo4F(color, pDraw->Color);
	pDraw->Color.red *= opacity / sys::COLOR_FLOAT_VALUE;
	pDraw->Color.green *= opacity / sys::COLOR_FLOAT_VALUE;
	pDraw->Color.blue *= opacity / sys::COLOR_FLOAT_VALUE;
	pDraw->Color.alpha *= opacity / sys::COLOR_FLOAT_VALUE;

	pDraw->Points.assign(points.begin(), points.end());

	return pDraw;
}

