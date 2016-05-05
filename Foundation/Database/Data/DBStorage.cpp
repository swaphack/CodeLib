#include "DBStorage.h"

using namespace db;

using namespace sys;

//////////////////////////////////////////////////////////////////////////

void DBStorage::readDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs)
{
	DBFileReader reader = DBFileReader(filename);

	int count = reader.readUInt();
	for (int i = 0; i < count; i++)
	{
		std::string key = reader.readDBString();
		std::string value = reader.readDBString();

		dbConfigs[key] = value;
	}
}

void DBStorage::writeDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs)
{
	DBFileWriter writer;
	writer.writeInt(dbConfigs.size());

	std::map<std::string, std::string>::const_iterator iter = dbConfigs.begin();
	while (iter != dbConfigs.end())
	{
		std::string name = iter->first;
		std::string path = iter->second;
		writer.writeDBString(name);
		writer.writeDBString(path);

		iter++;
	}

	File::write(filename, writer.getData(), writer.getLength());
}
//////////////////////////////////////////////////////////////////////////

void DBStorage::loadSheetFromFile( const char* filename, DBSheet* sheet )
{
	if (filename == nullptr)
	{
		return;
	}

	long size = 0;
	char* data = File::read(filename, size);
	if (data == nullptr)
	{
		return;
	}

	long offset = 0;
	long length = 0;

	while (offset < size)
	{
		length = 0;
		DBRecord* record = new DBRecord();
		record->loadText(sheet->getTable(), data + offset, length);
		sheet->addRecord(record);
		offset += length;
	}

	SAFE_FREE(data);
}

void DBStorage::saveSheetToFile( const char* filename, const DBSheet* sheet )
{
	if (filename == nullptr || sheet == nullptr)
	{
		return;
	}

	StreamWriter writer;

	std::map<int, DBRecord*>::const_iterator beginIter = sheet->beginRecord();
	std::map<int, DBRecord*>::const_iterator endIter = sheet->endRecord();

	while (beginIter != endIter)
	{
		std::string data;
		beginIter->second->makeText(sheet->getTable(), data);
		writer.writeString((char*)data.c_str(), (int)data.size());
		beginIter++;
	}

	File::write(filename, writer.getData(), writer.getLength());
	
}

int DBStorage::getHashKey(const DBTable* table, DBRecord* record, int defaultKey)
{
	if (table == nullptr || record == nullptr)
	{
		return defaultKey;
	}

	std::string data = "";

	const std::set<std::string>& keys = table->getKeys();
	const std::map<std::string, DBField*>& fields = table->getFields();

	std::map<std::string, DBField*>::const_iterator fieldIter = fields.begin();
	std::set<std::string>::const_iterator keyIter = keys.begin();

	while (fieldIter != fields.end())
	{
		keyIter = keys.begin();
		while (keyIter != keys.end())
		{
			if ((*keyIter) == fieldIter->first)
			{
				std::string value;
				record->getFieldValue((*keyIter).c_str(), value);
				data += value;
			}

			keyIter++;
		}
		fieldIter++;
	}

	if (data.empty())
	{
		return defaultKey;
	}

	return Hash::getBKDRHash((char*)data.c_str());
}
