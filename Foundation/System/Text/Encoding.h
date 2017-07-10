#pragma once

namespace sys
{
	// ±‡¬Î∏Ò Ω
	class Encoding
	{
	public:
		virtual bool Is(const char* text) = 0;
	};

	class UTF8
	{
	public:
		virtual bool Is(const char* text);
	protected:
	private:
	};
}