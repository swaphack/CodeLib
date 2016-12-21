#pragma once

#include "macros.h"

namespace script
{
	// �﷨�ڵ�
	struct ASTNode
	{
		// �ڵ�ֵ
		std::string value;
		// ��ڵ�
		ASTNode* left;
		// �ҽڵ�
		ASTNode* right;
		// �Ƿ��Ƿ���
		bool isSymbol;
		// �Ƿ���Ƕ
		bool builtin;
		// ���λ
		int flag;

		ASTNode() 
			:left(nullptr), right(nullptr) 
			, isSymbol(false), builtin(false)
			, flag(0){}
		~ASTNode() { clear(); }

		// ����ڵ�
		void clear()
		{
			cleanNode(this->left);
			cleanNode(this->right);
		}

		// ���ñ��λ
		void resetFlag()
		{
			resetFlag(this);
		}
	protected:
		// ����ڵ�
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