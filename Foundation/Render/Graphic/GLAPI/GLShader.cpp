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

void GLShader::createShaderProgram(ShaderType type, int size, const char** strings)
{
	glCreateShaderProgramv((GLenum)type, size, strings);
}

void GLShader::attachShader(uint32_t program, uint32_t shader)
{
	glAttachShader(program, shader);
}

void GLShader::detachShader(uint32_t program, uint32_t shader)
{
	glDetachShader(program, shader);
}

void GLShader::showShaderError(uint32_t shader)
{
	GLsizei bufferSize = 0;
	getShader(shader, ShaderParameter::INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		getShaderInfoLog(shader, bufferSize, nullptr, buffer);
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
}

void GLShader::useProgram(uint32_t program)
{
	glUseProgram(program);
}

void GLShader::showProgramError(uint32_t program)
{
	GLsizei bufferSize = 0;
	getProgram(program, GetProgramParameter::INFO_LOG_LENGTH, &bufferSize);
	if (bufferSize > 0)
	{
		GLchar* buffer = new char[bufferSize];
		getProgramInfoLog(program, bufferSize, NULL, buffer);
		PRINT("%s", buffer);
		delete[] buffer;
	}
}

void GLShader::setVertexAttribValue(uint32_t attribID, VertexAttribSize type, const double* v)
{
	if (type == VertexAttribSize::ONE) glVertexAttrib1dv(attribID, v);
	if (type == VertexAttribSize::TWO) glVertexAttrib2dv(attribID, v);
	if (type == VertexAttribSize::THREE) glVertexAttrib3dv(attribID, v);
	if (type == VertexAttribSize::FOUR) glVertexAttrib4dv(attribID, v);
}

void GLShader::setVertexAttribValue(uint32_t attribID, VertexAttribSize type, const float* v)
{
	if (type == VertexAttribSize::ONE) glVertexAttrib1fv(attribID, v);
	if (type == VertexAttribSize::TWO) glVertexAttrib2fv(attribID, v);
	if (type == VertexAttribSize::THREE) glVertexAttrib3fv(attribID, v);
	if (type == VertexAttribSize::FOUR)  glVertexAttrib4fv(attribID, v);
}

void GLShader::setVertexAttribValue4(uint32_t attribID, const uint32_t* v)
{
	glVertexAttrib4uiv(attribID, v);
}

void GLShader::setVertexAttribValue4(uint32_t attribID, const int32_t* v)
{
	glVertexAttrib4Niv(attribID, v);
}

void GLShader::setVertexAttribValue4(uint32_t attribID, const uint16_t* v)
{
	glVertexAttrib4usv(attribID, v);
}

void GLShader::setVertexAttribValue(uint32_t attribID, VertexAttribSize type, const int16_t* v)
{
	if (type == VertexAttribSize::ONE) glVertexAttrib1sv(attribID, v);
	if (type == VertexAttribSize::TWO)  glVertexAttrib2sv(attribID, v);
	if (type == VertexAttribSize::THREE) glVertexAttrib3sv(attribID, v);
	if (type == VertexAttribSize::FOUR)  glVertexAttrib4sv(attribID, v);
}

void GLShader::setVertexAttribValue4(uint32_t attribID, const uint8_t* v)
{
	glVertexAttrib4ubv(attribID, v);
}

void GLShader::setVertexAttribValue4(uint32_t attribID, const int8_t* v)
{
	glVertexAttrib4Nbv(attribID, v);
}

void GLShader::setVertexAttribValue(uint32_t attribID, double v0)
{
	glVertexAttrib1d(attribID, v0);
}

void GLShader::setVertexAttribValue(uint32_t attribID, double v0, double v1)
{
	glVertexAttrib2d(attribID, v0, v1);
}

void GLShader::setVertexAttribValue(uint32_t attribID, double v0, double v1, double v2)
{
	glVertexAttrib3d(attribID, v0, v1, v2);
}

void GLShader::setVertexAttribValue(uint32_t attribID, double v0, double v1, double v2, double v3)
{
	glVertexAttrib4d(attribID, v0, v1, v2, v3);
}

void GLShader::setVertexAttribValue(uint32_t attribID, float v0)
{
	glVertexAttrib1f(attribID, v0);
}

void GLShader::setVertexAttribValue(uint32_t attribID, float v0, float v1)
{
	glVertexAttrib2f(attribID, v0, v1);
}

void GLShader::setVertexAttribValue(uint32_t attribID, float v0, float v1, float v2)
{
	glVertexAttrib3f(attribID, v0, v1, v2);
}

void GLShader::setVertexAttribValue(uint32_t attribID, float v0, float v1, float v2, float v3)
{
	glVertexAttrib4f(attribID, v0, v1, v2, v3);
}

void GLShader::setVertexAttribValue(uint32_t attribID, uint16_t v0)
{
	glVertexAttrib1s(attribID, v0);
}

void GLShader::setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1)
{
	glVertexAttrib2s(attribID, v0, v1);
}

