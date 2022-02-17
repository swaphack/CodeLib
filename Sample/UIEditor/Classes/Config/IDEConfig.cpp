#include "IDEConfig.h"

ue::IDEConfig::IDEConfig()
{

}
ue::IDEConfig::~IDEConfig()
{
	Dispose();
}
const ue::IDEConfig::TextSetting& ue::IDEConfig::getText() const
{
	return _text;
}

const ue::IDEConfig::IDESetting& ue::IDEConfig::getIDE() const
{
	return _ide;
}

const ue::IDEConfig::ShaderSetting* ue::IDEConfig::getShader() const
{
	auto it = _shaders.find(_ide.ShaderMode);
	if (it == _shaders.end()) return nullptr;
	return it->second;
}

void ue::IDEConfig::Dispose()
{
	for (auto item : _shaders)
	{
		delete item.second;
	}
	_shaders.clear();
}

void ue::IDEConfig::loadXml(const std::string& filepath)
{
	this->Dispose();

	if (!_helper.loadFile(filepath.c_str()))
	{
		return;
	}

	auto element = _helper.getElement("Shader");
	if (element)
	{
		auto item = element->FirstChildElement();
		while (item != nullptr)
		{
			auto attribute = item->Attribute("mode");
			if (attribute)
			{
				int type = atoi(attribute);
				ShaderSetting* pShader = new ShaderSetting();

				auto child = item->FirstChildElement("TexVertex");
				if (child && child->GetText())
				{
					pShader->TexVertex = child->GetText();
				}

				child = item->FirstChildElement("TexFragment");
				if (child && child->GetText())
				{
					pShader->TexFragment = child->GetText();
				}
				child = item->FirstChildElement("ColorVertex");
				if (child && child->GetText())
				{
					pShader->ColorVertex = child->GetText();
				}

				child = item->FirstChildElement("ColorFragment");
				if (child && child->GetText())
				{
					pShader->ColorFragment = child->GetText();
				}
				_shaders.insert(std::make_pair(type, pShader));
			}
			item = item->NextSiblingElement();
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

	element = _helper.getElement("IDE");
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
		child = element->FirstChildElement("ShaderMode");
		if (child && child->GetText())
		{
			_ide.ShaderMode = atoi(child->GetText());
		}
		child = element->FirstChildElement("DebugMode");
		if (child && child->GetText())
		{
			_ide.DebugMode = atoi(child->GetText());
		}
	}
}
