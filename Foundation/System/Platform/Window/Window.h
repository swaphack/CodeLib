#pragma once

#include "../Implement/import.h"

#include <string>

namespace sys
{
	class Window : public WindowImpl
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