#include "TestTool.h"
#include "toollib.h"
TestTool::TestTool()
{
}

TestTool::~TestTool()
{
}

void TestTool::initNodes()
{
	this->testTexturePack();
}

void TestTool::testTexturePack()
{
	std::string root = "H:/Github/CodeLib/Sample/GameEngine/Resource/";

	tool::TexturePacker packer;
	packer.addDirectory(root + "/UI");
	//packer.addImage("H:/Github/CodeLib/Sample/UIEditor/Resource/Image/ExampleDiffuseAmbientLighting.png");
	packer.setSize(512, 512);
	packer.packPNG(root + "/ATLAS/ui.png", root + "/ATLAS/ui.atlas");
}
