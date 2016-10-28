#pragma once

#include "Variable.h"

#include <string>

namespace script
{
	// ʵ��
	class Real : public Variable
	{
	public:
		Real();
		Real(Real& value);
		virtual ~Real();
	public:
		// ���ñ���ֵ
		void setValue(float value);
		// ��ȡ����ֵ
		float getValue();

		Real operator + (Real& value);
		Real operator - (Real& value);
		Real operator * (Real& value);
		Real operator / (Real& value);

		Real& operator = (Real& value);
		Real& operator += (Real& value);
		Real& operator -= (Real& value);
		Real& operator *= (Real& value);
		Real& operator /= (Real& value);
	public: // ����
		// ��¡
		Real* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Real* alloct(const char* name);
	protected:
		void initFunctions();
	private:
		float m_fValue;
	};

	// �ı�
	class Text : public Variable
	{
	public:
		Text();
		virtual ~Text();
	public:
		// ���ñ���ֵ
		void setValue(const char* value);
		// ��ȡ����ֵ
		const char* getValue();
	public: // ����
		// ��¡
		Text* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Text* alloct(const char* name);
	private:
		std::string m_strValue;
	};

	// ��
	class None : public Variable
	{
	public:
		None();
		virtual ~None();
	public:
		// ��ȡ����ֵ
		void* getValue();
	public: // ����
		// ��¡
		None* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		None* alloct(const char* name);
	};
}