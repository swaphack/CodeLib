#pragma once

#include "ShaderVariable.h"

#include "Graphic/GLAPI/macros.h"

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
		/**
		*	���ñ������
		*/
		void setAttribID(uint32_t id);
		/**
		*	���Ա��
		*/
		uint32_t getAttribID();
	public:
		void showAttribs();
	public:
		void setValue1(const double* v);
		void setValue2(const double* v);
		void setValue3(const double* v);
		void setValue4(const double* v);

		void setValue1(const float* v);
		void setValue2(const float* v);
		void setValue3(const float* v);
		void setValue4(const float* v);

		void setValue4(const uint32_t* v);
		void setValue4(const int32_t* v);
		void setValue4(const uint16_t* v);

		void setValue1(const int16_t* v);
		void setValue2(const int16_t* v);
		void setValue3(const int16_t* v);
		void setValue4(const int16_t* v);

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
	private:
		/**
		*	���
		*/
		uint32_t _attribID = 0;
	};
}