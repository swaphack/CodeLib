#include "File.h"
#include "Panel/PanelEvent.h"

ue::File::File()
{
}

ue::File::~File()
{
}

const char* ue::File::getPanelPath()
{
	return "Default/Layout/ui_file.xml";
}

void ue::File::setSelectFileFunc(const SelectFileFunc& func)
{
	_selectFileFunc = func;
}

void ue::File::setFileFormat(const std::vector<std::string>& vecFormat)
{
	_fileFormats = vecFormat;
}

void ue::File::initUI()
{
	m_pRootWidget->findWidgetByName("body", _body);
}

void ue::File::initEvent()
{
	G_PANELEVT->addEventListener(PANEL_SELECT_FILE, this, [this](const sys::Event* evt) {
		if (evt)
		{
			std::string filepath = (char*)evt->getUserData();
			if (filepath.empty()) return;

			if (isMatchFormat(filepath))
			{
				this->onSelectFile(filepath);
			}
		}
	});
}

void ue::File::initText()
{
}

bool ue::File::isMatchFormat(const std::string& filepath)
{
	for (const auto& item : _fileFormats)
	{
		int index = filepath.find_last_of(item);
		if (index == filepath.size() - 1)
		{
			return true;
		}
	}
	return false;
}

void ue::File::onSelectFile(const std::string& filepath)
{
	_selectedFilepath = filepath;
	if (_selectFileFunc)
	{
		_selectFileFunc(filepath);
	}

	this->close();
}
