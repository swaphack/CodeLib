#pragma once

namespace sys
{
	// �����ʽ
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