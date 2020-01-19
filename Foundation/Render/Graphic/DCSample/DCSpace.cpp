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

	glTranslatef(Position.getX(), Position.getY(), Position.getZ());
	glRotatef(Rotation.getX(), 1, 0, 0);
	glRotatef(Rotation.getY(), 0, 1, 0);
	glRotatef(Rotation.getZ(), 0, 0, 1);
	glScalef(Scale.getX(), Scale.getY(), Scale.getZ());	

	GLfloat value0[16] = { 0 };
	glGetFloatv(GL_MODELVIEW_MATRIX, value0);
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
	if (!this->Relative)
	{
		glLoadIdentity();
	}

	GLfloat value[16] = { 0 };
	Matrix.getValue(value, 16);
	glMultMatrixf(value);
}

DCSpaceMatrix* DCSpaceMatrix::create(const math::Matrix& matrix, bool relative)
{
	DCSpaceMatrix* pSpace = sys::Instance<DCSpaceMatrix>::getInstance();
	pSpace->Relative = relative;
	pSpace->Matrix = matrix.transpose();
	return pSpace;
}
