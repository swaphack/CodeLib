#include "CommandParser.h"
#include "Type/String.h"

using namespace sys;


CommandParams::CommandParams()
{

}

CommandParams::~CommandParams()
{

}

void CommandParams::setKey(const std::string& key)
{
	_key = key;
}

const std::string& CommandParams::getKey()
{
	return _key;
}

void CommandParams::addParam(const std::string& param)
{
	_params.push_back(param);
}

void CommandParams::removeParam(const std::string& param)
{
	std::vector<std::string>::iterator it = std::find(_params.begin(), _params.end(), param);
	if (it != _params.end())
	{
		_params.erase(it);
	}
}

void CommandParams::removeAllParams()
{
	_params.clear();
}

int CommandParams::getParamsCount()
{
	return _params.size();
}

std::string CommandParams::item(int index)
{
	if (index < 0 || index >= _params.size())
	{
		return "";
	}

	return _params[index];
}


//////////////////////////////////////////////////////////////////////////
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

void CommandParser::parseLine(const std::string& line)
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

	std::string key;
	std::vector<std::string> params;

	std::string value = *words.begin();
	if (_commandParsers.find(value) == _commandParsers.end())
	{
		return;
	}

	int index = 0;
	while (index < words.size())
	{
		value = words[index];
		if (_commandParsers.find(value) != _commandParsers.end())
		{
			if (key.empty())
			{
				key = value;
				params.clear();
			}
			else
			{
				this->dispatch(key, params);
				key = value;
				params.clear();
			}
		}
		else
		{
			params.push_back(value);
		}
		index++;
	}

	if (!key.empty())
	{
		this->dispatch(key, params);
	}
}

void CommandParser::parseCommand(const std::string& commamd)
{
	String strLine = commamd;
	std::vector<std::string> words;
	strLine.split(' ', words);
	if (words.size() == 0)
	{
		return;
	}

	std::string key = *words.begin();
	words.erase(words.begin());

	this->dispatch(key, words);
}

void CommandParser::dispatch(const std::string& key, const std::vector<std::string>& params)
{
	if (_commandParsers.find(key) == _commandParsers.end())
	{
		return;
	}

	_commandParsers[key](params);
}
