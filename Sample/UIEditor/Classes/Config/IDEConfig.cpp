#include "IDEConfig.h"


const ue::IDEConfig::TextSetting& ue::IDEConfig::getText() const
{
	return _text;
}

const ue::IDEConfig::IDESetting& ue::IDEConfig::getIDE() const
{
	return _ide;
}

void ue::IDEConfig::Dispose()
{
}

void ue::IDEConfig::loadXml(const std::string& filepath)
{
	this->Dispose();

	if (!_helper.loadFile(filepath.c_str()))
	{
		return;
	}

	auto element = _helper.getElement("IDE");
	if (element)
	{
		auto child = element->FirstChildElement("Design");
		if (child && child->GetText())
		{
			_ide.Design = child->GetText();
		}
	}
	element = _helper.getElement("Text");
	if (element)
	{
		auto child = element->FirstChildElement("FontPath");
		if (child && child->GetText())
		{
			_text.FontPath = child->GetText();
		}

		child = element->FirstChildElement("FontSize");
		if (child && child->GetText())
		{
			_text.FontSize = atoi(child->GetText());
		}
		child = element->FirstChildElement("TextColor");
		if (child && child->GetText())
		{
			sys::ColorConvert::convertToColor(child->GetText(), _text.TextColor);
		}
	}
}
