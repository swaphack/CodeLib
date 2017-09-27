#include "Camera.h"

#include "ext-config.h"
#include "../Tool/import.h"

using namespace render;


Camera::Camera()
{
	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = 0.0f;

	_rotation.x = 0.0f;
	_rotation.y = 0.0f;
	_rotation.z = 0.0f;

	_scale.x = 1.0f;
	_scale.y = 1.0f;
	_scale.z = 1.0f;
}

Camera::~Camera()
{

}

void Camera::updateCamera()
{
	
}

void Camera::lookAt(const sys::Vector3& position)
{
	_position = position;
	_position.mult(-1);

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

	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
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

	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
}


