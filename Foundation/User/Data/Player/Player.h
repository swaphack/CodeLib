#pragma once

#include "IPlayer.h"

namespace user
{
	class Player : public IPlayer
	{
	public:
		Player(long id = 0);
		~Player();
	public:
		virtual long getID();

		virtual void runAction(IAction* action);

		virtual void runActionWithRecord(IRecordAction* action);

	private:
		long _id;
	};
}