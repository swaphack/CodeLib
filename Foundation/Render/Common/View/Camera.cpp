#include "Camera.h"

#include "ext-config.h"
#include "../Tool/import.h"

using namespace render;


Camera::Camera()
{
	_position.set(0,0,0);

	_rotation.set(0, 0, 0);

	_scale.set(1.0f, 1.0f, 1.0f);
}

Camera::~Camera()
{

}

void Camera::updateCamera()
{
	
}

void Camera::lookAt(const math::Vector3& position)
{
	_position = position;
	_position *= -1;

	onSpaceChange();
}

void Camera::onSpaceChange()
{
	Tool::convertToOGLPoisition(_position, _obPosition);
}

//////////////////////////////////////////////////////////////////////////

Camera2D::Camera2D()
{
}

Camera2D::~Camera2D()
{

}

void Camera2D::updateCamera()
{
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
	glOrtho(0, 1, 0, 1, 0, 1);

	glTranslatef(_obPosition.getX(), _obPosition.getY(), _obPosition.getZ());
	glRotatef(_rotation.getX(), 1, 0, 0);
	glRotatef(_rotation.getY(), 0, 1, 0);
	glRotatef(_rotation.getZ(), 0, 0, 1);
	glScalef(_scale.getX(), _scale.getY(), _scale.getZ());
}

//////////////////////////////////////////////////////////////////////////

Camera3D::Camera3D()
{
}

Camera3D::~Camera3D()
{

}

void Camera3D::updateCamera()
{
	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();

	glFrustum(0, 1, 0, 1, 0, 1);

	glTranslatef(_obPosition.getX(), _obPosition.getY(), _obPosition.getZ());
	glRotatef(_rotation.getX(), 1, 0, 0);
	glRotatef(_rotation.getY(), 0, 1, 0);
	glRotatef(_rotation.getZ(), 0, 0, 1);
	glScalef(_scale.getX(), _scale.getY(), _scale.getZ());
}


