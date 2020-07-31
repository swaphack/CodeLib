#include "ShaderUniform.h"
#include "Graphic/GLAPI/GLShader.h"
#include "ShaderProgram.h"

using namespace render;

ShaderUniform::ShaderUniform()
{

}

ShaderUniform::~ShaderUniform()
{

}
void ShaderUniform::setValue1(int len, const float* v)
{
	GLShader::setUniformValue1(getUniformID(), len, v);
}

void ShaderUniform::setValue2(int len, const float* v)
{
	GLShader::setUniformValue2(getUniformID(), len, v);
}

void ShaderUniform::setValue3(int len, const float* v)
{
	GLShader::setUniformValue3(getUniformID(), len, v);
}

void ShaderUniform::setValue4(int len, const float* v)
{
	GLShader::setUniformValue4(getUniformID(), len, v);
}

void ShaderUniform::setValue1(int len, const int32_t* v)
{
	GLShader::setUniformValue1(getUniformID(), len, v);
}

void ShaderUniform::setValue2(int len, const int32_t* v)
{
	GLShader::setUniformValue2(getUniformID(), len, v);
}

void ShaderUniform::setValue3(int len, const int32_t* v)
{
	GLShader::setUniformValue3(getUniformID(), len, v);
}

void ShaderUniform::setValue4(int len, const int32_t* v)
{
	GLShader::setUniformValue4(getUniformID(), len, v);
}

void ShaderUniform::setValue(float v0)
{
	GLShader::setUniformValue(getUniformID(), v0);
}

void ShaderUniform::setValue(float v0, float v1)
{
	GLShader::setUniformValue(getUniformID(), v0, v1);
}

void ShaderUniform::setValue(float v0, float v1, float v2)
{
	GLShader::setUniformValue(getUniformID(), v0, v1, v2);
}

void ShaderUniform::setValue(float v0, float v1, float v2, float v3)
{
	GLShader::setUniformValue(getUniformID(), v0, v1, v2, v3);
}

void ShaderUniform::setValue(int32_t v0)
{
	GLShader::setUniformValue(getUniformID(), v0);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1)
{
	GLShader::setUniformValue(getUniformID(), v0, v1);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2)
{
	GLShader::setUniformValue(getUniformID(), v0, v1, v2);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	GLShader::setUniformValue(getUniformID(), v0, v1, v2, v3);
}

void ShaderUniform::setMatrix2(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix2(getUniformID(), count, transpose, value);
}

void ShaderUniform::setMatrix3(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix3(getUniformID(), count, transpose, value);
}

void ShaderUniform::setMatrix4(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix4(getUniformID(), count, transpose, value);
}

void render::ShaderUniform::setUniformID(uint32_t id)
{
	_uniformID = id;
}

uint32_t render::ShaderUniform::getUniformID()
{
	return _uniformID;
}

void render::ShaderUniform::setValue(uint32_t v0)
{
	GLShader::setUniformValue(getUniformID(), (int32_t)v0);
}

void render::ShaderUniform::setMatrix2(bool transpose, const float* value)
{
	this->setMatrix2(1, transpose, value);
}

void render::ShaderUniform::setMatrix3(const float* value)
{
	this->setMatrix3(false, value);
}

void render::ShaderUniform::setMatrix4(const math::Matrix4x4& value)
{
	this->setMatrix4(value.getValue());
}

void render::ShaderUniform::setMatrix4(const float* value)
{
	this->setMatrix4(false, value);
}

void render::ShaderUniform::setMatrix2(const math::Matrix2x2& value)
{
	this->setMatrix2(value.getValue());
}

void render::ShaderUniform::setMatrix3(const math::Matrix3x3& value)
{
	this->setMatrix3(value.getValue());
}

void render::ShaderUniform::setMatrix3(bool transpose, const float* value)
{
	this->setMatrix3(1, transpose, value);
}

void render::ShaderUniform::setMatrix4(bool transpose, const float* value)
{
	this->setMatrix4(1, transpose, value);
}

void render::ShaderUniform::setMatrix2(const float* value)
{
	this->setMatrix2(false, value);
}

