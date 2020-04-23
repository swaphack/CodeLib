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
		static uint32_t createShader(ShaderType type);
		static void deleteShader(uint32_t shaderID);
		static void loadShader(uint32_t shaderID, const char* data);
		static void attachShader(uint32_t programID, uint32_t shaderID);
		static void detachShader(uint32_t programID, uint32_t shaderID);
		static void showShaderStatus(uint32_t shaderID);
	public:
		static uint32_t createProgram();
		static void deleteProgram(uint32_t programID);
		static void linkProgram(uint32_t programID);
		static void useProgram(uint32_t programID);
		static void showProgramStatus(uint32_t programID);
	public:
		static int getAttrib(uint32_t programID, const char* attribName);
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
		static int getUniform(int32_t programID, const char* uniformName);
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
	};
}