void GLShader::setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2)
{
	glVertexAttrib3s(attribID, v0, v1, v2);
}

void GLShader::setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3)
{
	glVertexAttrib4s(attribID, v0, v1, v2, v3);
}

void GLShader::setVertexAttribValue(uint32_t attribID, float* value)
{
	ASSERT(value != nullptr);

	glVertexAttribPointer(attribID, 1, GL_FLOAT, GL_FALSE, 0, value);
}

void GLShader::setVertexAttribValue(uint32_t attribID, uint16_t* value)
{
	ASSERT(value != nullptr);

	glVertexAttribPointer(attribID, 1, GL_UNSIGNED_SHORT, GL_FALSE, 0, value);
}

int GLShader::getUniformLocation(int32_t program, const char* uniformName)
{
	return glGetUniformLocation(program, uniformName);
}

void GLShader::setUniformValue(int32_t uniformID, VertexAttribSize type, int len, float* v)
{
	if (type == VertexAttribSize::ONE) glUniform1fv(uniformID, len, v);
	if (type == VertexAttribSize::TWO) glUniform2fv(uniformID, len, v);
	if (type == VertexAttribSize::THREE) glUniform3fv(uniformID, len, v);
	if (type == VertexAttribSize::FOUR) glUniform4fv(uniformID, len, v);
}

