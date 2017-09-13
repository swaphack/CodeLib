#include "Server/import.h"
#include "Module/import.h"

#include "text.h"
#include "system.h"

#include <ctime>
#include <windows.h>
#include <string>

using namespace sys;

hs::HttpServer* initSock(XmlConfig* config)
{
	hs::HttpServer* httpServer = new hs::HttpServer(
		config->getValue("server.local", "ip"),
		atoi(config->getValue("server.local", "port")),
		10000);

	// 网站本地资源路径
	httpServer->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	// 注册监听
	new hs::HttpReceiver();

	httpServer->run(10);

	return httpServer;
}

void initDataBase(XmlConfig* config)
{
	std::string host = config->getValue("database.url", "host");
	const char* strPort = config->getValue("database.url", "port");
	int port = strPort ? atoi(strPort) : 0;
	std::string username = config->getValue("database.url", "username");
	std::string password = config->getValue("database.url", "password");
	std::string dbname = config->getValue("database.url", "dbname");
	const char* strType = config->getValue("database.url", "type");
	int dbType = strType ? atoi(strType) : 0;

	web::DBAuthor dbInfo(host, port, username, password, dbname);
	if (hs::DBManager::getInstance()->init(dbInfo, dbType))
	{
		sys::String tables = config->getValue("database.table", "names");
		std::vector<std::string> tableAry;
		tables.split(';', tableAry);

		std::map<std::string, std::string> tableKeyMap;

		for (size_t i = 0; i < tableAry.size(); i++)
		{
			sys::String table = tableAry[i];
			std::vector<std::string> tableKey;
			table.split(',', tableKey);
			tableKeyMap[tableKey[0]] = tableKey[1];
		}

		hs::DBManager::getInstance()->load(tableKeyMap);
	}
}

int main(int argc, char** argv)
{
	// 工程路径
	std::string projectPath;
	Directory::getCurrentDirectory(projectPath);

	// 服务器配置路径
	std::string configPath = projectPath + "/Resource/Server.xml";
	XmlConfig* config = new XmlConfig();
	if (!config->loadFile(configPath.c_str()))
	{
		return -1;
	}
	// 数据库
	initDataBase(config);
	// 服务器
	hs::HttpServer* httpServer = initSock(config);

	delete config;

	httpServer->run(10);
	delete httpServer;

	return 0;
}