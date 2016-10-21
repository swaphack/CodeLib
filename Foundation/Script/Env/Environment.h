#pragma once

#include <map>

#include "../Core/import.h"

namespace script
{
	// ����,ȫ�ֱ����ͺ���
	class Environment
	{
	private:
		Environment();
		virtual ~Environment();
	public:
		static Environment* getInstance();

		// ��ӱ���
		void addVariable(Variable* pVariable);
		// �Ƴ�����
		void removeVariable(const char* name);
		// �Ƴ����б���
		void removeAllVariables();
		// ��ȡ����
		Variable* getVariable(const char* name);

		 

		// ��Ӻ���
		void addFunction(Function* pFunction);
		// �Ƴ�����
		void removeFunction(const char* name);
		// �Ƴ����к���
		void removeAllFunctions();
		// ��ȡ����
		Function* getFunction(const char* name);

		// ��������
		Scope* getRoot();

		void dispose();
	private:
		typedef std::map<std::string, Variable*> Variables;
		typedef std::map<std::string, Struct*> Structs;
		typedef std::map<std::string, Function*> Functions;

		// ȫ�ֱ���
		Variables m_pVariables;
		// ȫ�����ݽṹ
		Structs m_pStructs;
		// ȫ�ֺ���
		Functions m_pFunctions;
		// ����
		Scope* m_pRoot;
	};

	// ��ȡ����
	extern Environment* getEnv();
}