#pragma once

#include "user.h"

#include "BusinessMacros.h"

namespace test
{
	class BLLAction : public user::BusinessAction
	{
	public:
		BLLAction(long playerID, long type, const char* name);
	public:
		virtual user::ILogger* getLogger();

		virtual user::IPlayer* getPlayer();
	protected:
	private:
	};
}