#include "GateWay/import.h"
#include "text.h"
#include "system.h"

#include <ctime>
#include <windows.h>
#include <string>

using namespace gw;
using namespace sys;

int main(int argc, char** argv)
{
	// 工程路径
	std::string projectPath;
	Directory::getCurrentDirectory(projectPath);

	// 服务器配置路径
	std::string configPath = projectPath + "/Resource/GateWay.xml";
	XmlConfig* config = new XmlConfig();
	if (!config->loadFile(configPath.c_str()))
	{
		return -1;
	}

	// 服务器
	GateWay* web = new GateWay(
		config->getValue("server.local", "ip"), 
		atoi(config->getValue("server.local", "port")), 
		10000);

	web->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	// 注册监听
	new HttpActivityTest();
	new PacketActivityTest();

	while (true)
	{
		Sleep(100);
		web->update();
	}

	delete web;

	return 0;
};