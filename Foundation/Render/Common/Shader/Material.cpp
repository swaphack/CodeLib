#include "Material.h"
#include "ext-config.h"

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

void Material::applyDefault()
{
	float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float matrialShiness = 0.0f;
	float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, matrialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matrialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matrialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &matrialShiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, matrialEmission);
}

void Material::apply()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, _matrialAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, _matrialDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, _matrialSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, &_matrialShiness);
	glMaterialfv(GL_FRONT, GL_EMISSION, _matrialEmission);
}

void Material::setAmbient(uint8 red, uint8 green, uint8 blue, uint8 alpha)
{
	_matrialAmbient[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialAmbient[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getAmbient() const
{
	return _matrialAmbient;
}

void Material::setDiffuse(uint8 red, uint8 green, uint8 blue, uint8 alpha)
{
	_matrialDiffuse[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialDiffuse[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getDiffuse() const
{
	return _matrialDiffuse;
}

void Material::setSpecular(uint8 red, uint8 green, uint8 blue, uint8 alpha)
{
	_matrialSpecular[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialSpecular[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getSpecular() const
{
	return _matrialSpecular;
}

void Material::setShiness(float value)
{
	_matrialShiness = value;
}

float Material::getShiness() const
{
	return _matrialShiness;
}

void Material::setEmisiion(uint8 red, uint8 green, uint8 blue, uint8 alpha)
{
	_matrialEmission[0] = red / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[1] = green / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[2] = blue / sys::COLOR_FLOAT_VALUE;
	_matrialEmission[3] = alpha / sys::COLOR_FLOAT_VALUE;
}

const float* Material::getEmisiion() const
{
	return _matrialEmission;
}

Material& Material::operator = (const Material& value)
{
	memcpy(_matrialAmbient, (float*)value.getAmbient(), sizeof(_matrialAmbient));
	memcpy(_matrialDiffuse, (float*)value.getDiffuse(), sizeof(_matrialDiffuse));
	memcpy(_matrialSpecular, (float*)value.getSpecular(), sizeof(_matrialSpecular));
	memcpy(_matrialEmission, (float*)value.getEmisiion(), sizeof(_matrialEmission));

	_matrialShiness = value.getShiness();

	return *this;
}
