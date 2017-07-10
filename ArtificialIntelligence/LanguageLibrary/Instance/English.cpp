#include "English.h"
using namespace ll;

void English::load(const char* content, int size)
{
	if (content == nullptr || size <= 0)
	{
		return;
	}

	getDictionary()->removeAllWords();

	char* ptr = (char*)content;
	while (ptr != content + size)
	{
		if (!readWord(ptr))
		{
			break;
		}
	}
}

bool English::readWord(char* ptr)
{
	if (ptr == nullptr)
	{
		return false;
	}

	char* temp = ptr;

	Text text;
	WordMeaning meaning;
	bool bRet;

	while (true)
	{
		if (*temp == '\r' || *temp == '\n')
		{
			bRet =  false;
			temp++;
			break;
		}

		if (text.empty())
	}

	ptr += temp - ptr;
	return bRet;
}

