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
	packer.addDirectory("H:/Github/CodeLib/Sample/UIEditor/Default/Image");
	packer.addImage("H:/Github/CodeLib/Sample/UIEditor/Resource/Image/ExampleDiffuseAmbientLighting.png");
	packer.setSize(1024, 1024);
	packer.pack("H:/Github/CodeLib/Sample/GameEngine/Resource/texture_pack");
}
