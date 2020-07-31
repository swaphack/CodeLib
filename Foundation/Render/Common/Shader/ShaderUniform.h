#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	属性
	*	uniform变量就像是C语言里面的常量（const ），它不能被shader程序修改。（shader只能用，不能改）
	*	如果uniform变量在vertex和fragment两者之间声明方式完全一样，则它可以在vertex和fragment共享使用。（相当于一个被vertex和fragment shader共享的全局变量）
	*/
	class ShaderUniform : public ShaderVariable
	{
	public:
		ShaderUniform();
		virtual ~ShaderUniform();
	public:
		/**
		*	设置变量编号
		*/
		void setUniformID(uint32_t id);
		/**
		*	属性编号
		*/
		uint32_t getUniformID();
	public:
		void setValue1(int len, const float* v);
		void setValue2(int len, const float* v);
		void setValue3(int len, const float* v);
		void setValue4(int len, const float* v);

		void setValue1(int len, const int32_t* v);
		void setValue2(int len, const int32_t* v);
		void setValue3(int len, const int32_t* v);
		void setValue4(int len, const int32_t* v);

		void setValue(float v0);
		void setValue(float v0, float v1);
		void setValue(float v0, float v1, float v2);
		void setValue(float v0, float v1, float v2, float v3);

		void setValue(uint32_t v0);
		void setValue(int32_t v0);
		void setValue(int32_t v0, int32_t v1);
		void setValue(int32_t v0, int32_t v1, int32_t v2);
		void setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3);
		// 2*2
		void setMatrix2(int count, bool transpose, const float* value);
		// 3*3
		void setMatrix3(int count, bool transpose, const float* value);
		// 4*4
		void setMatrix4(int count, bool transpose, const float* value);
		// 2*2
		void setMatrix2(bool transpose, const float* value);
		// 3*3
		void setMatrix3(bool transpose, const float* value);
		// 4*4
		void setMatrix4(bool transpose, const float* value);
		// 2*2
		void setMatrix2(const float* value);
		// 3*3
		void setMatrix3(const float* value);
		// 4*4
		void setMatrix4(const float* value);

		void setMatrix2(const math::Matrix2x2& value);
		void setMatrix3(const math::Matrix3x3& value);
		void setMatrix4(const math::Matrix4x4& value);
	private:
		uint32_t _uniformID = 0;
	};
}