#include "Console.h"
#include "Base/macros.h"
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
	std::string line = "";
	while ((ch = getchar()) != '\n')
	{

		line.append(1, ch);
	}
	return line.c_str();
}

char Console::readChar()
{
	char ch = getchar();
	return ch;
}

void Console::writeLine(const char* words)
{
	PRINT("%s", words);
}

void Console::writeChar(char word)
{
	PRINT("%c", word);
}
