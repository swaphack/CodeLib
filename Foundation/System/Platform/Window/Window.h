#pragma once

#include <string>

namespace sys
{
	class Window
	{
	public:
		Window();
		virtual ~Window();
	public:

	protected:
	private:
		std::string _title;
	};
}