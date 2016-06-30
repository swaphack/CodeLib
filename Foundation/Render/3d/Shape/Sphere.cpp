#include "Sphere.h"

using namespace render;

//球心坐标为（x，y，z），球的半径为radius，M，N分别表示球体的横纵向被分成多少份
void drawSphere(GLfloat xx, GLfloat yy, GLfloat zz, GLfloat radius)
{
	float step_z = PI / SPHERE_HORIZONTAL_COUNT;
	float step_xy = 2 * PI / SPHERE_VERTICAL_COUNT;
	float x[4], y[4], z[4];
	float angle_z = 0.0;
	float angle_xy = 0.0;
	int i = 0, j = 0;
	glBegin(GL_QUADS);
	for (i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
	{
		angle_z = i * step_z;

		for (j = 0; j < SPHERE_VERTICAL_COUNT; j++)
		{
			angle_xy = j * step_xy;
			x[0] = radius * sin(angle_z) * cos(angle_xy);
			y[0] = radius * sin(angle_z) * sin(angle_xy);
			z[0] = radius * cos(angle_z);
			x[1] = radius * sin(angle_z + step_z) * cos(angle_xy);
			y[1] = radius * sin(angle_z + step_z) * sin(angle_xy);
			z[1] = radius * cos(angle_z + step_z);
			x[2] = radius*sin(angle_z + step_z)*cos(angle_xy + step_xy);
			y[2] = radius*sin(angle_z + step_z)*sin(angle_xy + step_xy);
			z[2] = radius*cos(angle_z + step_z);
			x[3] = radius * sin(angle_z) * cos(angle_xy + step_xy);
			y[3] = radius * sin(angle_z) * sin(angle_xy + step_xy);
			z[3] = radius * cos(angle_z);
			for (int k = 0; k < 4; k++)
			{
				glVertex3f(xx + x[k], yy + y[k], zz + z[k]);
			}
		}
	}
	glEnd();
}

Sphere::Sphere()
:_radius(1)
{

}

Sphere::~Sphere()
{

}

void Sphere::draw()
{
	drawSphere(_obPosition.x, _obPosition.y, _obPosition.z, _radius);
}

void Sphere::setRadius(float radius)
{
	_radius = radius;
	setDirty(true);
}

float Sphere::getRadius()
{
	return _radius;
}

void Sphere::initSelf()
{
	CtrlModel::initSelf();
}
