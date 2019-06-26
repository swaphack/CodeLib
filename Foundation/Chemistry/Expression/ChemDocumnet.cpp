#include "ChemDocument.h"

#include "system.h"

using namespace chem;

//////////////////////////////////////////////////////////////////////////

ChemDocument::ChemDocument()
:_cursor(nullptr)
{
}

ChemDocument::~ChemDocument()
{
}

ChemDocument* ChemDocument::getInstance()
{
	static ChemDocument* sChemDocument = nullptr;
	if (sChemDocument == nullptr)
	{
		sChemDocument = new ChemDocument();
	}

	return sChemDocument;
}

ChemNode* ChemDocument::loadMolecular(const char* expression)
{
	if (expression == nullptr)
	{
		return nullptr;
	}
	releaseNode();
	_cursor = (char*)expression;
	_chemNode = new ChemNode();
	if (readExpression())
	{
		return _chemNode;
	}
	return nullptr;
}

void ChemDocument::releaseNode()
{
	if (_chemNode != nullptr)
	{
		delete _chemNode;
		_chemNode = nullptr;
	}
}

bool ChemDocument::readExpression()
{
	if (_cursor == nullptr || *_cursor == 0)
	{
		return false;
	}
	
	do
	{
		CombineNode* root = readBlock();
		if (!root)
		{
			return false;
		}

		_chemNode->setRoot(root);

	} while (0);

	return true;
}

CombineNode* ChemDocument::readBlock()
{
	char* ptr = (char*)_cursor;
	char tempChar;

	CombineNode* root = nullptr;
	CombineNode* temp = nullptr;
	 
	while (*_cursor)
	{
		tempChar = *_cursor;
		if (tempChar == LEFT_PARENTHESIS)
		{
			_cursor++;
			CombineNode* child = readBlock();
			if (!child)
			{
				return root;
			}

			if (root == nullptr)
			{
				root = _chemNode->createNode("", "");
				root->firstChild = child;
				temp = root;
			}
			else
			{
				if (!_chemNode->addChild(temp, child))
				{
					return root;
				}
				else
				{
					temp = child;
				}
			}
		}
		else if (tempChar == RIGHT_PARENTHESIS)
		{
			_cursor++;
			std::string count;
			if (readNumber(count))
			{
				root->childCount = count;
			}
			return root;
		}
		else
		{
			CombineNode* next = readNode();
			if (!next)
			{
				return root;
			}
			if (root == nullptr)
			{
				root = next;
				temp = root;
			}
			else
			{
				if (!_chemNode->addNode(temp, next))
				{
					return root;
				}
				else
				{
					temp = next;
				}
			}
		}		
	}

	return root;
}

CombineNode* ChemDocument::readNode()
{
	std::string symbol;
	if (!readSymbol(symbol))
	{ 
		return nullptr;
	}

	std::string count;
	readNumber(count);

	return _chemNode->createNode(symbol, count);
}

bool ChemDocument::readSymbol(std::string& symbol)
{
	symbol.clear();

	char tempChar;

	while (*_cursor)
	{
		tempChar = *_cursor;
		if (IS_CAPITAL_LETTER(tempChar))
		{
			if (!symbol.empty())
			{
				break;
			}
			symbol.append(1, tempChar);
		}
		else if (IS_LOWER_CASE_LETTER(tempChar))
		{
			symbol.append(1, tempChar);
		}
		else
		{
			break;
		}
		_cursor++;
	}
	return !symbol.empty();
}

bool ChemDocument::readNumber(std::string& number)
{
	number.clear();
	char tempChar;

	while (*_cursor)
	{
		tempChar = *_cursor;
		if (IS_NUMBER(tempChar))
		{
			number.append(1, tempChar);
		}
		else
		{
			break;
		}
		_cursor++;
	}

	return !number.empty();
}