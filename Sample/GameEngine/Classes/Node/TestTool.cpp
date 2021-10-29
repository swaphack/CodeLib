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
	std::string root = "H:/Github/CodeLib/Sample/UIEditor/Default/";

	std::string text = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm234567890-=[]\;',./`~!@#$%^&*()_+{}|:\"<>?";

	tool::TextAtlasPacker packer;
	packer.setReverseY(false);
	packer.setText(text, root + "Font/font_3.ttf", 20);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text20.png", root + "/ATLAS/text20.atlas");

	packer.setText(text, root + "Font/font_3.ttf", 22);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text22.png", root + "/ATLAS/text22.atlas");

	packer.setText(text, root + "Font/font_3.ttf", 32);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text32.png", root + "/ATLAS/text32.atlas");
}
