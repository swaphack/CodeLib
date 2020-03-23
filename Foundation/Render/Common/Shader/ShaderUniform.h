#pragma once

#include "ShaderVariable.h"

namespace render
{
	/**
	*	固定属性
	*	uniform变量就像是C语言里面的常量（const ），它不能被shader程序修改。（shader只能用，不能改）
	*	如果uniform变量在vertex和fragment两者之间声明方式完全一样，则它可以在vertex和fragment共享使用。（相当于一个被vertex和fragment shader共享的全局变量）
	*/
	class ShaderUniform : public ShaderVariable
	{
	public:
		ShaderUniform();
		virtual ~ShaderUniform();
	public:
		void showUniforms();
	public:
		void setValue(int type, int len, float* v);
		void setValue(int type, int len, int32_t* v);

		void setValue(float v0);
		void setValue(float v0, float v1);
		void setValue(float v0, float v1, float v2);
		void setValue(float v0, float v1, float v2, float v3);

		void setValue(int32_t v0);
		void setValue(int32_t v0, int32_t v1);
		void setValue(int32_t v0, int32_t v1, int32_t v2);
		void setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3);

		void setMatrix2(int count, bool transpose, const float* value);
		void setMatrix3(int count, bool transpose, const float* value);
		void setMatrix4(int count, bool transpose, const float* value);
	};
}