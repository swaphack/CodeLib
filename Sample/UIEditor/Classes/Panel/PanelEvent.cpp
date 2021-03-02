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

void ue::PanelEvent::setSelectNode(render::Node* node)
{
	this->dispatchEvent(PANEL_SELECT_VIEW_WIDGET, node);
}

void ue::PanelEvent::setSelectTreeNode(const std::vector<int>& vecIndex)
{
	this->dispatchEvent(PANEL_SELECT_NODE_TREE, (std::vector<int>*)&vecIndex);
}

void ue::PanelEvent::setRoot(render::Node* node)
{
	this->dispatchEvent(PANEL_SELECT_ROOT, node);
}

void ue::PanelEvent::setSelectControlWidget(render::Node* node)
{
	this->dispatchEvent(PANEL_SELECT_CONTROL_WIDGET, node);
}

void ue::PanelEvent::saveFile()
{
	this->dispatchEvent(PANEL_SAVE_FILE, nullptr);
}
