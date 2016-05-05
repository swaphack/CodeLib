#include "Material.h"
#include "../GL/import.h"

using namespace	render;

Material::Material()
{
	_matrialAmbient[0] = 0.2f;
	_matrialAmbient[1] = 0.2f;
	_matrialAmbient[2] = 0.2f;
	_matrialAmbient[3] = 1.0f;

	_matrialDiffuse[0] = 0.8f;
	_matrialDiffuse[1] = 0.8f;
	_matrialDiffuse[2] = 0.8f;
	_matrialDiffuse[3] = 1.0f;

	_matrialSpecular[0] = 0.0f;
	_matrialSpecular[1] = 0.0f;
	_matrialSpecular[2] = 0.0f;
	_matrialSpecular[3] = 1.0f;


	_matrialShiness = 0.0f;

	_matrialEmission[0] = 0.0f;
	_matrialEmission[1] = 0.0f;
	_matrialEmission[2] = 0.0f;
	_matrialEmission[3] = 1.0f;
}

Material::~Material()
{

}

void Material::apply()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, _matrialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, _matrialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, _matrialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &_matrialShiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, _matrialEmission);
}

void Material::setAmbient(uchar red, uchar green, uchar blue, uchar alpha)
{
	_matrialAmbient[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getAmbient()
{
	return _matrialAmbient;
}

void Material::setDiffuse(uchar red, uchar green, uchar blue, uchar alpha)
{
	_matrialDiffuse[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getDiffuse()
{
	return _matrialDiffuse;
}

void Material::setSpecular(uchar red, uchar green, uchar blue, uchar alpha)
{
	_matrialSpecular[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getSpecular()
{
	return _matrialSpecular;
}

void Material::setShiness(float value)
{
	_matrialShiness = value;
}

float Material::getShiness()
{
	return _matrialShiness;
}

void Material::setEmisiion(uchar red, uchar green, uchar blue, uchar alpha)
{
	_matrialEmission[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getEmisiion()
{
	return _matrialEmission;
}

void Material::applyDefault()
{
	float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f};
	float matrialShiness = 0.0f;
	float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, matrialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matrialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matrialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &matrialShiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, matrialEmission);
}
