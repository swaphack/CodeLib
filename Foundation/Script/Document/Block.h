#pragma once

#include <vector>
#include <map>
#include <string>

namespace script
{
	class Variable;
	class Expression;
	// 代码块
	class Block
	{
	public:
		Block();
		virtual ~Block();
	public:
		// 设置块名称
		void setName(const char* name);
		// 获取块名称
		const char* getName();
		// 添加子块
		void addBlock(Block* block);
		// 获取子块
		Block* getBlock(const char* name);
		// 移除子块
		void removeBlock(const char* name);
		// 移除所有子块
		void removeAllBlocks();
		// 添加表达式
		void addExpression(Expression* expression);
		// 移除所有表达式
		void removeAllExpressions();
	private:
		typedef std::vector<Expression*>  Expressions;
		typedef std::map<std::string, Block*> Blocks;
		// 表达式
		Expressions m_pExpressions;
		// 子块
		Blocks m_pBlocks;
		// 名称
		std::string m_strName;
	};
}