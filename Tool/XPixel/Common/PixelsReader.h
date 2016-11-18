#pragma once

namespace xpixel
{
	class PixelsReader
	{
	public:
		PixelsReader();
		~PixelsReader();
	public:
		bool load(const char* filepath);
	private:
		int m_nWidht;
		int m_nHeight;
		
	};
}