#include "Script.h"

using namespace script;

int main(int argc, char** argv)
{
	// ��ʼ�����ʿ�
	const char* wordFile = "Resource/word.txt";
	Script::getInstance()->initWordSet(wordFile);

	// ��ʼ��������
	Script::getInstance()->initWordFilter();

	// ��ʼ�����Ž�������
	const char* symbolFile = "Resource/Symbol.xml";
	Script::getInstance()->initSysmbolRule(symbolFile);

	// �����ű�
	const char* scriptFile = "Resource/main.script";
	Script::getInstance()->load(scriptFile);

	return 0;
}