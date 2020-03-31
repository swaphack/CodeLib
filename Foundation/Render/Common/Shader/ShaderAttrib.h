#pragma once

#include "ShaderVariable.h"

namespace render
{
	/**
	*	�����޸�
	*	attribute������ֻ����vertex shader��ʹ�õı���������������fragment shader������attribute������Ҳ���ܱ�fragment shader��ʹ�ã�
	*/
	class ShaderAttrib : public ShaderVariable
	{
	public:
		ShaderAttrib();
		virtual ~ShaderAttrib();
	public:
		void showAttribs();
	public:
		void setValue(int len, const double* v);
		void setValue(int len, const float* v);
		void setValue(int len, const uint32_t* v);
		void setValue(int len, const int32_t* v);
		void setValue(int len, const uint16_t* v);
		void setValue(int len, const int16_t* v);
		void setValue(int len, const uint8_t* v);
		void setValue(int len, const int8_t* v);

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