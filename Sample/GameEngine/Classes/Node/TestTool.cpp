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
	tool::TexturePacker packer;
	packer.addDirectory("H:/Github/CodeLib/Sample/GameEngine/Resource/UI");
	//packer.addImage("H:/Github/CodeLib/Sample/UIEditor/Resource/Image/ExampleDiffuseAmbientLighting.png");
	packer.setSize(512, 512);
	packer.packPNG("H:/Github/CodeLib/Sample/GameEngine/Resource/ATLAS/ui");
}
