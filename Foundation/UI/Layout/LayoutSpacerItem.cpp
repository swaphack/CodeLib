#include "LayoutSpacerItem.h"

using namespace ui;

LayoutSpacerItem::LayoutSpacerItem()
{
	Widget* pWidget = render::createNode<Widget>();
	this->setWidget(pWidget);
	this->setGeometry(0, 0, 20, 20);
	this->setOrientation(ESO_Horizontal);
}

LayoutSpacerItem::~LayoutSpacerItem()
{

}

void LayoutSpacerItem::setOrientation(SpacerOrientation eType)
{
	m_eOrientation = eType;

	if (m_eOrientation == ESO_Horizontal)
	{
		this->getSizePolicy().width = EST_Expanding;
		this->getSizePolicy().height = EST_Fixed;
	}
	else if (m_eOrientation == ESO_Vertial)
	{
		this->getSizePolicy().width = EST_Fixed;
		this->getSizePolicy().height = EST_Expanding;
	}
}

SpacerOrientation LayoutSpacerItem::getOrientation()
{
	return m_eOrientation;
}