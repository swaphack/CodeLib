#pragma once

namespace wc
{
	struct ZipText
	{
		char* text;
		int size;

		ZipText();
		ZipText(const char* text, int size);
	};
}