#pragma once

namespace sys
{
	// �����ʽ
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