#include "GLTool.h"
#include "Tool.h"

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

void GLTool::setColor(const sys::Color4B& color)
{
	glColor4f(color.red / sys::COLOR_FLOAT_VALUE, color.green / sys::COLOR_FLOAT_VALUE, color.blue / sys::COLOR_FLOAT_VALUE, color.alpha / sys::COLOR_FLOAT_VALUE);
}

void GLTool::drawRect(const RectangeVertex* rectVertex, uint type)
{
	glBegin(type);

	glVertex3f(rectVertex->leftDown.x, rectVertex->leftDown.y, rectVertex->leftDown.z);
	glVertex3f(rectVertex->rightDown.x, rectVertex->rightDown.y, rectVertex->rightDown.z);
	glVertex3f(rectVertex->rightUp.x, rectVertex->rightUp.y, rectVertex->rightUp.z);
	glVertex3f(rectVertex->leftUp.x, rectVertex->leftUp.y, rectVertex->leftUp.z);

	glEnd();

	glDisable(GL_BLEND);
}

void GLTool::beginBlend(const BlendParam& blend)
{
	glEnable(GL_BLEND);
	glBlendFunc(blend.src, blend.dest);
}

void GLTool::beginBlend(int src, int dest)
{
	glEnable(GL_BLEND);
	glBlendFunc(src, dest);
}

void GLTool::endBlend()
{
	glDisable(GL_BLEND);
}
