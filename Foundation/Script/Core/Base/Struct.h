#pragma once

#include "Variable.h"
#include <map>

namespace script
{
	class Members;
	class Function;
	// ���ݽṹ��
	class Struct : public Variable
	{
	public:
		Struct();
		virtual ~Struct();
	public:
		// �̳�
		void setParent(Struct* pParent);
		// ����
		Struct* getParent();
		// ����
		virtual bool callFunction(const std::string& pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
		// ����
		virtual void dispose();
		// ��ȡ��Ա����
		Variable* getVariable(const std::string& name);
		// ��ȡ��Ա
		Members* getMembers();
	public: // ��д
		// �ж��Ƿ����
		virtual bool equal(const IVariable& var);
	public: // ����
		// �����µ��ڴ棬Ϊ������ֵ
		Struct* alloct(const char* name);
		// ��¡
		Struct* clone();
	protected:
		// ��ʼ��Ĭ�Ϻ���
		virtual void initFunctions();
	private:
		// ����
		Struct* m_pParent;
		// ��Ա����
		Members* m_pMembers;
	};
}