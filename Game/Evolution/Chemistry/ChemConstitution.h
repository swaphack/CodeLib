#pragma once

#include "macros.h"

#include <map>
#include <set>
#include <string>

namespace nature
{
	// 元素信息 {元素id,元素个数}
	typedef std::map<int, int> Elements;

	/**
	*	化学结构(一类物质的符号标识)
	*/
	class ChemConstitution
	{
	public:
		ChemConstitution();
		virtual ~ChemConstitution();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 获取表达式
		const char* getExpression();
	protected:// 表达式
		std::string _expression;
	};

	/**
	*	原子
	*	标准:Ag
	*/
	class Atom : public ChemConstitution
	{
	public:
		Atom();
		virtual ~Atom();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 获取元素标识
		int getElement();
	private:
		// 解析结构
		void parseConstitution();
	private:
		// 元素
		int _element;
	};

	/**
	*	分子
	*	标准:H2, Al(OH)3
	*/
	class Molecule : public ChemConstitution
	{
	public:
		Molecule();
		virtual ~Molecule();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 构成元素
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
	private:
		// 解析结构
		void parseConstitution();
	private:
		// 构成元素 {元素，个数}
		Elements _elements;
	};

	/**
	*	离子
	*	标准:NH4+,AL3+
	*/
	class Hydrogenion : public ChemConstitution
	{
	public:
		Hydrogenion();
		virtual	~Hydrogenion();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 构成元素
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
		// 获取带电荷数
		int getCharge();
	private:
		// 解析结构,未完成
		void parseConstitution();
	private:
		// 构成元素 {元素，个数}
		Elements _elements;
		// 带电荷数
		int _charge;
	};
}