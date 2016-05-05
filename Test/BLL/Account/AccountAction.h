#pragma once

#include "user.h"

#include "../BLLAction.h"

namespace test
{
	//////////////////////////////////////////////////////////////////////////
	class AccountAction : public BLLAction
	{
	public:
		AccountAction(long playerID, const char* name);
	protected:
	private:
	};

	//////////////////////////////////////////////////////////////////////////
	class AccountActionLogin : public AccountAction
	{
	public:
		AccountActionLogin(long playerID);
	public:
		virtual bool run();
	protected:
	private:
	};
}