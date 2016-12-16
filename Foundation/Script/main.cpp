#include "Script.h"

using namespace script;

int main(int argc, char** argv)
{
	// ��ʼ�����ʿ�
	const char* wordFile = "Resource/word.txt";
	Script::getInstance()->initWordSet(wordFile);

	// ��ʼ��������
	Script::getInstance()->initWordFilter();

	// �����ű�
	const char* scriptFile = "Resource/language.script";
	Script::getInstance()->load(scriptFile);

	return 0;
}