#include "TestTexturePack.h"
#include "toollib.h"
TestTexturePack::TestTexturePack()
{
}

TestTexturePack::~TestTexturePack()
{
}

void TestTexturePack::initNodes()
{
	this->packImageTexture();
	this->packEnglishTexture();
	this->packChineseTexture();
}

void TestTexturePack::packImageTexture()
{
	std::string root = "H:/Github/CodeLib/Sample/GameEngine/Resource/";

	tool::ImageAtlasPacker packer;
	packer.setAutoRotate(true);
	packer.setReverseY(true);

	packer.setAtlas("ui.png", "ui.atlas");
	packer.addDirectory(root + "/UI");
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/ui.png", root + "/ATLAS/ui.atlas");
}

void TestTexturePack::packEnglishTexture()
{
	std::string root = "H:/Github/CodeLib/Sample/UIEditor/Default/";

	std::string text = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890-=[]\\;',./`~!@#$%^&*()_+{}|:\"<>?";

	tool::TextAtlasPacker packer;
	packer.setAutoRotate(false);
	packer.setReverseY(true);

	packer.setAtlas("text20.png", "text20.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 20);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text20.png", root + "/ATLAS/text20.atlas");

	packer.setAtlas("text22.png", "text22.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 22);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text22.png", root + "/ATLAS/text22.atlas");

	packer.setAtlas("text32.png", "text32.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 32);
	packer.setSize(512, 512);
	packer.packImage(root + "/ATLAS/text32.png", root + "/ATLAS/text32.atlas");
}

void TestTexturePack::packChineseTexture()
{
	std::string path = G_FILEPATH->getFilePath("Resource/Text/cn_3500.txt");
	std::string text;
	if (!sys::File::read(path, text))
	{
		return;
	}

	std::string root = "H:/Github/CodeLib/Sample/UIEditor/Default/";
	tool::TextAtlasPacker packer;
	packer.setAutoRotate(false);
	packer.setReverseY(true);

	packer.setAtlas("text_cn32.png", "text_cn32.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 32);
	packer.setSize(2048, 2048);
	packer.packImage(root + "/ATLAS/text_cn32.png", root + "/ATLAS/text_cn32.atlas");

	packer.setAtlas("text_cn22.png", "text_cn22.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 22);
	packer.setSize(2048, 1024);
	packer.packImage(root + "/ATLAS/text_cn22.png", root + "/ATLAS/text_cn22.atlas");

	packer.setAtlas("text_cn20.png", "text_cn20.atlas");
	packer.setText(text, root + "Font/font_3.ttf", 20);
	packer.setSize(2048, 1024);
	packer.packImage(root + "/ATLAS/text_cn20.png", root + "/ATLAS/text_cn20.atlas");
}