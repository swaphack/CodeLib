#include "ShaderProgramUniform.h"
#include "Graphic/import.h"

using namespace render;

render::ShaderProgramUniform::ShaderProgramUniform()
{

}

render::ShaderProgramUniform::~ShaderProgramUniform()
{

}

void render::ShaderProgramUniform::setProgramUniformID(uint32_t id)
{
	_programUniformID = id;
}

uint32_t render::ShaderProgramUniform::getProgramUniformID()
{
	return _programUniformID;
}

void render::ShaderProgramUniform::setMatrix2(int count, const float* value)
{
	GLShader::setProgramUniformMatrix2(getProgramID(), getProgramUniformID(), count, value);
}

void render::ShaderProgramUniform::setMatrix3(int count, const float* value)
{
	GLShader::setProgramUniformMatrix2(getProgramID(), getProgramUniformID(), count, value);
}

void render::ShaderProgramUniform::setMatrix4(int count, const float* value)
{
	GLShader::setProgramUniformMatrix4(getProgramID(), getProgramUniformID(), count, value);
}

void render::ShaderProgramUniform::setMatrix2x3(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix2x3(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setMatrix3x2(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix3x2(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setMatrix2x4(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix2x4(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setMatrix4x2(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix4x2(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setMatrix3x4(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix3x4(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setMatrix4x3(int count, bool transpose, const float* value)
{
	GLShader::setProgramUniformMatrix4x3(getProgramID(), getProgramUniformID(), count, transpose, value);
}

void render::ShaderProgramUniform::setValue(VertexAttribSize type, int len, const int32_t* v)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), type, len, v);
}

void render::ShaderProgramUniform::setValue(VertexAttribSize type, int count, const uint32_t* value)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), type, count, value);
}

void render::ShaderProgramUniform::setValue(VertexAttribSize type, int count, const float* value)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), type, count, value);
}

void render::ShaderProgramUniform::setValue(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2, v3);
}

void render::ShaderProgramUniform::setValue(uint32_t v0, uint32_t v1, uint32_t v2)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2);
}

void render::ShaderProgramUniform::setValue(uint32_t v0, uint32_t v1)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1);
}

void render::ShaderProgramUniform::setValue(uint32_t v0)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0);
}

void render::ShaderProgramUniform::setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2, v3);
}

void render::ShaderProgramUniform::setValue(int32_t v0, int32_t v1, int32_t v2)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2);
}

void render::ShaderProgramUniform::setValue(int32_t v0, int32_t v1)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1);
}

void render::ShaderProgramUniform::setValue(int32_t v0)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0);
}

void render::ShaderProgramUniform::setValue(float v0, float v1, float v2, float v3)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2, v3);
}

void render::ShaderProgramUniform::setValue(float v0, float v1, float v2)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1, v2);
}

void render::ShaderProgramUniform::setValue(float v0, float v1)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0, v1);
}

void render::ShaderProgramUniform::setValue(float v0)
{
	GLShader::setProgramUniformValue(getProgramID(), getProgramUniformID(), v0);
}


