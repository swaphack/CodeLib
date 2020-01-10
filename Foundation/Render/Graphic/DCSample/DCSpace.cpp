#include "DCSpace.h"
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

	glScalef(Scale.getX(), Scale.getY(), Scale.getZ());
	glRotatef(Rotation.getX(), 1, 0, 0);
	glRotatef(Rotation.getY(), 0, 1, 0);
	glRotatef(Rotation.getZ(), 0, 0, 1);
	glTranslatef(Position.getX(), Position.getY(), Position.getZ());
}

DCSpace* DCSpace::create(const math::Vector3& position, const math::Vector3& scale, const math::Vector3& rotation, bool relative)
{
	DCSpace* pSpace = sys::Instance<DCSpace>::getInstance();
	pSpace->Position = position;
	pSpace->Scale = scale;
	pSpace->Rotation = rotation;
	pSpace->Relative = relative;

	return pSpace;
}

//////////////////////////////////////////////////////////////////////////
DCSpaceMatrix::DCSpaceMatrix()
{

}

DCSpaceMatrix::~DCSpaceMatrix()
{

}

void DCSpaceMatrix::draw()
{
	glLoadIdentity();

	glMultMatrixf(Matrix.value());
}

DCSpaceMatrix* DCSpaceMatrix::create(const math::Matrix& matrix)
{
	DCSpaceMatrix* pSpace = sys::Instance<DCSpaceMatrix>::getInstance();
	pSpace->Matrix = matrix.transpose();
	return pSpace;
}
