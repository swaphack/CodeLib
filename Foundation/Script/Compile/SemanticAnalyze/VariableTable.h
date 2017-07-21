#pragma once

#include <map>
#include <string>

namespace script
{
	class Variable;

	// ������¼��
	class VariableTable
	{
	public:
		VariableTable();
		~VariableTable();
	public:
		// ����ֵ
		void set(Variable* pVar);
		// ��ȡֵ
		Variable* get(const std::string& name);
		// ���
		void clear();
	private:
		std::map<std::string, Variable*> m_mapVariable;
	};
}