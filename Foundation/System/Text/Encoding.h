#pragma once

namespace sys
{
	// ±‡¬Î∏Ò Ω
	class Encoding
	{
	public:
		virtual bool Is(const std::string& text) = 0;
	};

	class UTF8
	{
	public:
		virtual bool Is(const std::string& text);
	protected:
	private:
	};
}