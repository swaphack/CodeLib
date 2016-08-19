#include "ChemNode.h"

using namespace chem;

ChemNode::ChemNode()
:symbol("")
, count("")
, inner(nullptr)
, innerCount("")
{
}

ChemNode::~ChemNode()
{
	this->disponse();
}

void ChemNode::foreach(std::function<void(const std::string& symbol, const std::string& number)> func)
{
	func(symbol, count);

	int count = next.size();

	for (int i = 0; i < count; i++)
	{
		ChemNode* pNode = next[i];
		pNode->foreach(func);
	}

	if (inner)
	{
		inner->foreach(func);
	}
}

void ChemNode::disponse()
{
	int count = next.size();

	for (int i = 0; i < count; i++)
	{
		ChemNode* pNode = next[i];
		pNode->disponse();
		delete pNode;
	}

	next.clear();

	if (inner)
	{
		inner->disponse();
		delete inner;
		inner = nullptr;
	}
}