#include "ProjectConfig.h"

const ue::ProjectConfig::ProjectSetting& ue::ProjectConfig::getProject() const
{
	return _project;
}

const ue::ProjectConfig::RecentSetting& ue::ProjectConfig::getRecent() const
{
	return _recentFiles;
}

void ue::ProjectConfig::Dispose()
{
	_recentFiles.Files.clear();
}

void ue::ProjectConfig::loadXml(const std::string& filepath)
{
	this->Dispose();

	if (!_helper.loadFile(filepath.c_str()))
	{
		return;
	}

	auto element = _helper.getElement("Project");
	if (element)
	{
		auto child = element->FirstChildElement("Directory");
		if (child && child->GetText())
		{
			_project.Root = child->GetText();
		}
	}
	element = _helper.getElement("Recent");
	if (element)
	{
		auto child = element->FirstChildElement("Item");
		while (child)
		{
			if (child->GetText())
			{
				_recentFiles.Files.push_back(child->GetText());
			}

			child = child->NextSiblingElement();
		}
	}
}

std::string ue::ProjectConfig::RecentSetting::getFile(int index) const
{
	if (Files.size() <= index)
	{
		return "";
	}
	return Files[index];
}
