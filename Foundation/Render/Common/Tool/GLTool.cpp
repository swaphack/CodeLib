#include "GLTool.h"
#include "UITool.h"

using namespace render;


void drawTextureVertex(const TextureVertex* texCoords)
{
	glTexCoord3f(texCoords->coords.x, texCoords->coords.y, texCoords->coords.z);
	glVertex3f(texCoords->point.x, texCoords->point.y, texCoords->point.z);
}


void GLTool::drawRectVertex(const TextureRect* texRect)
{
	// Draw quad
	glBegin(GL_QUADS);
	drawTextureVertex(&texRect->leftDown);
	drawTextureVertex(&texRect->rightDown);
	drawTextureVertex(&texRect->rightUp);
	drawTextureVertex(&texRect->leftUp);
	glEnd();
}

void GLTool::drawTriangleVertex(const TextureRect* texRect)
{
	// Draw quad
	glBegin(GL_TRIANGLE_STRIP);	
	drawTextureVertex(&texRect->rightUp);
	drawTextureVertex(&texRect->leftUp);
	drawTextureVertex(&texRect->rightDown);
	drawTextureVertex(&texRect->leftDown);
	glEnd();
}

void GLTool::drawRectVertexWithNormal(const TextureRect* texRect, const sys::Vector& normal)
{
	// Draw quad
	glBegin(GL_QUADS);

	glNormal3f(normal.x, normal.y, normal.z);

	drawTextureVertex(&texRect->leftDown);
	drawTextureVertex(&texRect->rightDown);
	drawTextureVertex(&texRect->rightUp);
	drawTextureVertex(&texRect->leftUp);
	glEnd();
}

void GLTool::setColor(uchar red, uchar green, uchar blue, uchar alpha)
{
	glColor4f(red / sys::COLOR_FLOAT_VALUE, green / sys::COLOR_FLOAT_VALUE, blue / sys::COLOR_FLOAT_VALUE, alpha / sys::COLOR_FLOAT_VALUE);
}

void GLTool::setColor(sys::Color4B color)
{
	glColor4f(color.red / sys::COLOR_FLOAT_VALUE, color.green / sys::COLOR_FLOAT_VALUE, color.blue / sys::COLOR_FLOAT_VALUE, color.alpha / sys::COLOR_FLOAT_VALUE);
}

void GLTool::drawRect(const RectangeVertex* rectVertex, uint type)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(type);

	glVertex3f(rectVertex->leftDown.x, rectVertex->leftDown.y, rectVertex->leftDown.z);
	glVertex3f(rectVertex->rightDown.x, rectVertex->rightDown.y, rectVertex->rightDown.z);
	glVertex3f(rectVertex->rightUp.x, rectVertex->rightUp.y, rectVertex->rightUp.z);
	glVertex3f(rectVertex->leftUp.x, rectVertex->leftUp.y, rectVertex->leftUp.z);

	glEnd();

	glDisable(GL_BLEND);
}

void GLTool::calNormal(const sys::Vector& p1, const sys::Vector& p2, const sys::Vector& p3, sys::Vector& normal)
{
	sys::Vector vc1, vc2;
	float a, b, c;
	double r;

	vc1.x = p2.x - p1.x; vc1.y = p2.y - p1.y; vc1.z = p2.z - p1.z;
	vc2.x = p3.x - p1.x; vc2.y = p3.y - p1.y; vc2.z = p3.z - p1.z;

	a = vc1.y * vc2.z - vc2.y * vc1.z;
	b = vc2.x * vc1.z - vc1.x * vc2.z;
	c = vc1.x * vc2.y - vc2.x * vc1.y;
	r = sqrt(a * a + b* b + c * c);

	normal.x = a / r;
	normal.y = b / r;
	normal.z = c / r;
}

void GLTool::calRect(const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor, RectangeVertex& rectVertex)
{
	float x = 0;
	float y = 0;

	// left down
	x = position.x - volume.width * anchor.x;
	y = position.y - volume.height * anchor.y;
	rectVertex.leftDown = UITool::convertToOGLPoisition(x, y, position.z);

	// right down
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y - volume.height * anchor.y;
	rectVertex.rightDown = UITool::convertToOGLPoisition(x, y, position.z);

	// right up
	x = position.x + volume.width * (1 - anchor.x);
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.rightUp = UITool::convertToOGLPoisition(x, y, position.z);

	// left up
	x = position.x - volume.width * anchor.x;
	y = position.y + volume.height * (1 - anchor.y);
	rectVertex.leftUp = UITool::convertToOGLPoisition(x, y, position.z);
}
