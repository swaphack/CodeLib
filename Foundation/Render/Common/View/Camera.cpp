#include "Camera.h"

#include "../GL/import.h"
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

void Camera::onLookAt(const sys::Vector& position)
{

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
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
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
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
	glFrustum(0, 1, 0, 1, 0, 1);

	glTranslatef(_obPosition.x, _obPosition.y, _obPosition.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
}


