#pragma once

#include "macros.h"

namespace script
{
	// 实数
	class Real : public Variable
	{
	public:
		Real();
		Real(Real& value);
		virtual ~Real();
	public:
		// 设置变量值
		void setValue(float value);
		// 获取变量值
		float getValue() const;
	public: // 覆盖
		// 克隆
		Real* clone();
		// 分配新的内存，为变量赋值
		Real* alloct(const char* name);
	public: // 重写操作符
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
		// 初始化默认函数
		virtual void initFunctions();
	private:
		float m_fValue;
	};
}