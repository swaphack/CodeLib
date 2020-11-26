#include "IDEConfig.h"


inline const ue::IDEConfig::Text& ue::IDEConfig::getText() const
{
	return _text;
}

void ue::IDEConfig::loadXml(const std::string& filepath)
{
	if (!_helper.loadFile(filepath.c_str()))
	{
		return;
	}

	auto element = _helper.getElement("root.text");
	if (element)
	{
		if (element->Attribute("fontPath"))
		{
			_text.FontPath = element->Attribute("fontPath");
		}
		if (element->Attribute("fontSize"))
		{
			_text.FontSize = element->IntAttribute("fontSize");
		}
		if (element->Attribute("textColor"))
		{
			//_text.TextColor = 
		}
	}
}
