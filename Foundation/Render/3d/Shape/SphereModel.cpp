#include "SphereModel.h"

#include "mathlib.h"

using namespace render;

#define SPHERE_HORIZONTAL_COUNT 100
#define SPHERE_VERTICAL_COUNT 100

//球心坐标为（x，y，z），球的半径为radius，M，N分别表示球体的横纵向被分成多少份
/*
θ∈[0, π]， φ∈[0,2π]

球解析过程：
1.绕z轴行走，直至绕z轴一圈，到2
2.绕x轴行走，重复1，直至全部结束

*/

void getXY(float& x, float& y, int i, int j)
{
	x = sin(PI * 0.5f * j / SPHERE_VERTICAL_COUNT);
	y = sin(PI * 0.5f * i / SPHERE_HORIZONTAL_COUNT);

	x = 1.0f * j / SPHERE_VERTICAL_COUNT;
	y = 1.0f * i / SPHERE_HORIZONTAL_COUNT;
}

void drawSphere(GLfloat radius)
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

			getXY(cx[0], cy[0], i, j);

			x[1] = sinza * cosxy;
			y[1] = sinza * sinxy;
			z[1] = cosza;

			getXY(cx[1], cy[1], i, j + 1);

			x[2] = sinza * cosxya;
			y[2] = sinza * sinxya;
			z[2] = cosza;

			getXY(cx[2], cy[2], i + 1, j + 1);

			x[3] = sinz * cosxya;
			y[3] = sinz * sinxya;
			z[3] = cosz;

			getXY(cx[3], cy[3], i + 1, j);

			for (int k = 0; k < 4; k++)
			{
				glTexCoord3f(cx[k], cy[k], cz[k]);
				glVertex3f(x[k], y[k], z[k]);
			}
		}
	}
	glEnd();
}

SphereModel::SphereModel()
:_radius(0)
, _obRadius(0)
{

}

SphereModel::~SphereModel()
{
	SAFE_RELEASE(_frame);
}

void SphereModel::draw()
{
	Model::draw();

	const math::Volume& volume = Tool::getGLViewSize();
	const math::Vector3& scale = getScale();
	float scaleX = scale.getX() * _radius / volume.getWidth();
	float scaleY = scale.getY() * _radius / volume.getHeight();
	float scaleZ = scale.getZ() * _radius / volume.getDeep();
	glScalef(scaleX, scaleY, scaleZ);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);

	drawSphere(_obRadius);

	glDisable(GL_TEXTURE_2D);

	//Material::applyDefault();
}

void SphereModel::setRadius(float radius)
{
	_radius = radius;
	setDirty(true);
}

float SphereModel::getRadius()
{
	return _radius;
}

void SphereModel::initSelf()
{
	Model::initSelf();

	_obRadius = _radius / Tool::getGLViewSize().getWidth();
}

void SphereModel::setTexFrame(TexFrame* frame)
{
	SAFE_RELEASE(_frame);
	SAFE_RETAIN(frame);
	_frame = frame;
}
