#pragma once

#include "ShaderVariable.h"

namespace render
{
	/**
	*	�̶�����
	*	uniform����������C��������ĳ�����const ���������ܱ�shader�����޸ġ���shaderֻ���ã����ܸģ�
	*	���uniform������vertex��fragment����֮��������ʽ��ȫһ��������������vertex��fragment����ʹ�á����൱��һ����vertex��fragment shader�����ȫ�ֱ�����
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