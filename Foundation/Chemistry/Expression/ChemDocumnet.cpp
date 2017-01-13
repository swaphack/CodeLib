#include "ChemDocument.h"

#include "system.h"

using namespace chem;

//////////////////////////////////////////////////////////////////////////

ChemDocument::ChemDocument()
:_chemNode(nullptr)
{
}

ChemDocument::~ChemDocument()
{

}

ChemDocument* ChemDocument::~getInstance()
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
	_cursor = (char*)expression;
	if (_chemNode != nullptr) 
	{
		delete _chemNode;
	}
	_chemNode = new ChemNode();

	readExpression();

	return _chemNode;
}

bool ChemDocument::readExpression(ChemNode* chemNode)
{
	if (_cursor == nullptr || *_cursor == 0 || chemNode == nullptr)
	{
		return nullptr;
	}

	std::string symbol;
	std::string number;
	
	do
	{
		if (readBlock(chemNode))
		{ // 组合体
		}
		else if (readSymbol(symbol))
		{ // 单个元素
			readNumber(number);

			chemNode->appendNode(symbol, number);
		}

	} while (*_cursor);

	return true;
}

bool ChemDocument::readBlock(ChemNode* chemNode)
{
	bool endBlock = false;
	char* ptr = (char*)_cursor;
	char tempChar;
	
	while (*_cursor)
	{
		tempChar = *_cursor;
		if (tempChar == LEFT_PARENTHESIS)
		{
			_cursor++;
		}		
		else if (tempChar == RIGHT_PARENTHESIS)
		{
			endBlock = true;
			_cursor++;
		}
		break;
	}

	if (_cursor - ptr == 0)
	{
		return false;
	}

	if (endBlock)
	{
		return true;
	}
	ChemNode* newBlockNode = new ChemNode();
	if (readExpression(newBlockNode))
	{
		chemNode->appendNode(newBlockNode);
		delete newBlockNode;
		return true;
	}

	return false;
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