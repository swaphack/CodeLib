#pragma once

#include "Variable.h"
#include "Function.h"

#include <map>

namespace script
{
	// 数据结构类
	class Struct : public Variable
	{
	public:
		Struct();
		virtual ~Struct();
	public:
		// 添加成员变量,重名移除
		void addMember(Variable* pVariable);
		// 移除成员变量
		void removeMember(const char* name);
		// 移除所有成员变量
		void removeAllMembers();

		// 继承
		Struct* inherit(Struct* pParent);
		// 父类
		Struct* getParent();

		// 获取成员变量
		Variable* getMember(const char* name);
		// 调用
		virtual bool callFunction(const char* pFuncName, std::vector<Variable*> inputs, std::vector<Variable*>& outputs);
		// 销毁
		virtual void disponse();
	public: // 覆盖
		// 分配新的内存，为变量赋值
		Struct* alloct(const char* name);
		// 克隆
		Struct* clone();
	private:
		typedef std::map<std::string, Variable*> Members;
		// 成员变量
		Members m_pMembers;
		// 父类
		Struct* m_pParent;
	};
}