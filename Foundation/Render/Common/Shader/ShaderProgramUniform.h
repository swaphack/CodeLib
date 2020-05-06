#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	编程属性
	*	uniform变量就像是C语言里面的常量（const ），它不能被shader程序修改。（shader只能用，不能改）
	*	如果uniform变量在vertex和fragment两者之间声明方式完全一样，则它可以在vertex和fragment共享使用。（相当于一个被vertex和fragment shader共享的全局变量）
	*/
	class ShaderProgramUniform : public ShaderVariable
	{
	public:
		ShaderProgramUniform();
		virtual ~ShaderProgramUniform();
	public:
		/**
		*	设置变量编号
		*/
		void setProgramUniformID(uint32_t id);
		/**
		*	属性编号
		*/
		uint32_t getProgramUniformID();
	public:
		void setValue(float v0);
		void setValue(float v0, float v1);
		void setValue(float v0, float v1, float v2);
		void setValue(float v0, float v1, float v2, float v3);

		void setValue(int32_t v0);
		void setValue(int32_t v0, int32_t v1);
		void setValue(int32_t v0, int32_t v1, int32_t v2);
		void setValue(int32_t v0, int32_t v1, int32_t v2, int32_t v3);

		void setValue(uint32_t v0);
		void setValue(uint32_t v0, uint32_t v1);
		void setValue(uint32_t v0, uint32_t v1, uint32_t v2);
		void setValue(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3);

		void setValue(VertexAttribSize type, int count, const float* value);
		void setValue(VertexAttribSize type, int count, const int32_t* value);
		void setValue(VertexAttribSize type, int count, const uint32_t* value);

		void setMatrix2(int count, const float* value);
		void setMatrix3(int count, const float* value);
		void setMatrix4(int count, const float* value);

		void setMatrix2x3(int count, bool transpose, const float* value);
		void setMatrix3x2(int count, bool transpose, const float* value);
		void setMatrix2x4(int count, bool transpose, const float* value);
		void setMatrix4x2(int count, bool transpose, const float* value);
		void setMatrix3x4(int count, bool transpose, const float* value);
		void setMatrix4x3(int count, bool transpose, const float* value);
	private:
		uint32_t _programUniformID = 0;
	};
}