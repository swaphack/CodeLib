#include "Camera.h"

#include "../GL/import.h"

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

void Camera::setPosition(float px, float py, float pz)
{
	_position.x = px;
	_position.y = py;
	_position.z = pz;
}

const sys::Vector& Camera::getPosition()
{
	return _position;
}

void Camera::setRotation(float rx, float ry, float rz)
{
	_rotation.x = rx;
	_rotation.y = ry;
	_rotation.z = rz;
}

const sys::Vector& Camera::getRotation()
{
	return _rotation;
}

void Camera::setScale(float sx, float sy, float sz)
{
	_scale.x = sx;
	_scale.y = sy;
	_scale.z = sz;
}

const sys::Vector& Camera::getScale()
{
	return _position;
}

void Camera::updateCamera()
{
	
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, 0, 1);

	glTranslatef(_position.x, _position.y, _position.z);
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glFrustum(0, 1, 0, 1, 0, 1);

	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation.x, 1, 0, 0);
	glRotatef(_rotation.y, 0, 1, 0);
	glRotatef(_rotation.z, 0, 0, 1);
	glScalef(_scale.x, _scale.y, _scale.z);
}


