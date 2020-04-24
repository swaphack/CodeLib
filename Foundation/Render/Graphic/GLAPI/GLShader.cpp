#include "GLShader.h"
#include "macros.h"
using namespace render;

uint32_t GLShader::createShader(ShaderType type)
{
	return glCreateShader((GLenum)type);
}

void GLShader::deleteShader(uint32_t shader)
{
	glDeleteShader(shader);
}

void GLShader::loadShader(uint32_t shader, const char* data)
{
	glShaderSource(shader, 1, &data, nullptr);
	compileShader(shader);

	int compiled = 0;
	glGetProgramiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE)
	{
		showShaderStatus(shader);
	}
}

void GLShader::attachShader(uint32_t program, uint32_t shader)
{
	glAttachShader(program, shader);
}

void GLShader::detachShader(uint32_t program, uint32_t shader)
{
	glDetachShader(program, shader);
}

void GLShader::showShaderStatus(uint32_t shader)
{
	GLsizei bufferSize = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetShaderInfoLog(shader, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

uint32_t GLShader::createProgram()
{
	return glCreateProgram();
}

void GLShader::deleteProgram(uint32_t program)
{
	glDeleteProgram(program);
}

void GLShader::linkProgram(uint32_t program)
{
	glLinkProgram(program);

	int linkStatus = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		showProgramStatus(program);
	}
}

void GLShader::useProgram(uint32_t program)
{
	glUseProgram(program);
}

void GLShader::showProgramStatus(uint32_t program)
{
	GLsizei bufferSize = 0;
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetProgramInfoLog(program, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

int GLShader::getAttrib(uint32_t program, const char* attribName)
{
	return glGetAttribLocation(program, attribName);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const double* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1dv(attribID, v);
	if (len == 2) glVertexAttrib2dv(attribID, v);
	if (len == 3) glVertexAttrib3dv(attribID, v);
	if (len == 4) glVertexAttrib4dv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const float* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1fv(attribID, v);
	if (len == 2) glVertexAttrib2fv(attribID, v);
	if (len == 3) glVertexAttrib3fv(attribID, v);
	if (len == 4) glVertexAttrib4fv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const uint32_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4uiv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const int32_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4Niv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const uint16_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4usv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const int16_t* v)
{
	ASSERT(len != 0 && v != nullptr);

	if (len == 1) glVertexAttrib1sv(attribID, v);
	if (len == 2) glVertexAttrib2sv(attribID, v);
	if (len == 3) glVertexAttrib3sv(attribID, v);
	if (len == 4) glVertexAttrib4sv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const uint8_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4ubv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, int len, const int8_t* v)
{
	ASSERT(len == 4 && v != nullptr);

	glVertexAttrib4Nbv(attribID, v);
}

void GLShader::setAttribValue(uint32_t attribID, double v0)
{
	glVertexAttrib1d(attribID, v0);
}

void GLShader::setAttribValue(uint32_t attribID, double v0, double v1)
{
	glVertexAttrib2d(attribID, v0, v1);
}

void GLShader::setAttribValue(uint32_t attribID, double v0, double v1, double v2)
{
	glVertexAttrib3d(attribID, v0, v1, v2);
}

void GLShader::setAttribValue(uint32_t attribID, double v0, double v1, double v2, double v3)
{
	glVertexAttrib4d(attribID, v0, v1, v2, v3);
}

void GLShader::setAttribValue(uint32_t attribID, float v0)
{
	glVertexAttrib1f(attribID, v0);
}

void GLShader::setAttribValue(uint32_t attribID, float v0, float v1)
{
	glVertexAttrib2f(attribID, v0, v1);
}

void GLShader::setAttribValue(uint32_t attribID, float v0, float v1, float v2)
{
	glVertexAttrib3f(attribID, v0, v1, v2);
}

void GLShader::setAttribValue(uint32_t attribID, float v0, float v1, float v2, float v3)
{
	glVertexAttrib4f(attribID, v0, v1, v2, v3);
}

void GLShader::setAttribValue(uint32_t attribID, uint16_t v0)
{
	glVertexAttrib1s(attribID, v0);
}

void GLShader::setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1)
{
	glVertexAttrib2s(attribID, v0, v1);
}

void GLShader::setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2)
{
	glVertexAttrib3s(attribID, v0, v1, v2);
}

void GLShader::setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3)
{
	glVertexAttrib4s(attribID, v0, v1, v2, v3);
}

void GLShader::setAttribValue(uint32_t attribID, float* value)
{
	ASSERT(value != nullptr);

	glVertexAttribPointer(attribID, 1, GL_FLOAT, GL_FALSE, 0, value);
}

