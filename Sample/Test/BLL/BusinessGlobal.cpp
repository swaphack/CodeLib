#include "user.h"

#include "BusinessMacros.h"

using namespace user;

void BusinessGlobal::init()
{
	// init logger
	new BusinessLogger(LOGGER_TYPE_ACCOUNT, LOGGER_FILE_ACCOUNT);

	// init data
	new BusinessDataBase(DATABASE_TYPE_PLAYER, DATABASE_FILE_PLAYER);

	// init logic
}