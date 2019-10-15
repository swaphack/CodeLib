#pragma once

#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;

	// 变量
	class Members
	{
	public:
		Members();
		virtual ~Members();
	public:
		// 添加成员变量,重名移除
		void addMember(Variable* pVariable);
		// 移除成员变量
		void removeMember(const std::string& name);
		// 移除所有成员变量
		void removeAllMembers();
		// 获取成员变量
		Variable* getMember(const std::string& name);
		// 关键字
		std::vector<std::string> keys();
	private:
		typedef std::map<std::string, Variable*> VarMembers;
		// 成员变量
		VarMembers m_varMembers;
	};
}