#pragma once

#include "Variable.h"
#include <map>

namespace script
{
	class Members;
	class Function;
	// 数据结构类
	class Struct : public Variable
	{
	public:
		Struct();
		virtual ~Struct();
	public:
		// 继承
		void setParent(Struct* pParent);
		// 父类
		Struct* getParent();
		// 调用
		virtual bool callFunction(const std::string& pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
		// 销毁
		virtual void dispose();
		// 获取成员变量
		Variable* getVariable(const std::string& name);
		// 获取成员
		Members* getMembers();
	public: // 重写
		// 判断是否相等
		virtual bool equal(const IVariable& var);
	public: // 覆盖
		// 分配新的内存，为变量赋值
		Struct* alloct(const char* name);
		// 克隆
		Struct* clone();
	protected:
		// 初始化默认函数
		virtual void initFunctions();
	private:
		// 父类
		Struct* m_pParent;
		// 成员变量
		Members* m_pMembers;
	};
}