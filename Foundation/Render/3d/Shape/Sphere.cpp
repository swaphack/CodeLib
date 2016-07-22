#include "Sphere.h"

using namespace render;

#define SPHERE_HORIZONTAL_COUNT 100
#define SPHERE_VERTICAL_COUNT 100

//球心坐标为（x，y，z），球的半径为radius，M，N分别表示球体的横纵向被分成多少份
/*
θ∈[0, π]， φ∈[0,2π]

球解析过程：
1.绕z轴行走，直至绕z轴一圈，到2
2.绕x轴行走，重复1，直至全部结束

纹理解析过程
1.绕
*/
void drawSphere(GLfloat radius, float xDy)
{
	float step_z = 1.0f * PI / SPHERE_HORIZONTAL_COUNT;
	float step_xy = 2.0f * PI / SPHERE_VERTICAL_COUNT;
	float x[4], y[4], z[4];
	float angle_z = 0.0f;
	float angle_xy = 0.0f;

	float cx[4] = { 0 }, cy[4] = { 0 }, cz[4] = { 0 };

	int i = 0, j = 0;

	float sinz, cosz, sinza, cosza;

	float sinxy, cosxy, sinxya, cosxya;

	glScalef(1, xDy, 1);

	glBegin(GL_QUADS);
	for (i = 0; i < SPHERE_HORIZONTAL_COUNT; i++)
	{
		angle_z = i * step_z;

		sinz = sin(angle_z);
		cosz = cos(angle_z);
		sinza = sin(angle_z + step_z);
		cosza = cos(angle_z + step_z);

		for (j = 0; j < SPHERE_VERTICAL_COUNT; j++)
		{
			angle_xy = j * step_xy;

			sinxy = sin(angle_xy);
			cosxy = cos(angle_xy);
			sinxya = sin(angle_xy + step_xy);
			cosxya = cos(angle_xy + step_xy);

			x[0] = sinz * cosxy;
			y[0] = sinz * sinxy;
			z[0] = cosz;

			x[1] = sinza * cosxy;
			y[1] = sinza * sinxy;
			z[1] = cosza;

			x[2] = sinza * cosxya;
			y[2] = sinza * sinxya;
			z[2] = cosza;

			x[3] = sinz * cosxya;
			y[3] = sinz * sinxya;
			z[3] = cosz;

			for (int k = 0; k < 4; k++)
			{
				cx[k] = 1.0f;
				if (j < SPHERE_VERTICAL_COUNT * 0.25f)
				{
					cx[k] = 0.25f * x[k];
				}
				else if (j < SPHERE_VERTICAL_COUNT * 0.5f)
				{
					cx[k] = 0.25f * x[k] - 0.5f;
				}
				else if (j < SPHERE_VERTICAL_COUNT * 0.75f)
				{
					//cx[k] = -0.25f * x[k] + 0.5f;
				}
				else
				{
					//cx[k] = 0.25f * x[k] + 0.75f;
				}

				cy[k] = 1.0f;
				if (i < SPHERE_HORIZONTAL_COUNT * 0.5f)
				{
					cy[k] = 0.5f * y[k] + 0.5f;
				}
				else if (i < SPHERE_HORIZONTAL_COUNT)
				{
					cy[k] = 0.5f * y[k] + 0.5f;
				}				

				ADJUST_DURATION_VALUE_RANGE(cx[k], 0, 1, 1);
				ADJUST_DURATION_VALUE_RANGE(cy[k], 0, 1, 1);

				glTexCoord3f(cx[k], cy[k], cz[k]);
				glVertex3f(radius * x[k], radius * y[k], radius * z[k]);
			}
		}
	}
	glEnd();
}

Sphere::Sphere()
:_radius(0)
, _obRadius(0)
{

}

Sphere::~Sphere()
{

}

void Sphere::draw()
{
	CtrlModel::draw();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);
	drawSphere(_obRadius, Tool::getGLViewSize().width / Tool::getGLViewSize().height);
	glDisable(GL_TEXTURE_2D);
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

	_obRadius = _radius / Tool::getGLViewSize().width;
}
