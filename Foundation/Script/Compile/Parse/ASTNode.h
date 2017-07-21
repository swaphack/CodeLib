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
		// ��¡
		void copy(const ASTNode& node);
	protected:
		// ����ڵ�
		void cleanNode(ASTNode* ptr);

		void resetFlag(ASTNode* ptr);
	};
}