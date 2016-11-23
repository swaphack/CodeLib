#include "Console.h"
#include <cstdio>
#include <fcntl.h>  

using namespace sys;


Console::Console()
{

}

Console::~Console()
{

}

const char* Console::readLine()
{
	char ch;
	_word = "";
	while ((ch = getchar()) != '\n')
	{
		_word.append(1, ch);
	}
	return _word.c_str();
}

char Console::readChar()
{
	char ch = getchar();
	return ch;
}

void Console::writeLine(const char* words)
{
	printf("%s", words);
}

void Console::writeChar(char word)
{
	printf("%c", word);
}
