#pragma once

#include <map>
#include <string>

namespace script
{
	class Variable;

	// 变量记录表
	class VariableTable
	{
	public:
		VariableTable();
		~VariableTable();
	public:
		// 设置值
		void set(Variable* pVar);
		// 获取值
		Variable* get(const std::string& name);
		// 清空
		void clear();
	private:
		std::map<std::string, Variable*> m_mapVariable;
	};
}