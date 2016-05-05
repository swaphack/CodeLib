#include "BLLAction.h"

using namespace test;
using namespace user;

BLLAction::BLLAction( long playerID, long type, const char* name )
	:BusinessAction(playerID, type, name)
{

}

ILogger* BLLAction::getLogger()
{
	Loggers* dict = GET_GLOBAL_INSTANCE(Loggers);
	ILogger* logger = dict->getLogger(this->getType());

	return logger;
}

IPlayer* BLLAction::getPlayer()
{
	DataBases* dbs = GET_GLOBAL_INSTANCE(DataBases);
	IDBRecord* record = dbs->getDataBase(DATABASE_TYPE_PLAYER)->getRecord(this->getPlayerID());
	if (record == nullptr)
	{
		return nullptr;
	}

	IPlayer* player = record->getStatic<IPlayer>();

	return player;
}
