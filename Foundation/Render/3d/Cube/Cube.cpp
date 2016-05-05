#include "Cube.h"

using namespace render;

void drawCubeFace(TextureRect* face)
{
	glVertex3f(face->leftDown.point.x, face->leftDown.point.y, face->leftDown.point.z);
	glVertex3f(face->rightDown.point.x, face->rightDown.point.y, face->rightDown.point.z);
	glVertex3f(face->rightUp.point.x, face->rightUp.point.y, face->rightUp.point.z);
	glVertex3f(face->leftUp.point.x, face->leftUp.point.y, face->leftUp.point.z);
}

Cube::Cube()
{

}

Cube::~Cube()
{

}

void Cube::draw()
{
	Node::draw();

	glBegin(GL_QUADS);
	
	glEnd();
}
