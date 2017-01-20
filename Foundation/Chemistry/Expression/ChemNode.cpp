#include "ChemNode.h"

using namespace chem;

ChemNode::ChemNode()
:_root(nullptr)
{

}

ChemNode::~ChemNode()
{
	this->disponse();
}

void ChemNode::setRoot(CombineNode* node)
{
	if (node == nullptr)
	{ 
		return;
	}

	this->disponse();

	_root = node;
}

CombineNode* ChemNode::createRoot(const std::string& symbol, const std::string& count)
{
	_root = createNode(symbol, count);

	return _root;
}

CombineNode* ChemNode::createNode(const std::string& symbol, const std::string& count)
{
	AtomNode* value = new AtomNode(); 
	value->symbol = symbol;
	value->count = count;

	CombineNode* node = new CombineNode();
	node->value = value;

	return node;
}

bool ChemNode::disponseNode(CombineNode* node)
{
	if (node == nullptr)
	{
		return false;
	}
	
	if (node->value)
	{
		delete node->value;
		node->value = nullptr;
	}
	delete node;
	node = nullptr;

	return true;
}

bool ChemNode::addNode(CombineNode* previous, CombineNode* next)
{
	if (previous == nullptr || next == nullptr)
	{
		return false;
	}

	if (previous->next != nullptr)
	{
		return false;
	}

	previous->next = next;

	return true;
}

bool ChemNode::addChild(CombineNode* parent, CombineNode* child)
{
	if (parent == nullptr || child == nullptr)
	{
		return false;
	}

	if (parent->firstChild != nullptr)
	{
		return false;
	}

	parent->firstChild = child;

	return true;
}

void ChemNode::disponse()
{
	if (_root == nullptr)
	{
		return;
	}

	disponseTree(_root);
	_root = nullptr;
}

void ChemNode::foreach(const LookNodeHandler& handler)
{
	if (handler == nullptr || _root == nullptr)
	{
		return;
	}
	
	foreachTree(_root, handler);
}

bool ChemNode::disponseTree(CombineNode* node)
{
	if (node == nullptr)
	{
		return false;
	}

	CombineNode* current = node;
	CombineNode* last = nullptr;
	while (current != nullptr)
	{
		disponseTree(current->firstChild);
		delete current->value;
		last = current;
		current = last->next;
		delete last;
	}

	return true;
}

void ChemNode::foreachTree(CombineNode* node, const LookNodeHandler& handler)
{
	if (node == nullptr || handler == nullptr)
	{
		return;
	}

	CombineNode* current = node;

	while (current != nullptr)
	{
		if (current->firstChild)
		{
			int count = atoi(current->childCount.c_str());
			for (int i = 0; i < count; i++)
			{
				foreachTree(current->firstChild, handler);
			}
		}
		if (current->value)
		{
			handler(current->value);
		}
		current = current->next;
	}
}


