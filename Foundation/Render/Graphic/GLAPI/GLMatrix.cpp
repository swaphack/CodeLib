#include "GLMatrix.h"
#include "GLState.h"
using namespace render;

void GLMatrix::setMatrixMode(MatrixMode mode)
{
	glMatrixMode((GLenum)mode);
}

void GLMatrix::applyModelView()
{
	setMatrixMode(MatrixMode::MODELVIEW);
}

void GLMatrix::applyProjection()
{
	setMatrixMode(MatrixMode::PROJECTION);
}

void GLMatrix::applyTexture()
{
	setMatrixMode(MatrixMode::TEXTURE);
}

void GLMatrix::loadMatrix(const float* value)
{
	glLoadMatrixf(value);
}

void GLMatrix::loadMatrix(const math::Matrix44& value)
{
	loadMatrix(value.getValue());
}

void GLMatrix::loadIdentity()
{
	glLoadIdentity();
}

void GLMatrix::pushMatrix()
{
	glPushMatrix();
}

void GLMatrix::popMatrix()
{
	glPopMatrix();
}

void GLMatrix::multMatrix(const float* value)
{
	glMultMatrixf(value);
}

void GLMatrix::multMatrix(const math::Matrix44& value)
{
	multMatrix(value.getValue());
}

void GLMatrix::rotate(float angle, float x, float y, float z)
{
	glRotatef(angle, x, y, z);
}


void GLMatrix::rotate(float angle, const math::Vector3& value)
{
	rotate(angle, value.getX(), value.getY(), value.getZ());
}

void GLMatrix::rotate(const math::Vector3& value)
{
	rotate(value.getX(), 1, 0, 0);
	rotate(value.getY(), 0, 1, 0);
	rotate(value.getZ(), 0, 0, 1);
}

void GLMatrix::translate(float x, float y, float z)
{
	glTranslatef(x, y, z);
}

void GLMatrix::translate(const math::Vector3& value)
{
	translate(value.getX(), value.getY(), value.getZ());
}

void GLMatrix::scale(float x, float y, float z)
{
	glScalef(x, y, z);
}

void GLMatrix::scale(const math::Vector3& value)
{
	scale(value.getX(), value.getY(), value.getZ());
}

void GLMatrix::getProjectionMatrix(float* value)
{
	GLState::getFloat(GetTarget::PROJECTION_MATRIX, value);
}

void GLMatrix::getModelViewMatrix(float* value)
{
	GLState::getFloat(GetTarget::MODELVIEW_MATRIX, value);
}

void GLMatrix::getTextureMatrix(float* value)
{
	GLState::getFloat(GetTarget::TEXTURE_MATRIX, value);
}

void GLMatrix::loadFrustum(float left, float right, float bottom, float top, float zNear, float zFar)
{
	glFrustum(left, right, bottom, top, zNear, zFar);
}

void GLMatrix::loadOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
{
	glOrtho(left, right, bottom, top, zNear, zFar);
}

void GLMatrix::loadTransposeMatrix(float* value)
{
	glLoadTransposeMatrixf(value);
}

void GLMatrix::multTransposeMatrix(float* value)
{
	glMultTransposeMatrixf(value);
}
