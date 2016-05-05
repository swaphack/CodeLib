/*
#include "system.h"
#include "db.h"

#include <string>

using namespace db;
using namespace sys;

const std::string FILE_PATH_CONFIG = "config.txt";
const std::string FILE_PATH_STRUCT = "struct.txt";
const std::string FILE_PATH_TABLE = "content.txt";
const std::string FILE_PATH_DATA = "data.txt";

void db_create_table(DataBase* db)
{
	// 创建表结构
	DBTable t1;
	t1.setName("UserInfo");
	t1.addField("ID", EFT_UINT, true);
	t1.addField("Name", EFT_STRING, 50);
	t1.addField("BirthDay", EFT_STRING, 50);

	DBTable t2;
	t2.setName("Career");
	t2.addField("ID", EFT_UINT);
	t2.addField("Age", EFT_UCHAR);
	t2.addField("Work", EFT_USHORT);

	db->getContent()->addTable(t1);
	db->getContent()->addTable(t2);
}

void db_create_Data(DataBase* db)
{
	// 创建表数据结构
	DBSheet* sheet;
	DBTable* table;

	table = (DBTable*)db->getContent()->getTable("UserInfo");
	sheet = new DBSheet(table);
	db->getWarehouse()->addSheet(table->getName(), sheet);

	table = (DBTable*)db->getContent()->getTable("Career");
	sheet = new DBSheet(table);
	db->getWarehouse()->addSheet(table->getName(), sheet);


	DBRecord* record;

	sheet = db->getWarehouse()->getSheet("UserInfo");
	record = new DBRecord();
	record->loadTable(sheet->getTable());
	record->setFieldValue("ID", 1);
	record->setFieldValue("Name", "haha");
	record->setFieldValue("BirthDay", "1526");
	sheet->addRecord(record);


	sheet = db->getWarehouse()->getSheet("Career");
	record = new DBRecord();
	record->loadTable(sheet->getTable());
	record->setFieldValue("ID", 1);
	record->setFieldValue("Age", (uchar)12);
	record->setFieldValue("Work", (ushort)5);
	sheet->addRecord(record);
}

void init_db(DataBase* db)
{
	db_create_table(db);
	db_create_Data(db);

	db->getConfig()->dbStructFilepath = FILE_PATH_STRUCT.c_str();
	db->getConfig()->dbTableFilepath = FILE_PATH_TABLE.c_str();
	db->getConfig()->dbDataFilepath = FILE_PATH_DATA.c_str();
	db->getConfig()->save(FILE_PATH_CONFIG.c_str());

	db->saveDB(FILE_PATH_CONFIG.c_str());
}


int main()
{
	DataBase* db = new DataBase();

	init_db(db);

	db->loadDB(FILE_PATH_CONFIG.c_str());

	delete db;
	return 0;
};
*/