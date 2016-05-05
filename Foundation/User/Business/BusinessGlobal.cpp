#include "BusinessGlobal.h"
#include "BusinessLogger.h"
#include "BusinessDataBase.h"

using namespace user;


DEFINE_GLOBAL_INSTANCE_MEMBER(Loggers, Loggers);

DEFINE_GLOBAL_INSTANCE_MEMBER(DataBases, DataBases);


// void BusinessGlobal::init()
// {
// 	// init logger
// 	new BusinessLogger(LOGGER_TYPE_ACCOUNT, LOGGER_FILE_ACCOUNT);
// 
// 	// init data
// 	new BusinessDataBase(DATABASE_TYPE_PLAYER, DATABASE_FILE_PLAYER);
// }


