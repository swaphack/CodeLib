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
