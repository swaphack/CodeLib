#pragma once

#include "macros.h"

namespace script
{
	// �﷨�ڵ�
	class ASTNode
	{
	public:
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
	public:
		ASTNode();
		~ASTNode();
	public:
		// ����ڵ�
		void clear();
		// ���ñ��λ
		void resetFlag();
	protected:
		// ����ڵ�
		void cleanNode(ASTNode* ptr);

		void resetFlag(ASTNode* ptr);
	};
}