#include "IDEConfig.h"


const ue::IDEConfig::TextSetting& ue::IDEConfig::getText() const
{
	return _text;
}

const ue::IDEConfig::IDESetting& ue::IDEConfig::getIDE() const
{
	return _ide;
}

const ue::IDEConfig::ShaderSetting& ue::IDEConfig::getShader() const
{
	return _shader;
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

		child = element->FirstChildElement("Control");
		if (child && child->GetText())
		{
			_ide.Control = child->GetText();
		}
	}
	element = _helper.getElement("Shader");
	if (element)
	{
		auto child = element->FirstChildElement("TexVertex");
		if (child && child->GetText())
		{
			_shader.TexVertex = child->GetText();
		}

		child = element->FirstChildElement("TexFragment");
		if (child && child->GetText())
		{
			_shader.TexFragment = child->GetText();
		}
		child = element->FirstChildElement("ColorVertex");
		if (child && child->GetText())
		{
			_shader.ColorVertex = child->GetText();
		}

		child = element->FirstChildElement("ColorFragment");
		if (child && child->GetText())
		{
			_shader.ColorFragment = child->GetText();
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
