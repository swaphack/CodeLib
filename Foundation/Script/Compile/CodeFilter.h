#pragma once

#include "ITextFilter.h"
#include <cstring>

namespace script
{
	// 变量格式过滤
	class VariableFilter : public ITextFilter
	{
	public:
		VariableFilter() {}
		virtual ~VariableFilter() {}
	public:
		virtual bool match(const char* text, int& size)
		{
			if (text == nullptr)
			{
				return false;
			}

			int len = strlen(text);
			if (len <= 0)
			{
				return false;
			}

			char ch = *text;
			if (ch >= 0x30 && ch <= 0x39)
			{// 数字开头
				return false;
			}

			int i;
			for (i = 0; i < len; i++)
			{
				ch = *(text + i);
				// 数字，字母，下划线
				if (!((ch >= 0x30 && ch <= 0x39) || (ch >= 0x41 && ch <= 0x5A) || (ch >= 0x61 && ch <= 0x7A) || (ch == 0x5f)))
				{
					size = i;
					return i > 0;
				}
			}

			if (i == len)
			{
				size = i;
				return true;
			}

			return false;
		}
	};

	// 数值格式过滤
	class NumberFilter : public ITextFilter
	{
	public:
		NumberFilter() {}
		virtual ~NumberFilter() {}
	public:
		virtual bool match(const char* text, int& size)
		{
			if (text == nullptr)
			{
				return false;
			}

			int len = strlen(text);
			if (len <= 0)
			{
				return false;
			}

			char ch;
			int i;
			bool bExistSpot = false;
			for (i = 0; i < len; i++)
			{
				ch = *(text + i);
				if (ch == 0x2E)
				{
					if (bExistSpot == false)
						bExistSpot = true;
					else
					{
						size = i;
						return i > 0;
					}
				}
				// 非数字和.
				if (!(ch >= 0x30 && ch <= 0x39))
				{
					size = i;
					return i > 0;
				}
			}

			if (i == len)
			{
				size = i;
				return true;
			}

			return false;
		}
	};

	// 字符串格式过滤
	class StringFilter : public ITextFilter
	{
	public:
		StringFilter() {}
		virtual ~StringFilter() {}
	public:
		virtual bool match(const char* text, int& size)
		{
			if (text == nullptr)
			{
				return false;
			}


			int len = strlen(text);
			if (len <= 0)
			{
				return false;
			}

			if (*text != 0x22)
			{
				return false;
			}
			char ch;
			int i;
			for (i = 1; i < len; i++)
			{
				ch = *(text + i);
				if (ch == 0x22)
				{
					size = i + 1;
					return true;
				}
			}

			if (i == len)
			{
				size = i;
				return true;
			}

			return false;
		}
	};
}