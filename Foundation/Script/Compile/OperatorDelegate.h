#pragma once

#include <string>
#include <map>
#include <functional>

namespace script
{
	// ����������
	typedef std::function<void()> OperatorParser;

	// �����
	struct T_Operator
	{
		// ����
		std::string name;
		// �ȼ�
		int level;
		// ����������
		OperatorParser handler;
	};

	// ����������
	class OperatorDelegate
	{
	public:
		OperatorDelegate();
		~OperatorDelegate();
	public:
		// ��ӽ���
		void addParser(const T_Operator& opeartor);
		// ��ղ���������
		void clear();
	private:
		std::map<std::string, T_Operator> m_mOperatorParsers;
	};
}