void GLShader::setAttribValue(uint32_t attribID, uint16_t* value)
{
	ASSERT(value != nullptr);

	glVertexAttribPointer(attribID, 1, GL_UNSIGNED_SHORT, GL_FALSE, 0, value);
}

int GLShader::getUniform(int32_t program, const char* uniformName)
{
	return glGetUniformLocation(program, uniformName);
}

void GLShader::setUniformValue(int32_t uniformID, int type, int len, float* v)
{
	ASSERT(type != 0 && len > 0 && v != nullptr);

	if (type == 1) glUniform1fv(uniformID, len, v);
	if (type == 2) glUniform2fv(uniformID, len, v);
	if (type == 3) glUniform3fv(uniformID, len, v);
	if (type == 4) glUniform4fv(uniformID, len, v);
}

void GLShader::setUniformValue(int32_t uniformID, int type, int len, int32_t* v)
{
	ASSERT(type != 0 && len > 0 && v != nullptr);

	if (type == 1) glUniform1iv(uniformID, len, v);
	if (type == 2) glUniform1iv(uniformID, len, v);
	if (type == 3) glUniform1iv(uniformID, len, v);
	if (type == 4) glUniform1iv(uniformID, len, v);
}

void GLShader::setUniformValue(int32_t uniformID, float v0)
{
	glUniform1f(uniformID, v0);
}

void GLShader::setUniformValue(int32_t uniformID, float v0, float v1)
{
	glUniform2f(uniformID, v0, v1);
}

void GLShader::setUniformValue(int32_t uniformID, float v0, float v1, float v2)
{
	glUniform3f(uniformID, v0, v1, v2);
}

void GLShader::setUniformValue(int32_t uniformID, float v0, float v1, float v2, float v3)
{
	glUniform4f(uniformID, v0, v1, v2, v3);
}

void GLShader::setUniformValue(int32_t uniformID, int32_t v0)
{
	glUniform1i(uniformID, v0);
}

void GLShader::setUniformValue(int32_t uniformID, int32_t v0, int32_t v1)
{
	glUniform2i(uniformID, v0, v1);
}

void GLShader::setUniformValue(int32_t uniformID, int32_t v0, int32_t v1, int32_t v2)
{
	glUniform3i(uniformID, v0, v1, v2);
}

void GLShader::setUniformValue(int32_t uniformID, int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	glUniform4i(uniformID, v0, v1, v2, v3);
}

void GLShader::setUniformMatrix2(int32_t uniformID, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(uniformID, count, transpose, value);
}

void GLShader::setUniformMatrix3(int32_t uniformID, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(uniformID, count, transpose, value);
}

void GLShader::setUniformMatrix4(int32_t uniformID, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(uniformID, count, transpose, value);
}

void GLShader::showAttribStatus(uint32_t attribID)
{
	int value = 0;

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING : %d", value);

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_ENABLED : %d", value);

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_SIZE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_SIZE : %d", value);

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_STRIDE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_STRIDE : %d", value);

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_TYPE, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_TYPE : %d", value);

	glGetVertexAttribiv(attribID, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED, &value);
	PRINT("GL_VERTEX_ATTRIB_ARRAY_NORMALIZED : %d", value);
}

void render::GLShader::bindAttributeLocation(uint32_t program, uint32_t index, const char* name)
{
	glBindAttribLocation(program, index, name);
}

void render::GLShader::bindFragDataLocation(uint32_t program, uint32_t colorNumber, const char* name)
{
	glBindFragDataLocation(program, colorNumber, name);
}

void render::GLShader::bindFragDataLocationIndexed(uint32_t program, uint32_t colorNumber, uint32_t index, const char* name)
{
	glBindFragDataLocationIndexed(program, colorNumber, index, name);
}

void render::GLShader::compileShader(uint32_t shader)
{
	glCompileShader(shader);
}

void render::GLShader::getActiveAtomicCounterBuffer(uint32_t program, uint32_t bufferIndex, AtomicCounterBufferName name, int* params)
{
	glGetActiveAtomicCounterBufferiv(program, bufferIndex, (GLenum)name, params);
}

void render::GLShader::getActiveAttrib(uint32_t program, uint32_t index, int bufSize, int *length, int *size, AttribType *type, char *name)
{
	uint32_t* data = new uint32_t[*size];
	for (int i = 0; i < (*size); i++)
	{
		data[i] = (GLenum)type[i];
	}
	glGetActiveAttrib(program, index, bufSize, length, size, data, name);

	delete data;
}

void render::GLShader::getActiveSubroutineName(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int *length, char *name)
{
	glGetActiveSubroutineName(program, (GLenum)shaderType, index, bufSize, length, name);
}

void GLShader::createShaderProgram(ShaderType type, int size, const char** strings)
{
	glCreateShaderProgramv((GLenum)type, size, strings);
}

