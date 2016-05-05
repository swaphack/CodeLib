#pragma once

#include "../Macros.h"

namespace user
{
	class IPlayer : public IDBRecord
	{
	public:
		virtual void runAction(IAction* action) = 0;

		virtual void runActionWithRecord(IRecordAction* action) = 0;
	};
}