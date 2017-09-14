#include "CommandParser.h"
#include "../Type/String.h"

using namespace sys;


CommandParser::CommandParser()
{

}

CommandParser::~CommandParser()
{

}

void CommandParser::addParser(const std::string& key, ParseCommand parser)
{
	if (key.empty() || parser == nullptr)
	{
		return;
	}

	_commandParsers[key] = parser;
}

void CommandParser::removeParser(const std::string& key)
{
	_commandParsers.erase(key);
}

void CommandParser::removeAllParsers()
{
	_commandParsers.clear();
}

void CommandParser::parse(const std::string& line)
{
	if (line.empty())
	{
		return;
	}

	String strLine = line;
	std::vector<std::string> words;
	strLine.split(' ', words);
	if (words.size() == 0)
	{
		return;
	}

	std::string key = *words.begin();
	if (key.empty())
	{
		return;
	}

	if (_commandParsers.find(key) == _commandParsers.end())
	{
		return;
	}

	words.erase(words.begin());

	_commandParsers[key](words);
}
