#pragma once

#include "Base.h"
#include "Variable.h"

#include <vector>

namespace script
{
	// �������ض����ܵ�����
	class Scope : public Base
	{
	public:
		Scope();
		virtual ~Scope();
	public:
		// ��ȡ����
		void addChild(Scope* pChild);
		// �Ƴ�����
		void removeChild(const char* name);
		// �Ƴ���������
		void removeAllChildren();
		// ��ȡ����
		Scope* getChild(const char* name);

		// ����
		Scope* getParent();
		void setParent(Scope* pParent);

		// ��Ӿֲ�����
		void addMember(Variable* pVariable);
		// �Ƴ��ֲ�����
		void removeMember(const char* name);
		// �Ƴ����оֲ�����
		void removeAllMembers();
		// ��ȡ�ֲ�����
		Variable* getMember(const char* name);

		// ����
		bool call(std::vector<Variable*> inputs, std::vector<Variable*>& outputs);

		// �뿪��������Ƴ����г�Ա��Ϣ
		virtual void disponse();
	private:
		typedef std::map<std::string, Scope*> Scopes;
		typedef std::map<std::string, Variable*> Members;
		// ����
		Scopes m_pChildren;
		// �ֲ�����
		Members m_pMembers;
		// ����
		Scope* m_pParent;
	};
}