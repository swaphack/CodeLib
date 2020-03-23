#include "ShaderUniform.h"
#include "ext-config.h"
#include "ShaderProgram.h"

using namespace render;

ShaderUniform::ShaderUniform()
{

}

ShaderUniform::~ShaderUniform()
{

}

void ShaderUniform::showUniforms()
{
	if (getProgram() == nullptr)
	{
		return;
	}
	float value[16] = { 0 };
	glGetUniformfv(getProgram()->getProgramID(), getVarID(), value);
	PRINT("glGetUniformfv :");
	for (int i = 0; i < 16; i++)
	{
		PRINT("%f,", value);
	}
	PRINT("\n");
}

void ShaderUniform::setValue(int type, int len, float* v)
{
	ASSERT(type != 0 && len > 0 && v != nullptr);

	if (type == 1) glUniform1fv(getVarID(), len, v);
	if (type == 2) glUniform2fv(getVarID(), len, v);
	if (type == 3) glUniform3fv(getVarID(), len, v);
	if (type == 4) glUniform4fv(getVarID(), len, v);
}

void ShaderUniform::setValue(int type, int len, int32_t* v)
{
	ASSERT(type != 0 && len > 0 && v != nullptr);

	if (type == 1) glUniform1iv(getVarID(), len, v);
	if (type == 2) glUniform1iv(getVarID(), len, v);
	if (type == 3) glUniform1iv(getVarID(), len, v);
	if (type == 4) glUniform1iv(getVarID(), len, v);
}

void ShaderUniform::setValue(float v0)
{
	glUniform1f(getVarID(), v0);
}

void ShaderUniform::setValue(float v0, float v1)
{
	glUniform2f(getVarID(), v0, v1);
}

void ShaderUniform::setValue(float v0, float v1, float v2)
{
	glUniform3f(getVarID(), v0, v1, v2);
}

void ShaderUniform::setValue(float v0, float v1, float v2, float v3)
{
	glUniform4f(getVarID(), v0, v1, v2, v3);
}

void ShaderUniform::setValue(int32_t v0)
{
	glUniform1i(getVarID(), v0);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1)
{
	glUniform2i(getVarID(), v0, v1);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2)
{
	glUniform3i(getVarID(), v0, v1, v2);
}

void ShaderUniform::setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	glUniform4i(getVarID(), v0, v1, v2, v3);
}

void ShaderUniform::setMatrix2(int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(getVarID(), count, transpose, value);
}

void ShaderUniform::setMatrix3(int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(getVarID(), count, transpose, value);
}

void ShaderUniform::setMatrix4(int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(getVarID(), count, transpose, value);
}

