#pragma once

#include "Variable.h"

#include <string>

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
	public: // 覆盖
		// 克隆
		Real* clone();
		// 分配新的内存，为变量赋值
		Real* alloct(const char* name);
	protected:
		void initFunctions();
	private:
		float m_fValue;
	};

	// 文本
	class Text : public Variable
	{
	public:
		Text();
		virtual ~Text();
	public:
		// 设置变量值
		void setValue(const char* value);
		// 获取变量值
		const char* getValue();
	public: // 覆盖
		// 克隆
		Text* clone();
		// 分配新的内存，为变量赋值
		Text* alloct(const char* name);
	private:
		std::string m_strValue;
	};

	// 空
	class None : public Variable
	{
	public:
		None();
		virtual ~None();
	public:
		// 获取变量值
		void* getValue();
	public: // 覆盖
		// 克隆
		None* clone();
		// 分配新的内存，为变量赋值
		None* alloct(const char* name);
	};
}