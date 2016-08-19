#include "ChemDocument.h"

#include "system.h"

using namespace chem;

//////////////////////////////////////////////////////////////////////////

ChemDocument::ChemDocument()
{

}

ChemDocument::~ChemDocument()
{

}

ChemNode* ChemDocument::loadMolecular(const char* expression)
{
	_cursor = (char*)expression;
	return readExpression();
}

ChemNode* ChemDocument::readExpression()
{
	if (_cursor == nullptr || *_cursor == 0)
	{
		return nullptr;
	}

	ChemNode* node = new ChemNode();
	ChemNode* innerNode = nullptr;
	ChemNode* nextNode = nullptr;

	std::string symbol;
	std::string number;
	
	while (*_cursor)
	{
		bool endBlock = false;
		if (innerNode = readBlock(endBlock))
		{
			node->inner = innerNode;
		}

		if (endBlock)
		{
			return node;
		}

		if (innerNode)
		{
			number.clear();
			if (readNumber(number))
			{
				node->innerCount = number;
			}
		}

		symbol.clear();
		readSymbol(symbol);

		number.clear();
		readNumber(number);

		if (!symbol.empty())
		{
			if (node->symbol.empty())
			{
				node->symbol = symbol;
				node->count = number.empty() ? "1" : number;
			}
			else
			{
				nextNode = new ChemNode();
				nextNode->symbol = symbol;
				nextNode->count = number.empty() ? "1" : number;
				node->next.push_back(nextNode);
			}
		}
	}
	return node;
}

ChemNode* ChemDocument::readBlock(bool& endBlock)
{
	char* ptr = (char*)_cursor;
	char tempChar;
	endBlock = false;
	
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
		return nullptr;
	}

	if (endBlock)
	{
		return nullptr;
	}

	int cursor = 0;
	ChemNode* temp = readExpression();
	if (temp)
	{
		return temp;
	}

	return nullptr;
}

bool ChemDocument::readSymbol(std::string& symbol)
{
	char tempChar;
	symbol.clear();

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
	return true;
}

bool ChemDocument::readNumber(std::string& number)
{
	char tempChar;
	number.clear();

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

	return true;
}