#pragma once

#include <string>
#include <map>
#include <functional>

namespace script
{
	// 操作符解析
	typedef std::function<void()> OperatorParser;

	// 运算符
	struct T_Operator
	{
		// 名称
		std::string name;
		// 等级
		int level;
		// 操作符解析
		OperatorParser handler;
	};

	// 操作符处理
	class OperatorDelegate
	{
	public:
		OperatorDelegate();
		~OperatorDelegate();
	public:
		// 添加解析
		void addParser(const T_Operator& opeartor);
		// 清空操作符解析
		void clear();
	private:
		std::map<std::string, T_Operator> m_mOperatorParsers;
	};
}