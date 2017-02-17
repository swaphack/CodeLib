#pragma once

#include "macros.h"

namespace script
{
	// 语法节点
	class ASTNode
	{
	public:
		// 节点值
		std::string value;
		// 左节点
		ASTNode* left;
		// 右节点
		ASTNode* right;
		// 是否是符号
		bool isSymbol;
		// 是否内嵌
		bool builtin;
		// 标记位
		int flag;
	public:
		ASTNode();
		~ASTNode();
	public:
		// 清理节点
		void clear();
		// 重置标记位
		void resetFlag();
	protected:
		// 清理节点
		void cleanNode(ASTNode* ptr);

		void resetFlag(ASTNode* ptr);
	};
}