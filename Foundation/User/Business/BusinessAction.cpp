#include "BusinessAction.h"

#include "BusinessGlobal.h"

using namespace user;

BusinessAction::BusinessAction( long playerID, long type, const char* name )
	:_playerID(playerID)
	,_type(type)
	,_name(name)
{

}

long BusinessAction::getPlayerID()
{
	return _playerID;
}

long BusinessAction::getType()
{
	return _type;
}

const char* BusinessAction::getName()
{
	return _name.c_str();
}

void BusinessAction::saveRecord()
{
	ILogger* logger = this->getLogger();
	if (logger)
	{
		ILoggerRecord* record = this->generateRecord();	
		logger->addRecord(record);
	}
}

const char* BusinessAction::getActionString()
{
	char text[255] = {0};

	sprintf(text, "%ld %ld %s", _playerID, _type, _name);

	return text;
}

ILogger* BusinessAction::getLogger()
{
// 	Loggers* dict = GET_GLOBAL_INSTANCE(Loggers);
// 	ILogger* logger = dict->getLogger(this->getType());
// 
// 	return logger;

	return nullptr;
}

IPlayer* BusinessAction::getPlayer()
{
// 	DataBases* dbs = GET_GLOBAL_INSTANCE(DataBases);
// 	IDBRecord* record = dbs->getDataBase(DATABASE_TYPE_PLAYER)->getRecord(this->getPlayerID());
// 	if (record == nullptr)
// 	{
// 		return nullptr;
// 	}
// 
// 	IPlayer* player = record->getStatic<IPlayer>();
// 
// 	return player;

	return nullptr;
}

void BusinessAction::doAction(bool bLogger)
{
	IPlayer* player = this->getPlayer();
	if (player == nullptr)
	{
		delete this;
		return;
	}

	if (bLogger)
	{
		player->runActionWithRecord(this);
	}
	else
	{
		player->runAction(this);
	}

	delete this;
}
