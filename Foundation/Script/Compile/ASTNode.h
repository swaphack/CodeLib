#pragma once

#include "macros.h"

namespace script
{
	// 语法节点
	struct ASTNode
	{
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

		ASTNode() 
			:left(nullptr), right(nullptr) 
			, isSymbol(false), builtin(false)
			, flag(0){}
		~ASTNode() { clear(); }

		// 清理节点
		void clear()
		{
			cleanNode(this->left);
			cleanNode(this->right);
		}

		// 重置标记位
		void resetFlag()
		{
			resetFlag(this);
		}
	protected:
		// 清理节点
		void cleanNode(ASTNode* ptr)
		{
			if (ptr == nullptr)
				return;

			cleanNode(ptr->left);
			cleanNode(ptr->right);

			delete ptr;
		}

		void resetFlag(ASTNode* ptr)
		{
			if (ptr == nullptr)
				return;

			resetFlag(ptr->left);
			resetFlag(ptr->right);

			ptr->flag = 0;
		}
	};
}