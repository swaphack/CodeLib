#include "ASTNode.h"

using namespace script;

ASTNode::ASTNode() 
:left(nullptr)
, right(nullptr)
, isSymbol(false)
, flag(0)
{

}

ASTNode::~ASTNode()
{
	clear();
}

void ASTNode::resetFlag(ASTNode* ptr)
{
	if (ptr == nullptr)
		return;

	resetFlag(ptr->left);
	resetFlag(ptr->right);

	ptr->flag = 0;
}

void ASTNode::resetFlag()
{
	resetFlag(this);
}

void ASTNode::cleanNode(ASTNode* ptr)
{
	if (ptr == nullptr)
		return;

	if (ptr->left)
	{
		cleanNode(ptr->left);
		ptr->left = nullptr;
	}
	if (ptr->right)
	{
		cleanNode(ptr->right);
		ptr->right = nullptr;
	}

	delete ptr;
}

void ASTNode::clear()
{
	if (this->left)
	{
		cleanNode(this->left);
		this->left = nullptr;
	}
	if (this->right)
	{
		cleanNode(this->right);
		this->right = nullptr;
	}
}

void ASTNode::copy(const ASTNode& node)
{
	value = node.value;

	if (node.left != nullptr)
	{
		left = new ASTNode();
		left->copy(*(node.left));
	}

	if (node.right != nullptr)
	{
		right = new ASTNode();
		right->copy(*(node.right));
	}
}
