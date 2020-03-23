#include "Material.h"
#include "ext-config.h"
#include "Graphic/DCSample/DCMaterial.h"
#include "Graphic/Command/DrawCommander.h"

using namespace	render;

Material::Material()
{
	float size = 4 * sizeof(float);
	_matrialAmbient = (float*)malloc(size);
	_matrialDiffuse = (float*)malloc(size);
	_matrialSpecular = (float*)malloc(size);
	_matrialEmission = (float*)malloc(size);

	memset(_matrialAmbient, 0, size);

	_matrialAmbient[0] = 0.2f;
	_matrialAmbient[1] = 0.2f;
	_matrialAmbient[2] = 0.2f;
	_matrialAmbient[3] = 1.0f;

	_matrialDiffuse[0] = 0.8f;
	_matrialDiffuse[1] = 0.8f;
	_matrialDiffuse[2] = 0.8f;
	_matrialDiffuse[3] = 1.0f;

	_matrialSpecular[0] = 1.0f;
	_matrialSpecular[1] = 1.0f;
	_matrialSpecular[2] = 1.0f;
	_matrialSpecular[3] = 1.0f;


	_matrialShiness = 1.0f;

	_matrialEmission[0] = 1.0f;
	_matrialEmission[1] = 1.0f;
	_matrialEmission[2] = 1.0f;
	_matrialEmission[3] = 1.0f;
}

Material::~Material()
{
	free(_matrialAmbient);
	free(_matrialDiffuse);
	free(_matrialSpecular);
	free(_matrialEmission);
}

void Material::applyDefault()
{
	float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float matrialShiness = 0.0f;
	float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	G_DRAWCOMMANDER->addCommand(DCMaterial::create(matrialAmbient, matrialDiffuse, matrialSpecular, matrialShiness, matrialEmission));
}

void Material::apply()
{
	G_DRAWCOMMANDER->addCommand(DCMaterial::create(_matrialAmbient, _matrialDiffuse, _matrialSpecular, _matrialShiness, _matrialEmission));
}

void Material::setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialAmbient[0] = red / COLOR_FLOAT_VALUE;
	_matrialAmbient[1] = green / COLOR_FLOAT_VALUE;
	_matrialAmbient[2] = blue / COLOR_FLOAT_VALUE;
	_matrialAmbient[3] = alpha / COLOR_FLOAT_VALUE;
}

void Material::setAmbient(float red, float green, float blue, float alpha)
{
	_matrialAmbient[0] = red;
	_matrialAmbient[1] = green;
	_matrialAmbient[2] = blue;
	_matrialAmbient[3] = alpha;
}

void Material::setDiffuse(float red, float green, float blue, float alpha)
{
	_matrialDiffuse[0] = red;
	_matrialDiffuse[1] = green;
	_matrialDiffuse[2] = blue;
	_matrialDiffuse[3] = alpha;
}

void Material::setSpecular(float red, float green, float blue, float alpha)
{
	_matrialSpecular[0] = red;
	_matrialSpecular[1] = green;
	_matrialSpecular[2] = blue;
	_matrialSpecular[3] = alpha;
}

void Material::setEmisiion(float red, float green, float blue, float alpha)
{
	_matrialEmission[0] = red;
	_matrialEmission[1] = green;
	_matrialEmission[2] = blue;
	_matrialEmission[3] = alpha;
}

const float* Material::getAmbient() const
{
	return _matrialAmbient;
}

void Material::setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialDiffuse[0] = red / COLOR_FLOAT_VALUE;
	_matrialDiffuse[1] = green / COLOR_FLOAT_VALUE;
	_matrialDiffuse[2] = blue / COLOR_FLOAT_VALUE;
	_matrialDiffuse[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* Material::getDiffuse() const
{
	return _matrialDiffuse;
}

void Material::setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialSpecular[0] = red / COLOR_FLOAT_VALUE;
	_matrialSpecular[1] = green / COLOR_FLOAT_VALUE;
	_matrialSpecular[2] = blue / COLOR_FLOAT_VALUE;
	_matrialSpecular[3] = alpha / COLOR_FLOAT_VALUE;
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

void Material::setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialEmission[0] = red / COLOR_FLOAT_VALUE;
	_matrialEmission[1] = green / COLOR_FLOAT_VALUE;
	_matrialEmission[2] = blue / COLOR_FLOAT_VALUE;
	_matrialEmission[3] = alpha / COLOR_FLOAT_VALUE;
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

void Material::setName(const std::string& name)
{
	_name = name;
}

const std::string& Material::getName()
{
	return _name;
}

const std::string& Material::getTexture1()
{
	return _texture1;
}

void Material::setTexture1(const std::string& name)
{
	_texture1 = name;
}

const std::string& Material::getTexture2()
{
	return _texture2;
}

void Material::setTexture2(const std::string& name)
{
	_texture2 = name;
}
