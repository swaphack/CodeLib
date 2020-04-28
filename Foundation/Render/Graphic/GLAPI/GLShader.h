#pragma once

#include "macros.h"

namespace render
{
	/**
	*	×ÅÉ«Æ÷
	*/
	class GLShader
	{
	public:
		static void loadShader(uint32_t shader, const char* data);
		static void attachShader(uint32_t program, uint32_t shader);
		
		static void showShaderStatus(uint32_t shader);
	public:		
		static void linkProgram(uint32_t program);
		static void useProgram(uint32_t program);
		static void showProgramStatus(uint32_t program);
	public:
		static void setVertexAttribValue(uint32_t attribID, VertexAttribSize len, const double* v);
		static void setVertexAttribValue(uint32_t attribID, VertexAttribSize len, const float* v);
		static void setVertexAttribValue4(uint32_t attribID, const uint32_t* v);
		static void setVertexAttribValue4(uint32_t attribID, const int32_t* v);
		static void setVertexAttribValue4(uint32_t attribID, const uint16_t* v);
		static void setVertexAttribValue(uint32_t attribID, VertexAttribSize len, const int16_t* v);
		static void setVertexAttribValue4(uint32_t attribID, const uint8_t* v);
		static void setVertexAttribValue4(uint32_t attribID, const int8_t* v);

		static void setVertexAttribValue(uint32_t attribID, double v0);
		static void setVertexAttribValue(uint32_t attribID, double v0, double v1);
		static void setVertexAttribValue(uint32_t attribID, double v0, double v1, double v2);
		static void setVertexAttribValue(uint32_t attribID, double v0, double v1, double v2, double v3);

		static void setVertexAttribValue(uint32_t attribID, float v0);
		static void setVertexAttribValue(uint32_t attribID, float v0, float v1);
		static void setVertexAttribValue(uint32_t attribID, float v0, float v1, float v2);
		static void setVertexAttribValue(uint32_t attribID, float v0, float v1, float v2, float v3);

