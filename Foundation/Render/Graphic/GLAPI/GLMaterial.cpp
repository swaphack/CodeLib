#include "GLMaterial.h"

using namespace render;

void GLMaterial::getMaterial(GetMaterialFace face, MaterialParameter parameter, float* value)
{
	glGetMaterialfv((GLenum)face, (GLenum)parameter, value);
}

void GLMaterial::setMaterial(FaceType face, MaterialParameter type, const float* value)
{
	glMaterialfv((GLenum)face, (GLenum)type, value);
}

void GLMaterial::setMaterialAmbient(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::AMBIENT, value);
}

void GLMaterial::setMaterialDiffuse(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::DIFFUSE, value);
}

void GLMaterial::setMaterialSpecular(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::SPECULAR, value);
}

void GLMaterial::setMaterialEmission(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::EMISSION, value);
}

void GLMaterial::setMaterialShininess(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::SHININESS, value);
}

void GLMaterial::setMaterialAmbientAndDiffuse(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::AMBIENT_AND_DIFFUSE, value);
}

void GLMaterial::setMaterialColorIndexes(FaceType face, const float* value)
{
	setMaterial(face, MaterialParameter::COLOR_INDEXES, value);
}

void GLMaterial::setMaterialColorIndexes(FaceType face, const math::Vector3& value)
{
	setMaterialColorIndexes(face, value.getValue());
}

void GLMaterial::setMaterialAmbientAndDiffuse(FaceType face, const math::Vector4& value)
{
	setMaterialAmbientAndDiffuse(face, value.getValue());
}

void GLMaterial::setMaterialShininess(FaceType face, float value)
{
	setMaterialShininess(face, &value);
}

void GLMaterial::setMaterialEmission(FaceType face, const math::Vector4& value)
{
	setMaterialEmission(face, value.getValue());
}

void GLMaterial::setMaterialSpecular(FaceType face, const math::Vector4& value)
{
	setMaterialSpecular(face, value.getValue());
}

void GLMaterial::setMaterialDiffuse(FaceType face, const math::Vector4& value)
{
	setMaterialDiffuse(face, value.getValue());
}

void GLMaterial::setMaterialAmbient(FaceType face, const math::Vector4& value)
{
	setMaterialAmbient(face, value.getValue());
}

void GLMaterial::setColorMaterial(FaceType face, ColorMaterialParameter type)
{
	glColorMaterial((GLenum)face, (GLenum)type);
}
