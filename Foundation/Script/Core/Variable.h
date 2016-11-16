#pragma once

#include "Base.h"

#include <string>
#include <vector>
#include <map>

namespace script
{
	// 数据类型
	enum DataType
	{
		// 无类型
		E_DATATYPE_NONE,
		// 变量
		E_DATATYPE_Variable,
		// 实数
		E_DATATYPE_REAL,
		// 字符串
		E_DATATYPE_TEXT,
		// 空
		E_DATATYPE_NULL,
		// 数据结构
		E_DATATYPE_STRUCT,
	};

	class Function;

	// 变量
	class Variable : public Base
	{
	public:
		Variable();
		virtual ~Variable();
	public:
		// 获取数据类型
		int getDataType();
		// 设置数据类型
		void setDataType(int nDataType);

		// 添加函数,重名移除
		void addFunction(Function* pFunction);
		// 移除函数
		void removeFunction(const char* name);
		// 移除所有函数
		void removeAllFunctions();
		// 获取函数
		Function* getFunction(const char* name);
		// 调用函数
		virtual bool callFunction(const char* pFuncName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs);
		// 调用操作符函数
		virtual bool callOperator(const char* pOperatorName, std::vector<Variable*>& inputs, std::vector<Variable*>& outputs) { return false; }
		// 销毁
		virtual void disponse();
	public: // 覆盖
		// 克隆,继承
		Variable* clone();
		// 分配新的内存，为变量赋值
		Variable* alloct(const char* name);
	protected: 
		// 初始化默认函数
		virtual void initFunctions();
	protected:
		typedef std::map<std::string, Function*> Functions;

		// 数据类型
		int m_nDataType;
		// 成员函数
		Functions m_pFunctions;
	};

	// 是否制定类型的数据
	#define IS_DATATYPE(var, varType) (var->getDataType() == varType)
}