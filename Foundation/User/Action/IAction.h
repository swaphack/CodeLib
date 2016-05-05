#pragma once

#include "../Logger/ILoggerRecord.h"

#include <string>

namespace user
{
	class IAction
	{
	public:
		virtual bool run() = 0;
	};

	class IRecordAction : public IAction
	{
	public:
		virtual ILoggerRecord* generateRecord() = 0;

		virtual void saveRecord() = 0;

		virtual const char* getActionString() = 0;
	protected:
	private:
	};
}