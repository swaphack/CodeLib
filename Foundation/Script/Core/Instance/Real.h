#pragma once

#include "macros.h"

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
		float getValue() const;
	public: // ����
		// ��¡
		Real* clone();
		// �����µ��ڴ棬Ϊ������ֵ
		Real* alloct(const char* name);
	public: // ��д������
		Real& operator=(const Real& value);
		Real& operator+=(const Real& value);
		Real& operator-=(const Real& value);
		Real& operator*=(const Real& value);
		Real& operator/=(const Real& value);

		Real operator+(const Real& value);
		Real operator-(const Real& value);
		Real operator*(const Real& value);
		Real operator/(const Real& value);

		bool operator==(const Real& value);
		bool operator>(const Real& value);
		bool operator<(const Real& value);
		bool operator!=(const Real& value);
		bool operator>=(const Real& value);
		bool operator<=(const Real& value);
	protected:
		// ��ʼ��Ĭ�Ϻ���
		virtual void initFunctions();
	private:
		float m_fValue;
	};
}