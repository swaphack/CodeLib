#include "VariableFilter.h"

using namespace script;

bool VariableFilter::match(const std::string& text)
{
	if (text.empty())
	{
		return false;
	}
	int len = text.length();
	if (len <= 0)
	{
		return false;
	}

	char ch = text[0];
	if (ch >= 0x30 && ch <= 0x39)
	{// 数字开头
		return false;
	}

	int i;
	for (i = 0; i < len; i++)
	{
		ch = text[i];
		// 数字，字母，下划线
		if (!((ch >= 0x30 && ch <= 0x39) || (ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A) || (ch == 0x5f)))
		{
			return false;
		}
	}

	return i == len;
}

VariableFilter::~VariableFilter()
{

}

VariableFilter::VariableFilter()
{

}


//////////////////////////////////////////////////////////////////////////

bool NumberFilter::match(const std::string& text)
{
	if (text.empty())
	{
		return false;
	}
	int len = text.length();
	if (len <= 0)
	{
		return false;
	}

	char ch;
	int i;
	bool bExistSpot = false;
	for (i = 0; i < len; i++)
	{
		ch = text[i];
		if (ch == 0x2E)
		{
			if (bExistSpot == false)
			{
				bExistSpot = true;
			}
			else
			{
				return false;
			}
		}
		// 非数字和.
		if (!(ch >= 0x30 && ch <= 0x39))
		{
			return false;
		}
	}

	return i == len;
}

NumberFilter::~NumberFilter()
{

}

NumberFilter::NumberFilter()
{

}

//////////////////////////////////////////////////////////////////////////

bool StringFilter::match(const std::string& text)
{
	if (text.empty())
	{
		return false;
	}
	int len = text.length();
	if (len <= 0)
	{
		return false;
	}

	if (text[0] != 0x22 || text[len - 1] != 0x22)
	{
		return false;
	}

	return true;
}

StringFilter::~StringFilter()
{

}

StringFilter::StringFilter()
{

}

//////////////////////////////////////////////////////////////////////////

bool NoneFilter::match(const std::string& text)
{
	if (text.empty())
	{
		return false;
	}
	int len = text.length();
	if (len <= 0)
	{
		return false;
	}

	return text == "null";
}

NoneFilter::~NoneFilter()
{

}

NoneFilter::NoneFilter()
{

}
