#include "WidgetConfig.h"

const ue::WidgetConfig::WidgetSetting* ue::WidgetConfig::getWidget(const std::string& name) const
{
	auto it = _widgetSettings.find(name);
	if (it == _widgetSettings.end())
	{
		return nullptr;
	}
	return &it->second;
}

void ue::WidgetConfig::loadXml(const std::string& filepath)
{
	this->Dispose();

	if (!_helper.loadFile(filepath.c_str()))
	{
		return;
	}

	auto child = _helper.getElement("Item");
	while (child)
	{
		if (child->Attribute("name"))
		{
			WidgetSetting setting;
			if (child->Attribute("name")) setting.Name = child->Attribute("name");
			if (child->Attribute("control")) setting.ControlFilepath = child->Attribute("control");
			if (child->Attribute("property")) setting.PropertyFilepath = child->Attribute("property");
			_widgetSettings[setting.Name] = setting;
		}

		child = child->NextSiblingElement();
	}
}

void ue::WidgetConfig::Dispose()
{
	_widgetSettings.clear();
}
