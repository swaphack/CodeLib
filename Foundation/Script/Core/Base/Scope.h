#pragma once

#include "Base.h"

#include <functional>
#include <vector>

namespace script
{
	class Variable;
	class Members;

	typedef std::function<bool(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)> ScopeHandler;

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

		// ��ȡ�ֲ�����
		Variable* getMember(const char* name);

		// ���ÿ�ִ���߼�
		void setHandler(ScopeHandler handler);

		// ����
		virtual bool call(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);

		// �뿪��������Ƴ����г�Ա��Ϣ
		virtual void dispose();
	private:
		typedef std::map<std::string, Scope*> Scopes;		
		// ����
		Scopes m_pChildren;
		// �ֲ�����
		Members* m_pMembers;
		// ����
		Scope* m_pParent;
		// ��ִ���߼�
		ScopeHandler m_pHandler;
	};
}