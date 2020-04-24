#include "GLShader.h"
#include "macros.h"
using namespace render;

uint32_t GLShader::createShader(ShaderType type)
{
	return glCreateShader((GLenum)type);
}

void GLShader::deleteShader(uint32_t shaderID)
{
	glDeleteShader(shaderID);
}

void GLShader::loadShader(uint32_t shaderID, const char* data)
{
	glShaderSource(shaderID, 1, &data, nullptr);
	glCompileShader(shaderID);

	int compiled = 0;
	glGetProgramiv(shaderID, GL_COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE)
	{
		showShaderStatus(shaderID);
	}
}

void GLShader::attachShader(uint32_t programID, uint32_t shaderID)
{
	glAttachShader(programID, shaderID);
}

void GLShader::detachShader(uint32_t programID, uint32_t shaderID)
{
	glDetachShader(programID, shaderID);
}

void GLShader::showShaderStatus(uint32_t shaderID)
{
	GLsizei bufferSize = 0;
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetShaderInfoLog(shaderID, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

uint32_t GLShader::createProgram()
{
	return glCreateProgram();
}

void GLShader::deleteProgram(uint32_t programID)
{
	glDeleteProgram(programID);
}

void GLShader::linkProgram(uint32_t programID)
{
	glLinkProgram(programID);

	int linkStatus = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		showProgramStatus(programID);
	}
}

void GLShader::useProgram(uint32_t programID)
{
	glUseProgram(programID);
}

void GLShader::showProgramStatus(uint32_t programID)
{
	GLsizei bufferSize = 0;
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		glGetProgramInfoLog(programID, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

int GLShader::getAttrib(uint32_t programID, const char* attribName)
{
	return glGetAttribLocation(programID, attribName);
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

int GLShader::getUniform(int32_t programID, const char* uniformName)
{
	return glGetUniformLocation(programID, uniformName);
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

void GLShader::createShaderProgram(ShaderType type, int size, const char** strings)
{
	glCreateShaderProgramv((GLenum)type, size, strings);
}

