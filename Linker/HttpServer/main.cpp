#include "Server/HttpServer.h"
#include "text.h"
#include "system.h"

#include <ctime>
#include <windows.h>
#include <string>

using namespace sys;

int main(int argc, char** argv)
{
	// ����·��
	std::string projectPath;
	Directory::getCurrentDirectory(projectPath);

	// ����������·��
	std::string configPath = projectPath + "/Resource/Server.xml";
	XmlConfig* config = new XmlConfig();
	if (!config->loadFile(configPath.c_str()))
	{
		return -1;
	}

	// ������
	hs::HttpServer* HttpServer = new hs::HttpServer(
		config->getValue("server.local", "ip"),
		atoi(config->getValue("server.local", "port")),
		10000);

	HttpServer->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	delete config;

	// ע�����
	new PacketReceiver();

	while (true)
	{
		Sleep(10);
		HttpServer->update();
	}

	delete HttpServer;

	return 0;
}