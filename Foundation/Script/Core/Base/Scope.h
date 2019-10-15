#pragma once

#include "Base.h"

#include <functional>
#include <vector>

namespace script
{
	class Variable;
	class Members;

	typedef std::function<bool(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs)> ScopeHandler;

	// 作用域，特定功能的区域
	class Scope : public Base
	{
	public:
		Scope();
		virtual ~Scope();
	public:
		// 获取子域
		void addChild(Scope* pChild);
		// 移除子域
		void removeChild(const std::string& name);
		// 移除所有子域
		void removeAllChildren();
		// 获取子域
		Scope* getChild(const std::string& name);

		// 父域
		Scope* getParent();
		void setParent(Scope* pParent);

		// 获取局部变量
		Variable* getMember(const std::string& name);

		// 设置块执行逻辑
		void setHandler(const ScopeHandler& handler);

		// 调用
		virtual bool call(std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);

		// 离开作用域后，移除所有成员信息
		virtual void dispose();
	private:
		typedef std::map<std::string, Scope*> Scopes;		
		// 子域
		Scopes m_pChildren;
		// 局部变量
		Members* m_pMembers = nullptr;
		// 父类
		Scope* m_pParent = nullptr;
		// 块执行逻辑
		ScopeHandler m_pHandler;
	};
}