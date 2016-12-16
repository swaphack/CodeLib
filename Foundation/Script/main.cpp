#include "Script.h"

using namespace script;

int main(int argc, char** argv)
{
	// 初始化单词库
	const char* wordFile = "Resource/word.txt";
	Script::getInstance()->initWordSet(wordFile);

	// 初始化过滤器
	Script::getInstance()->initWordFilter();

	// 解析脚本
	const char* scriptFile = "Resource/language.script";
	Script::getInstance()->load(scriptFile);

	return 0;
}