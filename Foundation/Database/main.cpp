#include "DataBase.h"


const char* dbFilePath = "/Resource/db.txt";

void createDB()
{
	std::string curDir;
	sys::Directory::getCurrentDirectory(curDir);

	db::DataBase* pDataBase = new db::DataBase();
	db::DBConfig* pConfig = pDataBase->getConfig();
	pConfig->dbStructFilepath = "struct.db";
	pConfig->dbTableFilepath = "table.db";
	pConfig->dbDataFilepath = "data.db";

	pDataBase->saveDB(curDir + dbFilePath);

	delete pDataBase;
}

int main(int argc, char** argv)
{

	return 0;
}