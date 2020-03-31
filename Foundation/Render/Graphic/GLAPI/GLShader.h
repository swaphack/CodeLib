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
		static int createShader(ShaderType type);
		static void deleteShader(int shaderID);
		static void loadShader(int shaderID, const char* data);
		static void attachShader(int programID, int shaderID);
		static void detachShader(int programID, int shaderID);
		static void showShaderStatus(int shaderID);
	public:
		static int createProgram();
		static void deleteProgram(int programID);
		static void linkProgram(int programID);
		static void useProgram(int programID);
		static void showProgramStatus(int programID);
	public:
		static int getAttrib(int programID, const char* attribName);
		static void setAttribValue(int attribID, int len, const double* v);
		static void setAttribValue(int attribID, int len, const float* v);
		static void setAttribValue(int attribID, int len, const uint32_t* v);
		static void setAttribValue(int attribID, int len, const int32_t* v);
		static void setAttribValue(int attribID, int len, const uint16_t* v);
		static void setAttribValue(int attribID, int len, const int16_t* v);
		static void setAttribValue(int attribID, int len, const uint8_t* v);
		static void setAttribValue(int attribID, int len, const int8_t* v);

		static void setAttribValue(int attribID, double v0);
		static void setAttribValue(int attribID, double v0, double v1);
		static void setAttribValue(int attribID, double v0, double v1, double v2);
		static void setAttribValue(int attribID, double v0, double v1, double v2, double v3);

		static void setAttribValue(int attribID, float v0);
		static void setAttribValue(int attribID, float v0, float v1);
		static void setAttribValue(int attribID, float v0, float v1, float v2);
		static void setAttribValue(int attribID, float v0, float v1, float v2, float v3);

		static void setAttribValue(int attribID, uint16_t v0);
		static void setAttribValue(int attribID, uint16_t v0, uint16_t v1);
		static void setAttribValue(int attribID, uint16_t v0, uint16_t v1, uint16_t v2);
		static void setAttribValue(int attribID, uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3);

		static void setAttribValue(int attribID, float* value);
		static void setAttribValue(int attribID, uint16_t* value);

		static void showAttribStatus(int attribID);
	public:
		static int getUniform(int programID, const char* uniformName);
		static void setUniformValue(int uniformID, int type, int len, float* v);
		static void setUniformValue(int uniformID, int type, int len, int32_t* v);
		 
		static void setUniformValue(int uniformID, float v0);
		static void setUniformValue(int uniformID, float v0, float v1);
		static void setUniformValue(int uniformID, float v0, float v1, float v2);
		static void setUniformValue(int uniformID, float v0, float v1, float v2, float v3);
		 
		static void setUniformValue(int uniformID, int32_t v0);
		static void setUniformValue(int uniformID, int32_t v0, int32_t v1);
		static void setUniformValue(int uniformID, int32_t v0, int32_t v1, int32_t v2);
		static void setUniformValue(int uniformID, int32_t v0, int32_t v1, int32_t v2, int32_t v3);
		 
		static void setUniformMatrix2(int uniformID, int count, bool transpose, const float* value);
		static void setUniformMatrix3(int uniformID, int count, bool transpose, const float* value);
		static void setUniformMatrix4(int uniformID, int count, bool transpose, const float* value);
	};
}