void GLShader::setUniformValue(int32_t uniformID, VertexAttribSize type, int len, int32_t* v)
{
	if (type == VertexAttribSize::ONE) glUniform1iv(uniformID, len, v);
	if (type == VertexAttribSize::TWO) glUniform2iv(uniformID, len, v);
	if (type == VertexAttribSize::THREE) glUniform3iv(uniformID, len, v);
	if (type == VertexAttribSize::FOUR) glUniform4iv(uniformID, len, v);
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
	glUniformMatrix2fv(uniformID, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setUniformMatrix3(int32_t uniformID, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(uniformID, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setUniformMatrix4(int32_t uniformID, int count, bool transpose, const float* value)
{
	glUniformMatrix2fv(uniformID, count, transpose ? GL_TRUE : GL_FALSE, value);
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

void GLShader::setProgramUniformValue(uint32_t program, int location, float v0)
{
	glProgramUniform1f(program, location, v0);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, VertexAttribSize type, int count, const float* value)
{
	if (type == VertexAttribSize::ONE) glProgramUniform1fv(program, location, count, value);
	if (type == VertexAttribSize::TWO) glProgramUniform2fv(program, location, count, value);
	if (type == VertexAttribSize::THREE) glProgramUniform3fv(program, location, count, value);
	if (type == VertexAttribSize::FOUR) glProgramUniform4fv(program, location, count, value);
}

void GLShader::setProgramUniformMatrix2(uint32_t program, int location, int count, const float* value)
{
	glProgramUniform2fv(program, location, count, value);
}

void GLShader::setProgramUniformMatrix3(uint32_t program, int location, int count, const float* value)
{
	glProgramUniform3fv(program, location, count, value);
}

void GLShader::setProgramUniformMatrix4(uint32_t program, int location, int count, const float* value)
{
	glProgramUniform4fv(program, location, count, value);
}

void GLShader::setProgramUniformMatrix2x3(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix2x3fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformMatrix3x2(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix3x2fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformMatrix2x4(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix2x4fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformMatrix4x2(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix4x2fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformMatrix3x4(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix3x4fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformMatrix4x3(uint32_t program, int location, int count, bool transpose, const float* value)
{
	glProgramUniformMatrix4x3fv(program, location, count, transpose ? GL_TRUE : GL_FALSE, value);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, VertexAttribSize type, int count, const uint32_t* value)
{
	if (type == VertexAttribSize::ONE) glProgramUniform1uiv(program, location, count, value);
	if (type == VertexAttribSize::TWO) glProgramUniform2uiv(program, location, count, value);
	if (type == VertexAttribSize::THREE) glProgramUniform3uiv(program, location, count, value);
	if (type == VertexAttribSize::FOUR) glProgramUniform4uiv(program, location, count, value);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, VertexAttribSize type, int count, const int32_t* value)
{
	if(type == VertexAttribSize::ONE) glProgramUniform1iv(program, location, count, value);
	if (type == VertexAttribSize::TWO) glProgramUniform2iv(program, location, count, value);
	if (type == VertexAttribSize::THREE) glProgramUniform3iv(program, location, count, value);
	if (type == VertexAttribSize::FOUR) glProgramUniform4iv(program, location, count, value);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
	glProgramUniform4ui(program, location, v0, v1, v2, v3);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1, uint32_t v2)
{
	glProgramUniform3ui(program, location, v0, v1, v2);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1)
{
	glProgramUniform2ui(program, location, v0, v1);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, uint32_t v0)
{
	glProgramUniform1ui(program, location, v0);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1, int32_t v2, int32_t v3)
{
	glProgramUniform4i(program, location, v0, v1, v2, v3);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1, int32_t v2)
{
	glProgramUniform3i(program, location, v0, v1, v2);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1)
{
	glProgramUniform2i(program, location, v0, v1);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, int32_t v0)
{
	glProgramUniform1i(program, location, v0);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, float v0, float v1, float v2, float v3)
{
	glProgramUniform4f(program, location, v0, v1, v2, v3);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, float v0, float v1, float v2)
{
	glProgramUniform3f(program, location, v0, v1, v2);
}

void GLShader::setProgramUniformValue(uint32_t program, int location, float v0, float v1)
{
	glProgramUniform2f(program, location, v0, v1);
}

void GLShader::getUniformValue(uint32_t program, int location, int* params)
{
	glGetUniformiv(program, location, params);
}

void GLShader::getUniformValue(uint32_t program, int location, int bufSize, float* params)
{
	glGetnUniformfv(program, location, bufSize, params);
}

void GLShader::getUniformValue(uint32_t program, int location, int bufSize, uint32_t* params)
{
	glGetnUniformuiv(program, location, bufSize, params);
}

void GLShader::getUniformValue(uint32_t program, int location, int bufSize, int* params)
{
	glGetnUniformiv(program, location, bufSize, params);
}

void GLShader::getUniformValue(uint32_t program, int location, float* params)
{
	glGetUniformfv(program, location, params);
}

void GLShader::getUniformValue(uint32_t program, int location, uint32_t* params)
{
	glGetUniformuiv(program, location, params);
}

void GLShader::bindAttributeLocation(uint32_t program, uint32_t index, const char* name)
{
	glBindAttribLocation(program, index, name);
}

void GLShader::bindFragDataLocation(uint32_t program, uint32_t colorNumber, const char* name)
{
	glBindFragDataLocation(program, colorNumber, name);
}

void GLShader::bindFragDataLocationIndexed(uint32_t program, uint32_t colorNumber, uint32_t index, const char* name)
{
	glBindFragDataLocationIndexed(program, colorNumber, index, name);
}

void GLShader::compileShader(uint32_t shader)
{
	glCompileShader(shader);
}

void GLShader::getActiveAtomicCounterBuffer(uint32_t program, uint32_t bufferIndex, AtomicCounterBufferName name, int* params)
{
	glGetActiveAtomicCounterBufferiv(program, bufferIndex, (GLenum)name, params);
}

void GLShader::getActiveAttrib(uint32_t program, uint32_t index, int bufSize, int *length, int *size, AttribType *type, char *name)
{
	uint32_t* data = new uint32_t[*size];
	for (int i = 0; i < (*size); i++)
	{
		data[i] = (GLenum)type[i];
	}
	glGetActiveAttrib(program, index, bufSize, length, size, data, name);

	delete[] data;
}

void GLShader::getActiveSubroutineName(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int *length, char *name)
{
	glGetActiveSubroutineName(program, (GLenum)shaderType, index, bufSize, length, name);
}

void GLShader::getActiveSubroutineUniform(uint32_t program, ShaderType shaderType, uint32_t index, SubroutineUniformParameter pname, int *values)
{
	glGetActiveSubroutineUniformiv(program, (GLenum)shaderType, index, (GLenum)pname, values);
}

void GLShader::getActiveSubroutineUniformName(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int* length, char *name)
{
	glGetActiveSubroutineUniformName(program, (GLenum)shaderType, index, bufSize, length, name);
}

void GLShader::getActiveUniform(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int* length, int* size, uint32_t* type, char *name)
{
	glGetActiveUniform(program, index, bufSize, length, size, type, name);
}

void GLShader::getActiveUniformBlock(uint32_t program, uint32_t uniformBlockIndex, UniformBlockParameter pname, int* params)
{
	glGetActiveUniformBlockiv(program, uniformBlockIndex, (GLenum)pname, params);
}

void GLShader::getActiveUniformBlockName(uint32_t program, uint32_t uniformBlockIndex, int bufSize, int* length, char *name)
{
	glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, name);
}

void GLShader::getActiveUniformName(uint32_t program, uint32_t uniformIndex, int bufSize, int* length, char *name)
{
	glGetActiveUniformName(program, uniformIndex, bufSize, length, name);
}

void GLShader::getActiveUniforms(uint32_t program, int uniformCount, const uint32_t* uniformIndices, UniformParameter pname, int* params)
{
	glGetActiveUniformsiv(program, uniformCount, uniformIndices, (GLenum)pname, params);
}

void GLShader::getAttachedShaders(uint32_t program, int maxCount, int* count, uint32_t* shaders)
{
	glGetAttachedShaders(program, maxCount, count, shaders);
}

int GLShader::getAttribLocation(uint32_t program, const char* name)
{
	return glGetAttribLocation(program, name);
}

int GLShader::getFragDataIndex(uint32_t program, const char* name)
{
	return glGetFragDataIndex(program, name);
}

int GLShader::getFragDataLocation(uint32_t program, const char* name)
{
	return glGetFragDataLocation(program, name);
}

void GLShader::getProgram(uint32_t program, GetProgramParameter pname, int* params)
{
	glGetProgramiv(program, (GLenum)pname, params);
}

void GLShader::getProgramBinary(uint32_t program, int bufSize, int* length, uint32_t* binaryFormat, void* binary)
{
	glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
}

void GLShader::getProgramInfoLog(uint32_t program, int maxLength, int* length, char* infoLog)
{
	glGetProgramInfoLog(program, maxLength, length, infoLog);
}

void GLShader::getProgramResource(uint32_t program, ProgramResourceInterface programInterface, uint32_t index, int proCount, const uint32_t* props, int bufSize, int* length, int* params)
{
	glGetProgramResourceiv(program, (GLenum)programInterface, index, proCount, props, bufSize, length, params);
}

void GLShader::getProgramResourceIndex(uint32_t program, ProgramResourceIndexInterface programInterface, const char* name)
{
	glGetProgramResourceIndex(program, (GLenum)programInterface, name);
}

void GLShader::getProgramResourceLocation(uint32_t program, ProgramResourceLocationInterface programInterface, const char* name)
{
	glGetProgramResourceLocation(program, (GLenum)programInterface, name);
}

void GLShader::getProgramResourceLocationIndex(uint32_t program, ProgramResourceLocationIndexInterface programInterface, const char* name)
{
	glGetProgramResourceLocationIndex(program, (GLenum)programInterface, name);
}

void GLShader::getProgramResourceName(uint32_t program, ProgramResourceNameInterface programInterface, uint32_t index, int bufSize, int* length, char* name)
{
	glGetProgramResourceName(program, (GLenum)programInterface, index, bufSize, length, name);
}

void GLShader::getProgramStage(uint32_t program, ShaderType type, ProgramStageParameter pname, int* values)
{
	glGetProgramStageiv(program, (GLenum)type, (GLenum)pname, values);
}

void GLShader::getShader(uint32_t shader, ShaderParameter parameter, int* params)
{
	glGetShaderiv(shader, (GLenum)parameter, params);
}

void GLShader::getShaderInfoLog(uint32_t shader, int maxLength, int* length, char* infoLog)
{
	glGetShaderInfoLog(shader, maxLength, length, infoLog);
}

void GLShader::getShaderPrecisionFormat(ShaderType type, ShaderPrecisionType precisionType, int* range, int* precision)
{
	glGetShaderPrecisionFormat((GLenum)type, (GLenum)precisionType, range, precision);
}

void GLShader::getShaderSource(uint32_t shader, int bufSize, int* length, char* source)
{
	glGetShaderSource(shader, bufSize, length, source);
}

uint32_t GLShader::getSubroutineIndex(uint32_t program, ShaderType type, const char* name)
{
	return glGetSubroutineIndex(program, (GLenum)type, name);
}

int32_t GLShader::getSubroutineUniformLocation(uint32_t program, ShaderType type, const char* name)
{
	return glGetSubroutineUniformLocation(program, (GLenum)type,  name);
}

uint32_t GLShader::getUniformBlockIndex(uint32_t program, const char* uniformBlockName)
{
	return glGetUniformBlockIndex(program, uniformBlockName);
}

void GLShader::getUniformIndices(uint32_t program, int uniformCount, const char** uniformNames, uint32_t* uniformIndices)
{
	glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}

void GLShader::getUniformSubroutine(ShaderType type, int location, uint32_t* values)
{
	glGetUniformSubroutineuiv((GLenum)type, location, values);
}

bool GLShader::isProgram(uint32_t program)
{
	return glIsProgram(program) == GL_TRUE;
}

bool GLShader::isShader(uint32_t shader)
{
	return glIsShader(shader) == GL_TRUE;
}

void GLShader::setMinSampleShading(float value)
{
	glMinSampleShading(value);
}

void GLShader::setProgramBinary(uint32_t program, GLenum binaryFormat, const void* binary, int length)
{
	glProgramBinary(program, binaryFormat, binary, length);
}

void GLShader::setProgramParameter(uint32_t program, ModifyProgramParameter pname, int value)
{
	glProgramParameteri(program, (GLenum)pname, value);
}

void GLShader::releaseShaderCompiler()
{
	glReleaseShaderCompiler();
}

void GLShader::setShaderBinary(int count, const uint32_t* shaders, GLenum binaryFormat, const void* binary, int length)
{
	glShaderBinary(count, shaders, binaryFormat, binary, length);
}

void GLShader::setShaderSource(uint32_t shader, int count, const char** string, const int* length)
{
	glShaderSource(shader, count, string, length);
}

void GLShader::setShaderStorageBlockBinding(uint32_t program, uint32_t storageBlockIndex, uint32_t storageBlockBinding)
{
	glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
}

void GLShader::setUniformBlockBinding(uint32_t program, uint32_t uniformBlockIndex, uint32_t uniformBlockBinding)
{
	glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}

void GLShader::setUniformSubroutines(ShaderType type, int count, const uint32_t* indices)
{
	glUniformSubroutinesuiv((GLenum)type, count, indices);
}

void GLShader::useProgramStages(uint32_t pipeline, uint32_t stages, uint32_t program)
{
	glUseProgramStages(pipeline, stages, program);
}

void GLShader::validateProgram(uint32_t program)
{
	glValidateProgram(program);
}

size_t render::GLShader::getTypeSize(AttribType type)
{
	size_t size;

#define CASE(Enum, Count, Type)\
	case Enum: size = Count * sizeof(Type); break;

	switch (type)
	{
		CASE(AttribType::BOOL, 1, GLboolean);
		CASE(AttribType::FLOAT, 1, GLfloat); 
		CASE(AttribType::FLOAT_VEC2, 2, GLfloat); 
		CASE(AttribType::FLOAT_VEC3, 3, GLfloat); 
		CASE(AttribType::FLOAT_VEC4, 4, GLfloat); 
		CASE(AttribType::FLOAT_MAT2, 2 * 2, GLfloat);
		CASE(AttribType::FLOAT_MAT3, 3 * 3, GLfloat);
		CASE(AttribType::FLOAT_MAT4, 4 * 4, GLfloat);
		CASE(AttribType::FLOAT_MAT2x3, 2 * 3, GLfloat);
		CASE(AttribType::FLOAT_MAT2x4, 2 * 4, GLfloat);
		CASE(AttribType::FLOAT_MAT3x2, 3 * 2, GLfloat);
		CASE(AttribType::FLOAT_MAT3x4, 3 * 4, GLfloat);
		CASE(AttribType::FLOAT_MAT4x2, 4 * 2, GLfloat);
		CASE(AttribType::FLOAT_MAT4x3, 4 * 3, GLfloat);
		CASE(AttribType::INT, 1, GLint);
		CASE(AttribType::INT_VEC2, 2, GLint);
		CASE(AttribType::INT_VEC3, 3, GLint);
		CASE(AttribType::INT_VEC4, 4, GLint);
		CASE(AttribType::UNSIGNED_INT, 1, GLuint);
		CASE(AttribType::UNSIGNED_INT_VEC2, 2, GLuint);
		CASE(AttribType::UNSIGNED_INT_VEC3, 3, GLuint);
		CASE(AttribType::UNSIGNED_INT_VEC4, 4, GLuint);
		CASE(AttribType::DOUBLE, 1, GLdouble);
		CASE(AttribType::DOUBLE_VEC2, 2, GLdouble);
		CASE(AttribType::DOUBLE_VEC3, 3, GLdouble);
		CASE(AttribType::DOUBLE_VEC4, 4, GLdouble);
		CASE(AttribType::DOUBLE_MAT2, 2 * 2, GLdouble);
		CASE(AttribType::DOUBLE_MAT3, 3 * 3, GLdouble);
		CASE(AttribType::DOUBLE_MAT4, 4 * 4, GLdouble);
		CASE(AttribType::DOUBLE_MAT2x3, 2 * 3, GLdouble);
		CASE(AttribType::DOUBLE_MAT2x4, 2 * 4, GLdouble);
		CASE(AttribType::DOUBLE_MAT3x2, 3 * 2, GLdouble);
		CASE(AttribType::DOUBLE_MAT3x4, 3 * 4, GLdouble);
		CASE(AttribType::DOUBLE_MAT4x2, 4 * 2, GLdouble);
		CASE(AttribType::DOUBLE_MAT4x3, 4 * 3, GLdouble);
	default:
		break;
	}

	return size;
}

void render::GLShader::setAttribPointer(uint32_t index, int size, VertexAttribPointerDataType type, bool normalized, int stride, const void *pointer)
{
	glVertexAttribPointer(index, size, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, stride, pointer);
}

