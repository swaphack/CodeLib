#include "UIPropertyProtocol.h"

void ue::UIPropertyProtocol::saveProperty() 
{ 
	writeWidgetProperty(); 
}
void ue::UIPropertyProtocol::setTarget(ui::CtrlWidget* widget) 
{ 
	m_pTarget = widget; 
}
