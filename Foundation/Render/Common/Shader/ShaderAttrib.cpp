#include "ShaderAttrib.h"
#include "ext-config.h"

using namespace render;


ShaderAttrib::ShaderAttrib()
{

}

ShaderAttrib::~ShaderAttrib()
{

}


void ShaderAttrib::showAttribs()
{
	int value = 0;

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING : %d", value);

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_ENABLED, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_ENABLED : %d", value);

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_SIZE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_SIZE : %d", value);

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_STRIDE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_STRIDE : %d", value);

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_TYPE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_TYPE : %d", value);

	glGetVertexAttribiv(getVarID(), GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_NORMALIZED : %d", value);

	SHOW_OPENGL_ERROR_MESSAGE();
}

void ShaderAttrib::setValue(int len, const double* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1dv(getVarID(), v);
	if (len == 2) glVertexAttrib2dv(getVarID(), v);
	if (len == 3) glVertexAttrib3dv(getVarID(), v);
	if (len == 4) glVertexAttrib4dv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const float* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1fv(getVarID(), v);
	if (len == 2) glVertexAttrib2fv(getVarID(), v);
	if (len == 3) glVertexAttrib3fv(getVarID(), v);
	if (len == 4) glVertexAttrib4fv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const uint32_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4uiv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const int32_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4Niv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const uint16_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4usv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const int16_t* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1sv(getVarID(), v);
	if (len == 2) glVertexAttrib2sv(getVarID(), v);
	if (len == 3) glVertexAttrib3sv(getVarID(), v);
	if (len == 4) glVertexAttrib4sv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const uint8_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4ubv(getVarID(), v);
}

void ShaderAttrib::setValue(int len, const int8_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4Nbv(getVarID(), v);
}

void ShaderAttrib::setValue(double v0)
{
	glVertexAttrib1d(getVarID(), v0);
}

void ShaderAttrib::setValue(double v0, double v1)
{
	glVertexAttrib2d(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(double v0, double v1, double v2)
{
	glVertexAttrib3d(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(double v0, double v1, double v2, double v3)
{
	glVertexAttrib4d(getVarID(), v0, v1, v2, v3);
}

void ShaderAttrib::setValue(float v0)
{
	glVertexAttrib1f(getVarID(), v0);
}

void ShaderAttrib::setValue(float v0, float v1)
{
	glVertexAttrib2f(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(float v0, float v1, float v2)
{
	glVertexAttrib3f(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(float v0, float v1, float v2, float v3)
{
	glVertexAttrib4f(getVarID(), v0, v1, v2, v3);
}

void ShaderAttrib::setValue(uint16_t v0)
{
	glVertexAttrib1s(getVarID(), v0);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1)
{
	glVertexAttrib2s(getVarID(), v0, v1);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2)
{
	glVertexAttrib3s(getVarID(), v0, v1, v2);
}

void ShaderAttrib::setValue(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3)
{
	glVertexAttrib4s(getVarID(), v0, v1, v2, v3);
}