		static void setVertexAttribValue(uint32_t attribID, uint16_t v0);
		static void setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1);
		static void setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2);
		static void setVertexAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3);

		static void setVertexAttribValue(uint32_t attribID, float* value);
		static void setVertexAttribValue(uint32_t attribID, uint16_t* value);
		static void setAttribPointer(uint32_t index, int size, VertexAttribPointerDataType type, bool normalized, int stride, const void *pointer);
		static void showAttribStatus(uint32_t attribID);
	public:
		static int getUniformLocation(int32_t program, const char* uniformName);

		static void setUniformValue(int32_t uniformID, int type, int len, float* v);
		static void setUniformValue(int32_t uniformID, int type, int len, int32_t* v);
		 
		static void setUniformValue(int32_t uniformID, float v0);
		static void setUniformValue(int32_t uniformID, float v0, float v1);
		static void setUniformValue(int32_t uniformID, float v0, float v1, float v2);
		static void setUniformValue(int32_t uniformID, float v0, float v1, float v2, float v3);
		 
		static void setUniformValue(int32_t uniformID, int32_t v0);
		static void setUniformValue(int32_t uniformID, int32_t v0, int32_t v1);
		static void setUniformValue(int32_t uniformID, int32_t v0, int32_t v1, int32_t v2);
		static void setUniformValue(int32_t uniformID, int32_t v0, int32_t v1, int32_t v2, int32_t v3);
		 
		static void setUniformMatrix2(int32_t uniformID, int count, bool transpose, const float* value);
		static void setUniformMatrix3(int32_t uniformID, int count, bool transpose, const float* value);
		static void setUniformMatrix4(int32_t uniformID, int count, bool transpose, const float* value);
	public:
		static void setProgramUniformValue(uint32_t program, int location, float v0);
		static void setProgramUniformValue(uint32_t program, int location, float v0, float v1);
		static void setProgramUniformValue(uint32_t program, int location, float v0, float v1, float v2);
		static void setProgramUniformValue(uint32_t program, int location, float v0, float v1, float v2, float v3);
																 
		static void setProgramUniformValue(uint32_t program, int location, int32_t v0);
		static void setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1);
		static void setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1, int32_t v2);
		static void setProgramUniformValue(uint32_t program, int location, int32_t v0, int32_t v1, int32_t v2, int32_t v3);
																 
		static void setProgramUniformValue(uint32_t program, int location, uint32_t v0);
		static void setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1);
		static void setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1, uint32_t v2);
		static void setProgramUniformValue(uint32_t program, int location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3);

		static void setProgramUniformValue1(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformValue2(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformValue3(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformValue4(uint32_t program, int location, int count, const float* value);
																  
		static void setProgramUniformValue1(uint32_t program, int location, int count, const int32_t* value);
		static void setProgramUniformValue2(uint32_t program, int location, int count, const int32_t* value);
		static void setProgramUniformValue3(uint32_t program, int location, int count, const int32_t* value);
		static void setProgramUniformValue4(uint32_t program, int location, int count, const int32_t* value);
																  
		static void setProgramUniformValue1(uint32_t program, int location, int count, const uint32_t* value);
		static void setProgramUniformValue2(uint32_t program, int location, int count, const uint32_t* value);
		static void setProgramUniformValue3(uint32_t program, int location, int count, const uint32_t* value);
		static void setProgramUniformValue4(uint32_t program, int location, int count, const uint32_t* value);

		static void setProgramUniformMatrix2(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformMatrix3(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformMatrix4(uint32_t program, int location, int count, const float* value);
		static void setProgramUniformMatrix2x3(uint32_t program, int location, int count, bool transpose, const float* value);
		static void setProgramUniformMatrix3x2(uint32_t program, int location, int count, bool transpose, const float* value);
		static void setProgramUniformMatrix2x4(uint32_t program, int location, int count, bool transpose, const float* value);
		static void setProgramUniformMatrix4x2(uint32_t program, int location, int count, bool transpose, const float* value);
		static void setProgramUniformMatrix3x4(uint32_t program, int location, int count, bool transpose, const float* value);
		static void setProgramUniformMatrix4x3(uint32_t program, int location, int count, bool transpose, const float* value);
	public:
		static void getUniformValue(uint32_t program, int location, int* params);
		static void getUniformValue(uint32_t program, int location, uint32_t* params);
		static void getUniformValue(uint32_t program, int location, float* params);
		static void getUniformValue(uint32_t program, int location, int bufSize, int* params);
		static void getUniformValue(uint32_t program, int location, int bufSize, uint32_t* params);
		static void getUniformValue(uint32_t program, int location, int bufSize, float* params);
	public:
		static void bindAttributeLocation(uint32_t program, uint32_t index, const char* name);
		static void bindFragDataLocation(uint32_t program, uint32_t colorNumber, const char* name);
		static void bindFragDataLocationIndexed(uint32_t program, uint32_t colorNumber, uint32_t index, const char* name);
	public:
		static void compileShader(uint32_t shader);
	public:
		static uint32_t createProgram();
		static uint32_t createShader(ShaderType type);
		static void createShaderProgram(ShaderType type, int size, const char** strings);

		static void deleteProgram(uint32_t program);
		static void deleteShader(uint32_t shader);
		static void detachShader(uint32_t program, uint32_t shader);
	public:
		static void getActiveAtomicCounterBuffer(uint32_t program, uint32_t bufferIndex, AtomicCounterBufferName name, int* params);

		static void getActiveAttrib(uint32_t program, uint32_t index, int bufSize, int *length, int *size, AttribType *type, char *name);
		static void getActiveSubroutineName(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int *length, char *name);
		static void getActiveSubroutineUniform(uint32_t program, ShaderType shaderType, uint32_t index, SubroutineUniformParameter pname, int *values);

		static void getActiveSubroutineUniformName(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int* length, char *name);
		static void getActiveUniform(uint32_t program, ShaderType shaderType, uint32_t index, int bufSize, int* length, int* size, uint32_t* type, char *name);
		static void getActiveUniformBlock(uint32_t program, uint32_t uniformBlockIndex, UniformBlockParameter pname, int* params);
		static void getActiveUniformBlockName(uint32_t program, uint32_t uniformBlockIndex, int bufSize, int* length, char *name);
		static void getActiveUniformName(uint32_t program, uint32_t uniformIndex, int bufSize, int* length, char *name);
		static void getActiveUniforms(uint32_t program, int uniformCount, const uint32_t* uniformIndices, UniformParameter pname, int* params);
		static void getAttachedShaders(uint32_t program, int maxCount, int* count, uint32_t* shaders);
		static int getAttribLocation(uint32_t program, const char* name);
		static int getFragDataIndex(uint32_t program, const char* name);
		static int getFragDataLocation(uint32_t program, const char* name);
		static void getProgram(uint32_t program, GetProgramParameter pname, int* params);
		static void getProgramBinary(uint32_t program, int bufSize, int* length, uint32_t* binaryFormat, void* binary);
		static void getProgramInfoLog(uint32_t program, int maxLength, int* length, char* infoLog);
		
		static void getProgramResource(uint32_t program, ProgramResourceInterface programInterface, uint32_t index, int proCount, const uint32_t* props, int bufSize, int* length, int* params);
		static void getProgramResourceIndex(uint32_t program, ProgramResourceIndexInterface programInterface, const char* name);
		static void getProgramResourceLocation(uint32_t program, ProgramResourceLocationInterface programInterface, const char* name);
		static void getProgramResourceLocationIndex(uint32_t program, ProgramResourceLocationIndexInterface programInterface, const char* name);
		static void getProgramResourceName(uint32_t program, ProgramResourceNameInterface programInterface, uint32_t index, int bufSize, int* length, char* name);
		static void getProgramStage(uint32_t program, ShaderType type, ProgramStageParameter pname, int* values);
		static void getShader(uint32_t shader, ShaderParameter parameter, int* params);
		static void getShaderInfoLog(uint32_t shader, int maxLength, int* length, char* infoLog);
		static void getShaderPrecisionFormat(ShaderType type, ShaderPrecisionType precisionType, int* range, int* precision);
		static void getShaderSource(uint32_t shader, int bufSize, int* length, char* source);
		static void getSubroutineIndex(uint32_t program, ShaderType type, const char* name);
		static void getSubroutineUniformLocation(uint32_t program, ShaderType type, const char* name);
		static uint32_t getUniformBlockIndex(uint32_t program, const char* uniformBlockName);
		static void getUniformIndices(uint32_t program, int uniformCount, const char** uniformNames, uint32_t* uniformIndices);
		static void getUniformSubroutine(ShaderType type, int location, uint32_t* values);
		static bool isProgram(uint32_t program);
		static bool isShader(uint32_t shader);
		static void setMinSampleShading(float value);
		static void setProgramBinary(uint32_t program, GLenum binaryFormat, const void* binary, int length);
		static void setProgramParameter(uint32_t program, ModifyProgramParameter pname, int value);
		static void releaseShaderCompiler();
		static void setShaderBinary(int count, const uint32_t* shaders, GLenum binaryFormat, const void* binary, int length);
			
		static void setShaderSource(uint32_t shader, int count, const char** string, const int* length);

			
		static void setShaderStorageBlockBinding(uint32_t program, uint32_t storageBlockIndex, uint32_t storageBlockBinding);
		static void setUniformBlockBinding(uint32_t program, uint32_t uniformBlockIndex, uint32_t uniformBlockBinding);
		static void setUniformSubroutines(ShaderType type, int count, const uint32_t* indices);

		//@see ProgramStage
		static void useProgramStages(uint32_t pipeline, GLbitfield stages, uint32_t program);
		static void validateProgram(uint32_t program);
	public:
		static size_t getTypeSize(AttribType type);
	};
}