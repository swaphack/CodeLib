#include "TextAtlasPacker.h"
#include "system.h"

tool::TextAtlasPacker::TextAtlasPacker()
{
}

tool::TextAtlasPacker::~TextAtlasPacker()
{
}

void tool::TextAtlasPacker::setText(const std::string& content, const std::string& fontFilePath, int fontSize)
{
    _textDefine.text = content;
    _textDefine.fontSize = fontSize;
    _textDefine.filepath = fontFilePath;
}

void tool::TextAtlasPacker::loadTextDetails(std::map<std::string, sys::ImageDetail*>& mapDetails)
{
	G_FONT_LIB->load(_textDefine, mapDetails);
}

bool tool::TextAtlasPacker::packImage(const std::string& imgFilePath, const std::string& atlasFilePath)
{
    std::map<std::string, sys::ImageDetail*> mapDetails;
	loadTextDetails(mapDetails);
	if (mapDetails.size() == 0) return false;

	saveTexAltas(imgFilePath, atlasFilePath, mapDetails);

	for (auto& item : mapDetails)
	{
		SAFE_RELEASE(item.second);
	}

	return true;
}

