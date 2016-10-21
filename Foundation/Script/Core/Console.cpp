#include "Console.h"

#include <cstdio>

using namespace script;

static Console* s_pConsole = nullptr;


Console::Console()
{

}

Console::~Console()
{

}

Console* Console::getInstance()
{
	if (s_pConsole == nullptr)
	{
		s_pConsole = new Console();
	}

	return s_pConsole;
}

void Console::info(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	printf("[INFO] %s\r\n", text);
}

void Console::warning(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	printf("[WARNING] %s\r\n", text);
}

void Console::error(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	printf("[ERROR] %s\r\n", text);
}

void Console::debug(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	printf("[DEBUG] %s\r\n", text);
}
