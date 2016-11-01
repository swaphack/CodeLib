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
	// ����·��
	std::string projectPath;
	Directory::getCurrentDirectory(projectPath);

	// ����������·��
	std::string configPath = projectPath + "/Resource/GateWay.xml";
	XmlConfig* config = new XmlConfig();
	if (!config->loadFile(configPath.c_str()))
	{
		return -1;
	}

	// ������
	GateWay* web = new GateWay(
		config->getValue("server.local", "ip"), 
		atoi(config->getValue("server.local", "port")), 
		10000);

	web->getResourceMgr()->getResource(ERT_LOCAL)->setUrl(config->getValue("resource.websit", "path"));

	// ע�����
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