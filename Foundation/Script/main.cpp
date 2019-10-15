#include "Script.h"
#include "Core/import.h"

using namespace script;

int main(int argc, char** argv)
{
	// 初始化单词库
	const char* wordFile = "Resource/word.txt";
	Script::getInstance()->initWordSet(wordFile);

	// 初始化符号解析规则
	const char* symbolFile = "Resource/Symbol.xml";
	Script::getInstance()->initSysmbolRule(symbolFile);

	// 解析脚本
	const char* scriptFile = "Resource/main.script";
	Script::getInstance()->load(scriptFile);

	Console::getInstance()->pause();

	return 0;
}