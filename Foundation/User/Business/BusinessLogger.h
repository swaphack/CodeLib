#pragma once

#include "../Logger/Logger.h"

#include "BusinessGlobal.h"

namespace user
{
	class BusinessLogger : public Logger
	{
	public:
		BusinessLogger(long type, const char* url);
		virtual ~BusinessLogger();
	public:
		virtual void load();

		virtual void save();
	protected:
	private:
	};
}