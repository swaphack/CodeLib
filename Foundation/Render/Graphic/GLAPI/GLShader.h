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
		static int getAttrib(uint32_t program, const char* attribName);
		static void setAttribValue(uint32_t attribID, int len, const double* v);
		static void setAttribValue(uint32_t attribID, int len, const float* v);
		static void setAttribValue(uint32_t attribID, int len, const uint32_t* v);
		static void setAttribValue(uint32_t attribID, int len, const int32_t* v);
		static void setAttribValue(uint32_t attribID, int len, const uint16_t* v);
		static void setAttribValue(uint32_t attribID, int len, const int16_t* v);
		static void setAttribValue(uint32_t attribID, int len, const uint8_t* v);
		static void setAttribValue(uint32_t attribID, int len, const int8_t* v);

		static void setAttribValue(uint32_t attribID, double v0);
		static void setAttribValue(uint32_t attribID, double v0, double v1);
		static void setAttribValue(uint32_t attribID, double v0, double v1, double v2);
		static void setAttribValue(uint32_t attribID, double v0, double v1, double v2, double v3);

		static void setAttribValue(uint32_t attribID, float v0);
		static void setAttribValue(uint32_t attribID, float v0, float v1);
		static void setAttribValue(uint32_t attribID, float v0, float v1, float v2);
		static void setAttribValue(uint32_t attribID, float v0, float v1, float v2, float v3);

		static void setAttribValue(uint32_t attribID, uint16_t v0);
		static void setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1);
		static void setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2);
		static void setAttribValue(uint32_t attribID, uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3);

		static void setAttribValue(uint32_t attribID, float* value);
		static void setAttribValue(uint32_t attribID, uint16_t* value);

		static void showAttribStatus(uint32_t attribID);
	public:
		static int getUniform(int32_t program, const char* uniformName);
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
		static void getActiveSubroutineUniform(uint32_t program, ShaderType shaderType, uint32_t index, int *values);
		/*
		static void getActiveSubroutineUniformName
		static void getActiveUniform
		static void getActiveUniformBlock
		static void getActiveUniformBlockName
		static void getActiveUniformName
		static void getActiveUniformsiv
		static void getAttachedShaders
		static void getAttribLocation
		static void getFragDataIndex
		static void getFragDataLocation
		static void getProgram
		static void getProgramBinary
		static void getProgramInfoLog
		static void getProgramResource
		static void getProgramResourceIndex
		static void getProgramResourceLocation
		static void getProgramResourceLocationIndex
		static void getProgramResourceName
		static void getProgramStage
		static void getShader
		static void getShaderInfoLog
		static void getShaderPrecisionFormat
		static void getShaderSource
		static void getSubroutineIndex
		static void getSubroutineUniformLocation
		static void getUniform
		static void getUniformBlockIndex
		static void getUniformIndices
		static void getUniformLocation
		static void getUniformSubroutine
		static void isProgram
		static void isShader
		static void linkProgram
		static void glMinSampleShading
		static void glProgramBinary
		static void glProgramParameter
		static void glProgramUniform
		static void glReleaseShaderCompiler
		static void glShaderBinary
		static void glShaderSource
		static void glShaderStorageBlockBinding
		static void glUniform
		static void glUniformBlockBinding
		static void glUniformSubroutines
		static void glUseProgram
		static void glUseProgramStages
		static void glValidateProgram
		*/
	};
}