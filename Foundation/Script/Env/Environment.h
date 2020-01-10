#pragma once

#include <map>

#include "../Core/import.h"

namespace script
{
	// 环境,全局变量和函数
	class Environment
	{
	private:
		Environment();
		virtual ~Environment();
	public:
		static Environment* getInstance();

		// 添加变量
		void addVariable(Variable* pVariable);
		// 移除变量
		void removeVariable(const std::string& name);
		// 移除所有变量
		void removeAllVariables();
		// 获取变量
		Variable* getVariable(const std::string& name);

		// 添加函数
		void addFunction(Function* pFunction);
		// 移除函数
		void removeFunction(const std::string& name);
		// 移除所有函数
		void removeAllFunctions();
		// 获取函数
		Function* getFunction(const std::string& name);

		// 主作用域
		Scope* getRoot();

		void dispose();
	private:
		typedef std::map<std::string, Variable*> Variables;
		typedef std::map<std::string, Struct*> Structs;
		typedef std::map<std::string, Function*> Functions;

		// 全局变量
		Variables m_pVariables;
		// 全局数据结构
		Structs m_pStructs;
		// 全局函数
		Functions m_pFunctions;
		// 主域
		Scope* m_pRoot = nullptr;
	};

	// 获取环境
	extern Environment* getEnv();
}