#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	属性修改
	*	attribute变量是只能在vertex shader中使用的变量。（它不能在fragment shader中声明attribute变量，也不能被fragment shader中使用）
	*/
	class ShaderAttrib : public ShaderVariable
	{
	public:
		ShaderAttrib();
		virtual ~ShaderAttrib();
	public:
		void showAttribs();
	public:
		void setValue(VertexAttribSize len, const double* v);
		void setValue(VertexAttribSize len, const float* v);
		void setValue4(const uint32_t* v);
		void setValue4(const int32_t* v);
		void setValue4(const uint16_t* v);
		void setValue(VertexAttribSize len, const int16_t* v);
		void setValue4(const uint8_t* v);
		void setValue4(const int8_t* v);

		void setValue(double v0);
		void setValue(double v0, double v1);
		void setValue(double v0, double v1, double v2);
		void setValue(double v0, double v1, double v2, double v3);
		
		void setValue(float v0);
		void setValue(float v0, float v1);
		void setValue(float v0, float v1, float v2);
		void setValue(float v0, float v1, float v2, float v3);
		
		void setValue(uint16_t v0);
		void setValue(uint16_t v0, uint16_t v1);
		void setValue(uint16_t v0, uint16_t v1, uint16_t v2);
		void setValue(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3);

		void setValue(float* value);
		void setValue(uint16_t* value);
	};
}