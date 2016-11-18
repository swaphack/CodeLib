// #ifdef _DEBUG
// #define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
// #else
// #define DEBUG_CLIENTBLOCK
// #endif  // _DEBUG
// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>
// #ifdef _DEBUG
// #define new DEBUG_CLIENTBLOCK
// #endif  // _DEBUG

//#include <vld.h>

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

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
	GateWay* gateWay = new GateWay(
		config->getValue("server.local", "ip"), 
		atoi(config->getValue("server.local", "port")), 
		10000);

	gateWay->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	
	gateWay->createGameServerListener(
		config->getValue("server.gameserver", "ip"),
		atoi(config->getValue("server.gameserver", "port")));

	delete config;

	// 注册监听
	new HttpActivityReceiver();
	new PacketActivityReceiver();

	while (true)
	{
		Sleep(10);
		gateWay->update();
	}

	delete gateWay;

	_CrtDumpMemoryLeaks();

	return 0;
};