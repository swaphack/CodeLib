#pragma once

#include "../Action/Action.h"

#include "BusinessGlobal.h"

namespace user
{
	class BusinessAction : public Action
	{
	public:
		BusinessAction(long playerID, long type, const char* name);
	public:
		long getPlayerID();

		long getType();

		const char* getName();

		virtual void saveRecord();

		virtual const char* getActionString();

		virtual ILogger* getLogger();

		virtual IPlayer* getPlayer();

		void doAction(bool bLogger);
	protected:
		long _playerID;
		long _type;
		std::string _name;
	};
}