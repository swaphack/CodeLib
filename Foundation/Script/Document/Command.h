#pragma once

#include "../Core/import.h"

namespace script
{
	class Command
	{
	public:
		Command();
		virtual ~Command();
	public:
		Base* parseExpress(Express* express);
	protected:
	private:
	};
}