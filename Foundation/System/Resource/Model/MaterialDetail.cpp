#include "MaterialDetail.h"
#include "../extensions.h"
#include "Light/ColorSample.h"
using namespace	sys;

MaterialDetail::MaterialDetail()
{
	_ambientColor[0] = 1.0f;
	_ambientColor[1] = 1.0f;
	_ambientColor[2] = 1.0f;
	_ambientColor[3] = 1.0f;

	_diffuseColor[0] = 0.8f;
	_diffuseColor[1] = 0.8f;
	_diffuseColor[2] = 0.8f;
	_diffuseColor[3] = 1.0f;

	_specularColor[0] = 1.0f;
	_specularColor[1] = 1.0f;
	_specularColor[2] = 1.0f;
	_specularColor[3] = 1.0f;


	_specularShiness = 32.0f;

	_specularStrength = 16;

	_emissionColor[0] = 1.0f;
	_emissionColor[1] = 1.0f;
	_emissionColor[2] = 1.0f;
	_emissionColor[3] = 1.0f;
}

MaterialDetail::~MaterialDetail()
{
}

void MaterialDetail::setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_ambientColor[0] = red / COLOR_FLOAT_VALUE;
	_ambientColor[1] = green / COLOR_FLOAT_VALUE;
	_ambientColor[2] = blue / COLOR_FLOAT_VALUE;
	_ambientColor[3] = alpha / COLOR_FLOAT_VALUE;
}

void MaterialDetail::setAmbient(float red, float green, float blue, float alpha)
{
	_ambientColor[0] = red;
	_ambientColor[1] = green;
	_ambientColor[2] = blue;
	_ambientColor[3] = alpha;
}

void MaterialDetail::setDiffuse(float red, float green, float blue, float alpha)
{
	_diffuseColor[0] = red;
	_diffuseColor[1] = green;
	_diffuseColor[2] = blue;
	_diffuseColor[3] = alpha;
}

void MaterialDetail::setSpecular(float red, float green, float blue, float alpha)
{
	_specularColor[0] = red;
	_specularColor[1] = green;
	_specularColor[2] = blue;
	_specularColor[3] = alpha;
}

void MaterialDetail::setEmission(float red, float green, float blue, float alpha)
{
	_emissionColor[0] = red;
	_emissionColor[1] = green;
	_emissionColor[2] = blue;
	_emissionColor[3] = alpha;
}

const float* MaterialDetail::getAmbient() const
{
	return _ambientColor;
}

void MaterialDetail::setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_diffuseColor[0] = red / COLOR_FLOAT_VALUE;
	_diffuseColor[1] = green / COLOR_FLOAT_VALUE;
	_diffuseColor[2] = blue / COLOR_FLOAT_VALUE;
	_diffuseColor[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getDiffuse() const
{
	return _diffuseColor;
}

void MaterialDetail::setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_specularColor[0] = red / COLOR_FLOAT_VALUE;
	_specularColor[1] = green / COLOR_FLOAT_VALUE;
	_specularColor[2] = blue / COLOR_FLOAT_VALUE;
	_specularColor[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getSpecular() const
{
	return _specularColor;
}

void MaterialDetail::setSpecularShiness(float value)
{
	_specularShiness = value;
}

float MaterialDetail::getSpecularShiness() const
{
	return _specularShiness;
}

void MaterialDetail::setEmissionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_emissionColor[0] = red / COLOR_FLOAT_VALUE;
	_emissionColor[1] = green / COLOR_FLOAT_VALUE;
	_emissionColor[2] = blue / COLOR_FLOAT_VALUE;
	_emissionColor[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getEmission() const
{
	return _emissionColor;
}

MaterialDetail& MaterialDetail::operator = (const MaterialDetail& value)
{
	memcpy(_ambientColor, (float*)value.getAmbient(), sizeof(_ambientColor));
	memcpy(_diffuseColor, (float*)value.getDiffuse(), sizeof(_diffuseColor));
	memcpy(_specularColor, (float*)value.getSpecular(), sizeof(_specularColor));
	memcpy(_emissionColor, (float*)value.getEmission(), sizeof(_emissionColor));

	_specularShiness = value.getSpecularShiness();

	return *this;
}

void MaterialDetail::setName(const std::string& name)
{
	_name = name;
}

const std::string& MaterialDetail::getName()
{
	return _name;
}

const std::string& MaterialDetail::getAmbientTextureMap()
{
	return _mapTextureAmbient;
}

void MaterialDetail::setAmbientTextureMap(const std::string& name)
{
	_mapTextureAmbient = name;
}

const std::string& MaterialDetail::getDiffuseTextureMap()
{
	return _mapTextureDiffuse;
}

void MaterialDetail::setDiffuseTextureMap(const std::string& name)
{
	_mapTextureDiffuse = name;
}

void MaterialDetail::setSpecularTextureMap(const std::string& name)
{
	_mapTextureSpecular = name;
}

const std::string& MaterialDetail::getSpecularTextureMap()
{
	return _mapTextureSpecular;
}

void MaterialDetail::setAlphaTextureMap(const std::string& name)
{
	_mapTextureAlpha = name;
}

const std::string& MaterialDetail::getAlphaTextureMap()
{
	return _mapTextureAlpha;
}

void MaterialDetail::setBumpTextureMap(const std::string& name)
{
	_mapTextureBump = name;
}

const std::string& MaterialDetail::getBumpTextureMap()
{
	return _mapTextureBump;
}

void sys::MaterialDetail::setSpecularStrength(float value)
{
	_specularStrength = value;
}

float sys::MaterialDetail::getSpecularStrength() const
{
	return _specularStrength;
}
