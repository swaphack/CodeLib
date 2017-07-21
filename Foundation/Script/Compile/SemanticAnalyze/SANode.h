#pragma once

namespace script
{
	class ASTNode;

	// 语义分析节点
	class SANode
	{
	public:
		SANode(const ASTNode* pASTNode);
		~SANode();
	public:
		// 设置节点
		bool setNode(const ASTNode* pASTNode);
		// 获取节点
		const ASTNode* getNode();
	private:
		ASTNode* m_pASTNode;
	};
}