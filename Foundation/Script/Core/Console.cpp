#include "Console.h"
#include <conio.h>
#include <consoleapi.h>
#include <cstdio>
#include <Windows.h>  

using namespace script;

static Console* s_pConsole = nullptr;

enum ConsoleTextColor{
	CTC_RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
	CTC_GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
	CTC_BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
	CTC_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
	CTC_PURPLE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
	CTC_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CTC_WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	CTC_BLACK = 0
};

enum ConsoleBackGroundColor{
	CBC_RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
	CBC_GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
	CBC_BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
	CBC_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
	CBC_PURPLE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
	CBC_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
	CBC_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	CBC_BLACK = 0
};

void setConsoleColor(ConsoleTextColor textColor = CTC_WHITE, ConsoleBackGroundColor backgroundColor = CBC_BLACK)
{
	//STD_ERROR_HANDLE;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, textColor | backgroundColor);
}


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
	setConsoleColor(CTC_GREEN, CBC_BLACK);
	printf("[INFO] %s\r\n", text);
}

void Console::warn(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	setConsoleColor(CTC_YELLOW, CBC_BLACK);
	printf("[WARNING] %s\r\n", text);
}

void Console::error(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	setConsoleColor(CTC_RED, CBC_BLACK);
	printf("[ERROR] %s\r\n", text);
}

void Console::debug(bool condition, const char* text)
{
	if (!text || condition)
	{
		return;
	}

	setConsoleColor(CTC_CYAN, CBC_BLACK);
	printf("[DEBUG] %s\r\n", text);
}

void Console::info(const char* text)
{
	info(false, text);
}

void Console::warn(const char* text)
{
	warn(false, text);
}

void Console::error(const char* text)
{
	error(false, text);
}

void Console::debug(const char* text)
{
	debug(false, text);
}

void Console::open()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
}

void Console::close()
{
	FreeConsole();
}

void Console::pause()
{
	system("pause");
}

void Console::show(const char* text)
{
	setConsoleColor(CTC_WHITE, CBC_BLACK);
	printf("%s\r\n", text);
}
