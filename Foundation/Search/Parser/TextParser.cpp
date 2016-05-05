#include "TextParser.h"
#include "../String/import.h"

using namespace search;

TextParser::TextParser( const char* key )
{
	this->parserText(key);
}

TextParser::~TextParser()
{
	_keys.clear();
}

void TextParser::parserText( const char* key )
{
	_keys.clear();

	if (key == nullptr)
	{
		return;
	}

	std::string* word = GET_STRING_PTR(key);

	_keys.insert(*word);
}

const std::set<std::string>& TextParser::getKeys()
{
	return _keys;
}
