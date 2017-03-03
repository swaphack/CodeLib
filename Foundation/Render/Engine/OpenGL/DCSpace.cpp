#include "macros.h"
using namespace render;

DCSpace::DCSpace()
{

}

DCSpace::~DCSpace()
{

}

void DCSpace::draw()
{
	if (!this->Relative)
	{
		glLoadIdentity();
	}

	glTranslatef(Position.x, Position.y, Position.z);
	glRotatef(Rotation.x, 1, 0, 0);
	glRotatef(Rotation.y, 0, 1, 0);
	glRotatef(Rotation.z, 0, 0, 1);
	glScalef(Scale.x, Scale.y, Scale.z);
}

DCSpace* DCSpace::create(const sys::Vector3& position, const sys::Vector3& scale, const sys::Vector3& rotation, bool relative)
{
	DCSpace* pSpace = sys::Instance<DCSpace>::getInstance();
	pSpace->Position = position;
	pSpace->Scale = scale;
	pSpace->Rotation = rotation;
	pSpace->Relative = relative;

	return pSpace;
}
