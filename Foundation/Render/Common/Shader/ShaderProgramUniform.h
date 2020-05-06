#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

namespace render
{
	/**
	*	�������
	*	uniform����������C��������ĳ�����const ���������ܱ�shader�����޸ġ���shaderֻ���ã����ܸģ�
	*	���uniform������vertex��fragment����֮��������ʽ��ȫһ��������������vertex��fragment����ʹ�á����൱��һ����vertex��fragment shader�����ȫ�ֱ�����
	*/
	class ShaderProgramUniform : public ShaderVariable
	{
	public:
		ShaderProgramUniform();
		virtual ~ShaderProgramUniform();
	public:
		/**
		*	���ñ������
		*/
		void setProgramUniformID(uint32_t id);
		/**
		*	���Ա��
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