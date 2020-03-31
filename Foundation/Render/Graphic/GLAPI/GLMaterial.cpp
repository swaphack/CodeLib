#include "GLMaterial.h"

using namespace render;

void GLMaterial::setMaterial(MaterialFace face, MaterialParameter type, const float* value)
{
	glMaterialfv((GLenum)face, (GLenum)type, value);
}

void GLMaterial::setMaterialAmbient(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::AMBIENT, value);
}

void GLMaterial::setMaterialDiffuse(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::DIFFUSE, value);
}

void GLMaterial::setMaterialSpecular(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::SPECULAR, value);
}

void GLMaterial::setMaterialEmission(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::EMISSION, value);
}

void GLMaterial::setMaterialShininess(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::SHININESS, value);
}

void GLMaterial::setMaterialAmbientAndDiffuse(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::AMBIENT_AND_DIFFUSE, value);
}

void GLMaterial::setMaterialColorIndexes(MaterialFace face, const float* value)
{
	setMaterial(face, MaterialParameter::COLOR_INDEXES, value);
}

void GLMaterial::setMaterialColorIndexes(MaterialFace face, const math::Vector3& value)
{
	setMaterialColorIndexes(face, value.getValue());
}

void GLMaterial::setMaterialAmbientAndDiffuse(MaterialFace face, const math::Vector4& value)
{
	setMaterialAmbientAndDiffuse(face, value.getValue());
}

void GLMaterial::setMaterialShininess(MaterialFace face, float value)
{
	setMaterialShininess(face, &value);
}

void GLMaterial::setMaterialEmission(MaterialFace face, const math::Vector4& value)
{
	setMaterialEmission(face, value.getValue());
}

void GLMaterial::setMaterialSpecular(MaterialFace face, const math::Vector4& value)
{
	setMaterialSpecular(face, value.getValue());
}

void GLMaterial::setMaterialDiffuse(MaterialFace face, const math::Vector4& value)
{
	setMaterialDiffuse(face, value.getValue());
}

void GLMaterial::setMaterialAmbient(MaterialFace face, const math::Vector4& value)
{
	setMaterialAmbient(face, value.getValue());
}

void GLMaterial::setColorMaterial(ColorMaterialFace face, ColorMaterialParameter type)
{
	glColorMaterial((GLenum)face, (GLenum)type);
}
