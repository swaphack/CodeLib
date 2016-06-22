#pragma once

#include "user.h"

using namespace user;

namespace test
{
	// action type
	#define ACTION_TYPE_ACCOUNT 1

	// action
	#define ACCOUNT_ACTION_CREATE	"create_account"
	#define ACCOUNT_ACTION_DELETE	"delete_account"
	#define ACCOUNT_ACTION_LOGIN	"login_account"
	#define ACCOUNT_ACTION_LOGOUT	"logout_account"


	// logger
	#define LOGGER_TYPE_ACCOUNT 1
	#define LOGGER_FILE_ACCOUNT		"log_account.txt"

	// database
	#define DATABASE_TYPE_PLAYER 1
	#define DATABASE_FILE_PLAYER	"db_player.txt"


	// logic
	DATABASE_DEFINE(Player, IPlayer);

}