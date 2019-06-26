#include "DBStructFile.h"
#include "../Tool/import.h"
#include "system.h"

using namespace db;
using namespace sys;

void createStructStream( const DBTable* dbTable, StreamWriter& writer )
{
	if (dbTable == nullptr)
	{
		return;
	}
	writer.writeString("struct ");
	writer.writeString(dbTable->getName());
	writer.writeString("\n");
	writer.writeString("{\n");
	writer.writeString("public:\n");
	const std::vector<DBField*>& fields = dbTable->getMemoryFields();
	std::vector<DBField*>::const_iterator iter = fields.begin();
	std::string value;
	while (iter != fields.end())
	{
		writer.writeString("\t");
		DBHelper::getTypeString((*iter)->getType(), value);
		writer.writeString(value.c_str());
		writer.writeString(" ");
		writer.writeString((*iter)->getName());
		if ((*iter)->getType() == EFT_STRING)
		{
			writer.writeString("[");
			sys::BitConvert::getNumberString((*iter)->getLength(), value);
			writer.writeString(value.c_str());
			writer.writeString("]");
		}
		writer.writeString(";\n");

		iter++;
	}
	writer.writeString("};\n");
}

void DBStructFile::createStructCPPFile( const char* filename, const std::map<std::string, DBTable>& structFiles )
{
	if (filename == nullptr)
	{
		return;
	}

	StreamWriter writer;
	writer.writeString("#pragma once\n");

	std::map<std::string, DBTable>::const_iterator iter = structFiles.begin();
	while (iter != structFiles.end())
	{
		createStructStream(&iter->second, writer);
		iter++;
	}
	int64 writtenSize = 0;
	File::write(filename, writer.getData(), writer.getLength(), writtenSize);
}

//////////////////////////////////////////////////////////////////////////

void DBStructFile::readTableStruct( const char* filename, std::map<std::string, DBTable>& dbTables )
{
	if (filename == nullptr)
	{
		return;
	}
	DBFileReader reader;
	reader.load(filename);
	
	uint32 count = reader.readUInt32();
	for (int i = 0; i < count; i++)
	{
		DBTable dbTable;
		dbTable.setName(reader.readDBString().c_str());

		uint32 size = reader.readInt32();
		for (int j = 0; j < size; j++)
		{
			std::string key = reader.readDBString();
			FieldType type = (FieldType)reader.readInt8();
			dbTable.addField(key.c_str(), type);
		}

		size = reader.readInt32();
		for (int j = 0; j < size; j++)
		{
			std::string key = reader.readDBString();
			dbTable.addKey(key.c_str());
		}

		dbTables[dbTable.getName()] = dbTable;
	}
}

void DBStructFile::writeTableStruct( const char* filename, const std::map<std::string, DBTable>& dbTables )
{
	DBFileWriter writer;
	writer.writeInt32(dbTables.size());

	std::map<std::string, DBTable>::const_iterator iter = dbTables.begin();
	while (iter != dbTables.end())
	{
		const DBTable& dbTable = iter->second;
		std::string name = dbTable.getName();
		writer.writeDBString(name);

		const std::vector<DBField*>& fields = dbTable.getMemoryFields();
		writer.writeInt32(fields.size());
		std::vector<DBField*>::const_iterator memeberIter = fields.begin();
		while (memeberIter != fields.end())
		{
			std::string key = (*memeberIter)->getName();
			char type = (*memeberIter)->getType();
			writer.writeDBString(key);
			writer.writeInt8(type);
			memeberIter++;
		}

		const std::set<std::string>& keys = dbTable.getKeys();
		writer.writeInt32(keys.size());
		std::set<std::string>::const_iterator keyIter = keys.begin();
		while (keyIter != keys.end())
		{
			std::string key = (*keyIter);
			writer.writeDBString(key);
			keyIter++;
		}
		iter++;
	}

	int64 writtenSize = 0;
	File::write(filename, writer.getData(), writer.getLength(), writtenSize);
}
//////////////////////////////////////////////////////////////////////////
void DBStructFile::createStructCode( std::string headFilename, const DBContent* content )
{
	createStructCPPFile(headFilename.c_str(), content->getTables());
}

void DBStructFile::saveContent( std::string filename, const DBContent* content )
{
	writeTableStruct(filename.c_str(), content->getTables());
}

void DBStructFile::loadContent(std::string configFilename, DBContent* content)
{
	std::map<std::string, DBTable> dbTables;

	readTableStruct(configFilename.c_str(), dbTables);

	std::map<std::string, DBTable>::iterator iter = dbTables.begin();

	while (iter != dbTables.end())
	{
		content->addTable(iter->second);
		iter++;
	}
}
