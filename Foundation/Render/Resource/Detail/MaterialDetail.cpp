#include "MaterialDetail.h"
#include "ext-config.h"
#include "Graphic/import.h"

using namespace	render;

MaterialDetail::MaterialDetail()
{
	size_t size = 4 * sizeof(float);
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

	_matrialSpecular[0] = 0.0f;
	_matrialSpecular[1] = 0.0f;
	_matrialSpecular[2] = 0.0f;
	_matrialSpecular[3] = 0.0f;


	_matrialShiness = 0.0f;

	_matrialEmission[0] = 0.0f;
	_matrialEmission[1] = 0.0f;
	_matrialEmission[2] = 0.0f;
	_matrialEmission[3] = 1.0f;
}

MaterialDetail::~MaterialDetail()
{
	free(_matrialAmbient);
	free(_matrialDiffuse);
	free(_matrialSpecular);
	free(_matrialEmission);
}

void MaterialDetail::applyDefault()
{
	static float matrialAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	static float matrialDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	static float matrialSpecular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	static float matrialShiness = 0.0f;
	static float matrialEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	GLMaterial::setMaterialAmbient(FaceType::FRONT, matrialAmbient);
	GLMaterial::setMaterialDiffuse(FaceType::FRONT, matrialDiffuse);
	GLMaterial::setMaterialSpecular(FaceType::FRONT, matrialSpecular);
	GLMaterial::setMaterialShininess(FaceType::FRONT, matrialShiness);
	GLMaterial::setMaterialEmission(FaceType::FRONT, matrialEmission);
}

void MaterialDetail::apply()
{
	GLMaterial::setMaterialAmbient(FaceType::FRONT, _matrialAmbient);
	GLMaterial::setMaterialDiffuse(FaceType::FRONT, _matrialDiffuse);
	GLMaterial::setMaterialSpecular(FaceType::FRONT, _matrialSpecular);
	GLMaterial::setMaterialShininess(FaceType::FRONT, _matrialShiness);
	GLMaterial::setMaterialEmission(FaceType::FRONT, _matrialEmission);
}

void MaterialDetail::setAmbientByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialAmbient[0] = red / COLOR_FLOAT_VALUE;
	_matrialAmbient[1] = green / COLOR_FLOAT_VALUE;
	_matrialAmbient[2] = blue / COLOR_FLOAT_VALUE;
	_matrialAmbient[3] = alpha / COLOR_FLOAT_VALUE;
}

void MaterialDetail::setAmbient(float red, float green, float blue, float alpha)
{
	_matrialAmbient[0] = red;
	_matrialAmbient[1] = green;
	_matrialAmbient[2] = blue;
	_matrialAmbient[3] = alpha;
}

void MaterialDetail::setDiffuse(float red, float green, float blue, float alpha)
{
	_matrialDiffuse[0] = red;
	_matrialDiffuse[1] = green;
	_matrialDiffuse[2] = blue;
	_matrialDiffuse[3] = alpha;
}

void MaterialDetail::setSpecular(float red, float green, float blue, float alpha)
{
	_matrialSpecular[0] = red;
	_matrialSpecular[1] = green;
	_matrialSpecular[2] = blue;
	_matrialSpecular[3] = alpha;
}

void MaterialDetail::setEmisiion(float red, float green, float blue, float alpha)
{
	_matrialEmission[0] = red;
	_matrialEmission[1] = green;
	_matrialEmission[2] = blue;
	_matrialEmission[3] = alpha;
}

const float* MaterialDetail::getAmbient() const
{
	return _matrialAmbient;
}

void MaterialDetail::setDiffuseByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialDiffuse[0] = red / COLOR_FLOAT_VALUE;
	_matrialDiffuse[1] = green / COLOR_FLOAT_VALUE;
	_matrialDiffuse[2] = blue / COLOR_FLOAT_VALUE;
	_matrialDiffuse[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getDiffuse() const
{
	return _matrialDiffuse;
}

void MaterialDetail::setSpecularByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialSpecular[0] = red / COLOR_FLOAT_VALUE;
	_matrialSpecular[1] = green / COLOR_FLOAT_VALUE;
	_matrialSpecular[2] = blue / COLOR_FLOAT_VALUE;
	_matrialSpecular[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getSpecular() const
{
	return _matrialSpecular;
}

void MaterialDetail::setShiness(float value)
{
	_matrialShiness = value;
}

float MaterialDetail::getShiness() const
{
	return _matrialShiness;
}

void MaterialDetail::setEmisiionByte(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	_matrialEmission[0] = red / COLOR_FLOAT_VALUE;
	_matrialEmission[1] = green / COLOR_FLOAT_VALUE;
	_matrialEmission[2] = blue / COLOR_FLOAT_VALUE;
	_matrialEmission[3] = alpha / COLOR_FLOAT_VALUE;
}

const float* MaterialDetail::getEmisiion() const
{
	return _matrialEmission;
}

MaterialDetail& MaterialDetail::operator = (const MaterialDetail& value)
{
	memcpy(_matrialAmbient, (float*)value.getAmbient(), sizeof(_matrialAmbient));
	memcpy(_matrialDiffuse, (float*)value.getDiffuse(), sizeof(_matrialDiffuse));
	memcpy(_matrialSpecular, (float*)value.getSpecular(), sizeof(_matrialSpecular));
	memcpy(_matrialEmission, (float*)value.getEmisiion(), sizeof(_matrialEmission));

	_matrialShiness = value.getShiness();

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
void MaterialDetail::setSpecularHightlightMap(const std::string& name)
{
	_mapSpecularHightlight = name;
}

const std::string& MaterialDetail::getSpecularHightlightMap()
{
	return _mapSpecularHightlight;
}

void MaterialDetail::setAlphaTextureMap(const std::string& name)
{
	_mapTextureAlpha = name;
}

const std::string& MaterialDetail::getAlphaTextureMap()
{
	return _mapTextureAlpha;
}

void MaterialDetail::setBumpMap(const std::string& name)
{
	_mapBump = name;
}

const std::string& MaterialDetail::getBumpMap()
{
	return _mapBump;
}
