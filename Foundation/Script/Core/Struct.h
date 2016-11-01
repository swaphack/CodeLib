#pragma once

#include "Variable.h"

#include <map>

namespace script
{
	class Function;
	// ���ݽṹ��
	class Struct : public Variable
	{
	public:
		Struct();
		virtual ~Struct();
	public:
		// ��ӳ�Ա����,�����Ƴ�
		void addMember(Variable* pVariable);
		// �Ƴ���Ա����
		void removeMember(const char* name);
		// �Ƴ����г�Ա����
		void removeAllMembers();

		// �̳�
		bool inherit(Struct* pParent);
		// ����
		Struct* getParent();

		// ��ȡ��Ա����
		Variable* getMember(const char* name);
		// ����
		virtual bool callFunction(const char* pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
		// ����
		virtual void disponse();
	public: // ����
		// �����µ��ڴ棬Ϊ������ֵ
		Struct* alloct(const char* name);
		// ��¡
		Struct* clone();
	protected:
		// ��ʼ��Ĭ�Ϻ���
		virtual void initFunctions();
	private:
		typedef std::map<std::string, Variable*> Members;
		// ��Ա����
		Members m_pMembers;
		// ����
		Struct* m_pParent;
	};
}