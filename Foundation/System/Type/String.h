#pragma once

namespace sys
{
	class String
	{
	public:
		String(const char* value);
		~String();
	public:
		virtual String& operator=(const char* value);
		virtual String& operator=(const String& value);

		String& format(const char* format, ...);
		const char* getString();
	protected:
	private:

	};
}