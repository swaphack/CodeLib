#include "IBlockParser.h"
#include "Base/str.h"
using namespace sys;

bool LineParser::readBlock(char* inPtr, std::string& outData)
{
	outData.clear();

	if (inPtr == nullptr)
	{
		return false;
	}

	char* ptr = inPtr;
	int32_t ext = strlen(LINE_MARK);

	while (*ptr != NULL)
	{
		if (LINE_EQUAL(ptr - ext + 1))
		{
			break;
		}
		ptr++;
	}

	if (LINE_EQUAL(ptr - ext + 1))
	{
		ptr++;
	}

	int32_t size = ptr - inPtr;
	outData = std::string(inPtr, size);
	inPtr += size;
	return true;
}

