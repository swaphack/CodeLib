#include "DBStorage.h"
#include "../Tool/DBFile.h"

using namespace db;

using namespace sys;

//////////////////////////////////////////////////////////////////////////

void DBStorage::readDataConfig(const char* filename, std::map<std::string, std::string>& dbConfigs)
{
	DBFileReader reader;

	if (!reader.load(filename))
	{
		return;
	}

	dbConfigs.clear();
	uint32_t count = reader.readUInt32();
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
	writer.writeUInt32(dbConfigs.size());

	std::map<std::string, std::string>::const_iterator iter = dbConfigs.begin();
	while (iter != dbConfigs.end())
	{
		std::string name = iter->first;
		std::string path = iter->second;
		writer.writeDBString(name);
		writer.writeDBString(path);

		iter++;
	}

	int64_t writtenSize = 0;
	File::write(filename, writer.getData(), writer.getLength(), writtenSize);
}
//////////////////////////////////////////////////////////////////////////

void DBStorage::loadSheetFromFile(const char* filename, const DBTable* table, DBSheet* sheet)
{
	if (filename == nullptr || table == nullptr || sheet == nullptr)
	{
		return;
	}

	int64_t size = 0;
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
		record->loadText(table, data + offset, length);
		sheet->addRecord(record);
		offset += length;
	}

	SAFE_FREE(data);
}

void DBStorage::saveSheetToFile(const char* filename, const DBTable* table, const DBSheet* sheet)
{
	if (filename == nullptr || table  == nullptr || sheet == nullptr)
	{
		return;
	}

	StreamWriter writer;

	int count = ((DBSheet*)sheet)->count();

	for (int i = 0; i < count; i++)
	{
		DBRecord* record = ((DBSheet*)sheet)->getRecord(i);
		std::string data;
		record->makeText(table, data);
		writer.writeString((char*)data.c_str(), (int)data.size());
	}
	int64_t writtenSize = 0;
	File::write(filename, writer.getData(), writer.getLength(), writtenSize);
	
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
