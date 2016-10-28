#pragma once

#include <string>
#include <functional>
#include <vector>

namespace script
{
	class Variable;

	// 表达式
	class Expression
	{
	public:
		Expression();
		~Expression();
	public:
		// 设置表达式字符串
		void setString(std::string& pszWords);
		// 设置表达式字符串
		void setString(const char* pszWords, int nLength);

		// 执行表达式逻辑
		bool run(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
	private:
	};
}