#include "WordDocument.h"
#include "../Compile/import.h"
#include "../macros.h"
using namespace script;


WordDocument::WordDocument()
{

}

WordDocument::~WordDocument()
{

}

bool WordDocument::parse()
{
	int offset = 0;
	char spot = 0;
	std::string word;
	while (true)
	{
		if (offset >= getSize())
		{
			WordSet::getInstance()->appendWord(word.c_str());
			word.clear();
			break;
		}

		spot = *(getPtr() + offset);
		if (IS_DECORATOR(spot))
		{
			WordSet::getInstance()->appendWord(word.c_str());
			word.clear();
		}
		else
		{
			word.append(1, spot);
		}
		offset++;
	}

	return true;
}
