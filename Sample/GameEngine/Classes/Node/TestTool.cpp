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
	this->packImageTexture();
	this->packTextTexture();
}

void TestTool::packImageTexture()
{
	std::string root = "H:/Github/CodeLib/Sample/GameEngine/Resource/";

	tool::ImageAtlasPacker packer;
	packer.setReverseY(true);
	packer.addDirectory(root + "/UI");
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/ui.png", root + "/ATLAS/ui.atlas");
}

void TestTool::packTextTexture()
{
	std::string root = "H:/Github/CodeLib/Sample/GameEngine/Resource/";

	tool::TextAtlasPacker packer;
	packer.setReverseY(false);
	packer.setText("qertyuiopasdfghjklzxcvbnm1234567890-=[]\;',./`~!@#$%^&*()_+{}|:\"<>?", root + "Font/font_3.ttf", 32);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text.png", root + "/ATLAS/text.atlas");
}
