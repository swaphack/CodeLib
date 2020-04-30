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
void ShaderUniform::setValue(VertexAttribSize type, int len, float* v)
{
	GLShader::setUniformValue(getVarID(), type, len, v);
}

void ShaderUniform::setValue(VertexAttribSize type, int len, int32_t* v)
{
	GLShader::setUniformValue(getVarID(), type, len, v);
}

void ShaderUniform::setValue(float v0)
{
	GLShader::setUniformValue(getVarID(), v0);
}

void ShaderUniform::setValue(float v0, float v1)
{
	GLShader::setUniformValue(getVarID(), v0, v1);
}

void ShaderUniform::setValue(float v0, float v1, float v2)
{
	GLShader::setUniformValue(getVarID(), v0, v1, v2);
}

void ShaderUniform::setValue(float v0, float v1, float v2, float v3)
{
	GLShader::setUniformValue(getVarID(), v0, v1, v2, v3);
}

void ShaderUniform::setValue(int32_t v0)
{
	GLShader::setUniformValue(getVarID(), v0);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1)
{
	GLShader::setUniformValue(getVarID(), v0, v1);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2)
{
	GLShader::setUniformValue(getVarID(), v0, v1, v2);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	GLShader::setUniformValue(getVarID(), v0, v1, v2, v3);
}

void ShaderUniform::setMatrix2(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix2(getVarID(), count, transpose, value);
}

void ShaderUniform::setMatrix3(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix3(getVarID(), count, transpose, value);
}

void ShaderUniform::setMatrix4(int count, bool transpose, const float* value)
{
	GLShader::setUniformMatrix4(getVarID(), count, transpose, value);
}

