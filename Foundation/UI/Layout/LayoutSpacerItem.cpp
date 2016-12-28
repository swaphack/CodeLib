#include "LayoutSpacerItem.h"

using namespace ui;

LayoutSpacerItem::LayoutSpacerItem()
{
	this->setWidget(this);
	this->setGeometry(0, 0, 20, 20);
	this->setOrientation(EO_Horizontal);
}

LayoutSpacerItem::~LayoutSpacerItem()
{

}

void LayoutSpacerItem::setOrientation(Orientation eType)
{
	m_eOrientation = eType;

	if (m_eOrientation == EO_Horizontal)
	{
		this->getSizePolicy().setHeightType(EST_Expanding);
	}
	else if (m_eOrientation == EO_Vertial)
	{
		this->getSizePolicy().setWidthType(EST_Expanding);
	}
}

Orientation LayoutSpacerItem::getOrientation()
{
	return m_eOrientation;
}