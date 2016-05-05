#include "Player.h"

using namespace user;

Player::Player(long id)
:_id(id)
{
}


Player::~Player()
{
}

long Player::getID()
{
	return _id;
}

void Player::runAction( IAction* action )
{
	if (action == nullptr)
	{
		return;
	}

	if (action->run())
	{
	}
}

void Player::runActionWithRecord( IRecordAction* action )
{
	if (action == nullptr)
	{
		return;
	}

	if (action->run())
	{
		action->saveRecord();
	}
}