#include "AccountAction.h"

using namespace user;
using namespace test;

AccountAction::AccountAction( long playerID, const char* name )
:BLLAction(playerID, ACTION_TYPE_ACCOUNT, name)
{

}

//////////////////////////////////////////////////////////////////////////
AccountActionLogin::AccountActionLogin( long playerID )
:AccountAction(playerID, ACCOUNT_ACTION_LOGIN)
{
	
}


bool AccountActionLogin::run()
{
	IPlayer* player = this->getPlayer();

	return true;
}