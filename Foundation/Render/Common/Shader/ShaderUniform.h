#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	����
	*	uniform����������C��������ĳ�����const ���������ܱ�shader�����޸ġ���shaderֻ���ã����ܸģ�
	*	���uniform������vertex��fragment����֮��������ʽ��ȫһ��������������vertex��fragment����ʹ�á����൱��һ����vertex��fragment shader�����ȫ�ֱ�����
	*/
	class ShaderUniform : public ShaderVariable
	{
	public:
		ShaderUniform();
		virtual ~ShaderUniform();
	public:
		/**
		*	���ñ������
		*/
		void setUniformID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getUniformID();
	public:
		void setValue(VertexAttribSize type, int len, float* v);
		void setValue(VertexAttribSize type, int len, int32_t* v);

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

		void setMatrix2(bool transpose, const float* value);
		void setMatrix3(bool transpose, const float* value);
		void setMatrix4(bool transpose, const float* value);

		void setMatrix2(const float* value);
		void setMatrix3(const float* value);
		void setMatrix4(const float* value);
	private:
		uint32_t _uniformID = 0;
	};
}