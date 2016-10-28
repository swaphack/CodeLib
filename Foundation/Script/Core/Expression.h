#pragma once

#include <string>
#include <functional>
#include <vector>

namespace script
{
	class Variable;

	// ���ʽ
	class Expression
	{
	public:
		Expression();
		~Expression();
	public:
		// ���ñ��ʽ�ַ���
		void setString(std::string& pszWords);
		// ���ñ��ʽ�ַ���
		void setString(const char* pszWords, int nLength);

		// ִ�б��ʽ�߼�
		bool run(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
	private:
	};
}