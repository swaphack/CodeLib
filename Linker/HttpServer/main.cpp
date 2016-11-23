#include "Server/HttpServer.h"
#include "text.h"
#include "system.h"

#include <ctime>
#include <windows.h>
#include <string>

using namespace sys;

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

	// 服务器
	hs::HttpServer* HttpServer = new hs::HttpServer(
		config->getValue("server.local", "ip"),
		atoi(config->getValue("server.local", "port")),
		10000);

	HttpServer->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	delete config;

	// 注册监听
	new PacketReceiver();

	while (true)
	{
		Sleep(10);
		HttpServer->update();
	}

	delete HttpServer;

	return 0;
}