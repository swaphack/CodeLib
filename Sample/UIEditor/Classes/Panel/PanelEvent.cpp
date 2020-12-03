#include "PanelEvent.h"

ue::PanelEvent::PanelEvent()
{
}

ue::PanelEvent::~PanelEvent()
{
}

void ue::PanelEvent::dispatchEvent(const std::string& name, void* userData)
{
	sys::Event evt;
	evt.setName(name);
	evt.setUserData(userData);

	this->dispatch(&evt);
}

void ue::PanelEvent::setDesignFile(const std::string& filepath)
{
	this->dispatchEvent(PANEL_SELECT_DESIGN_FILE, (void*)filepath.c_str());
}

void ue::PanelEvent::setSelectNode(ui::LayoutItem* node)
{
	this->dispatchEvent(PANEL_SELECT_LAYTOUT_ITEM, node);
}

void ue::PanelEvent::saveFile()
{
	this->dispatchEvent(PANEL_SAVE_FILE, nullptr);
}
