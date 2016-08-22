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
	ChemNode* ptr = nullptr;

	std::string symbol;
	std::string number;
	
	do
	{
		bool endBlock = false;
		if (innerNode = readBlock(endBlock))
		{
			node->inner = innerNode;
			if (endBlock) 
				return node;
			if (readNumber(number))
				node->innerCount = number;
		}

		readSymbol(symbol);
		if (symbol.empty()) continue;
		
		readNumber(number);
		if (node->symbol.empty())
			ptr = node;
		else
		{
			ptr = new ChemNode();
			node->next.push_back(ptr);
		}
		node->symbol = symbol;
		node->count = number.empty() ? "1" : number;
	} while (*_cursor);

	return node;
}

ChemNode* ChemDocument::readBlock(bool& endBlock)
{
	endBlock = false;
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
	return true;
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

	return true;
}