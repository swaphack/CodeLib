#pragma once

#include "IAction.h"
#include "../Logger/ILoggerRecord.h"

#include <string>

namespace user
{
	class Action : public IRecordAction, public IGenerateLoggerRecord<Action>
	{
	public:
		Action();
	public:
		virtual const char* getActionString();

		virtual ILoggerRecord* generateRecord();

		virtual ILoggerRecord* generateRecord(Action* action);
	};
}