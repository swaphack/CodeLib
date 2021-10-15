#include "MaterialDetail.h"
#include "../extensions.h"
#include "physicslib.h"
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

	_emissionColor[0] = 0.0f;
	_emissionColor[1] = 0.0f;
	_emissionColor[2] = 0.0f;
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

const std::string& MaterialDetail::getName() const
{
	return _name;
}

void sys::MaterialDetail::setTexture(const std::string& name)
{
	_ambientTextureMap = name;
}

const std::string& sys::MaterialDetail::getTexture() const
{
	return _ambientTextureMap;
}

const std::string& MaterialDetail::getAmbientTextureMap() const
{
	return _ambientTextureMap;
}

void MaterialDetail::setAmbientTextureMap(const std::string& name)
{
	_ambientTextureMap = name;
}

const std::string& MaterialDetail::getDiffuseTextureMap() const
{
	return _diffuseTextureMap;
}

void MaterialDetail::setDiffuseTextureMap(const std::string& name)
{
	_diffuseTextureMap = name;
}

void MaterialDetail::setSpecularTextureMap(const std::string& name)
{
	_specularTextureMap = name;
}

const std::string& MaterialDetail::getSpecularTextureMap() const
{
	return _specularTextureMap;
}

void MaterialDetail::setAlphaTextureMap(const std::string& name)
{
	_alphaTextureMap = name;
}

const std::string& MaterialDetail::getAlphaTextureMap() const
{
	return _alphaTextureMap;
}

void MaterialDetail::setBumpTextureMap(const std::string& name)
{
	_bumpTextureMap = name;
}

const std::string& MaterialDetail::getBumpTextureMap() const
{
	return _bumpTextureMap;
}

void sys::MaterialDetail::setNormalTextureMap(const std::string& name)
{
	_normalTextureMap = name;
}

const std::string& sys::MaterialDetail::getNormalTextureMap() const
{
	return _normalTextureMap;
}

void sys::MaterialDetail::setShadowTextureMap(const std::string& name)
{
	_shadowTextureMap = name;
}

const std::string& sys::MaterialDetail::getShadowTextureMap() const
{
	return _shadowTextureMap;
}

void sys::MaterialDetail::setSpecularStrength(float value)
{
	_specularStrength = value;
}

float sys::MaterialDetail::getSpecularStrength() const
{
	return _specularStrength;
}

bool sys::MaterialDetail::equals(const MaterialDetail& detail)
{
	return memcmp(_ambientColor, detail.getAmbient(), sizeof(_ambientColor)) == 0
		&& memcmp(_diffuseColor, detail.getDiffuse(), sizeof(_diffuseColor)) == 0
		&& memcmp(_specularColor, detail.getSpecular(), sizeof(_specularColor)) == 0
		&& _specularShiness == detail.getSpecularShiness()
		&& _specularStrength == detail.getSpecularStrength()
		&& memcmp(_emissionColor, detail.getEmission(), sizeof(_emissionColor)) == 0
		&& _ambientTextureMap == detail.getAmbientTextureMap()
		&& _diffuseTextureMap == detail.getDiffuseTextureMap()
		&& _specularTextureMap == detail.getSpecularTextureMap()
		&& _alphaTextureMap == detail.getAlphaTextureMap()
		&& _bumpTextureMap == detail.getBumpTextureMap()
		&& _normalTextureMap == detail.getNormalTextureMap()
		&& _shadowTextureMap == detail.getShadowTextureMap();
}
