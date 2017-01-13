#include "ChemNode.h"

using namespace chem;

void ChemNode::appendNode(const std::string& symbol, const std::string& count)
{
	if (symbol.empty())
	{
		return;
	}

	AtomNode* node = new AtomNode();
	node->symbol = symbol;
	node->count = count.empty() ? "1" : count;

	this->appendNode(node);
}

void ChemNode::appendNode(const AtomNode* node)
{
	if (node == nullptr) 
	{
		return;
	}

	MoleculeNode* combineNode = new MoleculeNode();
	combineNode->count = "1";
	combineNode->elements.push_back((AtomNode*)node);

	appendNode(combineNode);
}

void ChemNode::appendNode(const CombineNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	CombineNodes.push_back((CombineNode*)node);
}

void ChemNode::appendNode(const ChemNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::vector<CombineNode*>::const_iterator iter = node->CombineNodes.begin();
	while (iter != node->CombineNodes.end())
	{
		this->appendNode(*iter);
		iter++;
	}
}

void ChemNode::disponse()
{
	std::vector<CombineNode*>::iterator iter = CombineNodes.begin();
	while (iter != CombineNodes.end())
	{
		delete *iter;
		iter++;
	}

	CombineNodes.clear();
}
