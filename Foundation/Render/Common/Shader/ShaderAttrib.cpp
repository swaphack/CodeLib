#include "ShaderAttrib.h"
#include "Graphic/GLAPI/GLShader.h"

using namespace render;


ShaderAttrib::ShaderAttrib()
{

}

ShaderAttrib::~ShaderAttrib()
{

}


void ShaderAttrib::showAttribs()
{
	
}

void ShaderAttrib::setValue(VertexAttribSize len, const double* v)
{
	GLShader::setVertexAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(VertexAttribSize len, const float* v)
{
	GLShader::setVertexAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue4(const uint32_t* v)
{
	GLShader::setVertexAttribValue4(getVarID(), v);
}

void ShaderAttrib::setValue4(const int32_t* v)
{
	GLShader::setVertexAttribValue4(getVarID(), v);
}

void ShaderAttrib::setValue4(const uint16_t* v)
{
	GLShader::setVertexAttribValue4(getVarID(), v);
}

void ShaderAttrib::setValue(VertexAttribSize len, const int16_t* v)
{
	GLShader::setVertexAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue4(const uint8_t* v)
{
	GLShader::setVertexAttribValue4(getVarID(), v);
}

void ShaderAttrib::setValue4(const int8_t* v)
{
	GLShader::setVertexAttribValue4(getVarID(), v);
}

void ShaderAttrib::setValue(double v0)
{
	GLShader::setVertexAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(double v0, double v1)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(double v0, double v1, double v2)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(double v0, double v1, double v2, double v3)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(float v0)
{
	GLShader::setVertexAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(float v0, float v1)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(float v0, float v1, float v2)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(float v0, float v1, float v2, float v3)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(uint16_t v0)
{
	GLShader::setVertexAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3)
{
	GLShader::setVertexAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(float* value)
{
	GLShader::setVertexAttribValue(getVarID(), value);
}

void ShaderAttrib::setValue(uint16_t* value)
{
	GLShader::setVertexAttribValue(getVarID(), value);
}
