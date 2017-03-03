#include "DataBase.h"
#include "system.h"

using namespace db;


DBConfig::DBConfig()
{
	//this->reset();
}

void DBConfig::reset()
{
	dbStructFilepath = "";
	dbTableFilepath = "";
	dbDataFilepath = "";
}

void DBConfig::load( const char* configFilepath )
{
	DBFileReader reader(configFilepath);
	dbStructFilepath = reader.readDBString();
	dbTableFilepath = reader.readDBString();
	dbDataFilepath = reader.readDBString();
}

void DBConfig::save( const char* configFilepath )
{
	DBFileWriter writer;
	writer.writeDBString(dbStructFilepath);
	writer.writeDBString(dbTableFilepath);
	writer.writeDBString(dbDataFilepath);
	writer.save(configFilepath);
}

//////////////////////////////////////////////////////////////////////////
DataBase::DataBase()
{

}

DataBase::~DataBase()
{

}

DBContent* DataBase::getContent()
{
	return &_content;
}

DBWarehouse* DataBase::getWarehouse()
{
	return &_warehouse;
}


DBConfig* DataBase::getConfig()
{
	return &this->_config;
}

void DataBase::loadDB( const char* configFilepath )
{
	if (configFilepath == nullptr)
	{
		return;
	}

	DBConfig config;
	config.load(configFilepath);

	this->loadDB(config);
}

void DataBase::loadDB(const DBConfig& dbConfig)
{
	_config = dbConfig;
	if (!_config.dbTableFilepath.empty())
	{
		this->loadContent(_config.dbTableFilepath.c_str());
	}

	if (!_config.dbDataFilepath.empty())
	{
		this->loadData(_config.dbDataFilepath.c_str());
	}
}

void db::DataBase::saveDB(const char* configFilepath)
{
	if (configFilepath == nullptr)
	{
		return;
	}

	if (!_config.dbTableFilepath.empty())
	{
		this->saveContent(_config.dbTableFilepath.c_str());
	}

	if (!_config.dbDataFilepath.empty())
	{
		this->saveData(_config.dbDataFilepath.c_str());
	}

	_config.save(configFilepath);
}

void DataBase::loadContent( const char* filepath )
{
	_content.removeAllTables();
	DBCode::loadContent(filepath, &_content);
}

void DataBase::loadData( const char* filepath )
{
	_warehouse.removeAllSheets();

	std::map<std::string, std::string> configs;
	DBStorage::readDataConfig(filepath, configs);

	DBTable* table = nullptr;
	std::map<std::string, std::string>::iterator configIter = configs.begin();
	while (configIter != configs.end())
	{
		table = (DBTable*)_content.getTable(configIter->first.c_str());
		if (table)
		{
			DBSheet* sheet = new DBSheet();
			DBStorage::loadSheetFromFile(configIter->second.c_str(), table, sheet);
			_warehouse.addSheet(configIter->first.c_str(), sheet);
		}
		configIter++;
	}
}

void DataBase::saveContent( const char* filepath )
{
	DBCode::saveContent(filepath, &_content);
}

void DataBase::saveData( const char* filepath )
{
	DBTable* table = nullptr;
	std::map<std::string, std::string> configs;

	const std::map<std::string, DBTable>& tables = _content.getTables();
	std::map<std::string, DBTable>::const_iterator tableIter = tables.begin();

	std::string fullpath;
	Directory::getDirectory(filepath, fullpath);

	while (tableIter != tables.end())
	{
		std::string name = tableIter->first;
		std::string path = fullpath + tableIter->first;
		DBStorage::saveSheetToFile(path.c_str(), &tableIter->second, _warehouse.getSheet(name.c_str()));
		configs[name] = path;
		tableIter++;
	}

	DBStorage::writeDataConfig(filepath, configs);
}




