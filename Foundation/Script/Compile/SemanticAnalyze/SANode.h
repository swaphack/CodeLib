#pragma once

namespace script
{
	class ASTNode;

	// ��������ڵ�
	class SANode
	{
	public:
		SANode(const ASTNode* pASTNode);
		~SANode();
	public:
		// ���ýڵ�
		bool setNode(const ASTNode* pASTNode);
		// ��ȡ�ڵ�
		const ASTNode* getNode();
	private:
		ASTNode* m_pASTNode;
	};
}