#pragma once

#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;

	// ����
	class Members
	{
	public:
		Members();
		virtual ~Members();
	public:
		// ��ӳ�Ա����,�����Ƴ�
		void addMember(Variable* pVariable);
		// �Ƴ���Ա����
		void removeMember(const std::string& name);
		// �Ƴ����г�Ա����
		void removeAllMembers();
		// ��ȡ��Ա����
		Variable* getMember(const std::string& name);
		// �ؼ���
		std::vector<std::string> keys();
	private:
		typedef std::map<std::string, Variable*> VarMembers;
		// ��Ա����
		VarMembers m_varMembers;
	};
}