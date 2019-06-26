#include "TextParser.h"
#include "IBlockParser.h"

using namespace sys;


TextParser::TextParser()
{

}

void TextParser::AddParser(IBlockParser* parser)
{
	if (parser == nullptr)
	{
		return;
	}

	_textParsers.push_back(parser);
}

void TextParser::removeParser(IBlockParser* parser)
{
	if (parser == nullptr)
	{
		return;
	}

	for (int32 i = 0; i < _textParsers.size(); i++)
	{
		if (_textParsers[i] == parser)
		{
			_textParsers.erase(_textParsers.begin() + i);
			delete parser;
			return;
		}
	}
}

void TextParser::removeAllParsers()
{
	for (int32 i = 0; i < _textParsers.size(); i++)
	{
		delete _textParsers[i];
	}

	_textParsers.clear();
}

bool TextParser::readBlock(char* inPtr, std::vector<std::string>& outData)
{
	outData.clear();

	for (int32 i = 0; i < _textParsers.size(); i++)
	{
		std::string block;
		if (_textParsers[i]->readBlock(inPtr, block))
		{
			outData.push_back(block);
		}
		else
		{
			return false;
		}
	}

	return true;
}

