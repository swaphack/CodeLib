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

void ShaderAttrib::setValue(int len, const double* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const float* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const uint32_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const int32_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const uint16_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const int16_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const uint8_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(int len, const int8_t* v)
{
	GLShader::setAttribValue(getVarID(), len, v);
}

void ShaderAttrib::setValue(double v0)
{
	GLShader::setAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(double v0, double v1)
{
	GLShader::setAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(double v0, double v1, double v2)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(double v0, double v1, double v2, double v3)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(float v0)
{
	GLShader::setAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(float v0, float v1)
{
	GLShader::setAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(float v0, float v1, float v2)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(float v0, float v1, float v2, float v3)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(uint16_t v0)
{
	GLShader::setAttribValue(getVarID(), v0);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1)
{
	GLShader::setAttribValue(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3)
{
	GLShader::setAttribValue(getVarID(), v0, v1, v3);
}

void ShaderAttrib::setValue(float* value)
{
	GLShader::setAttribValue(getVarID(), value);
}

void ShaderAttrib::setValue(uint16_t* value)
{
	GLShader::setAttribValue(getVarID(), value);
}
