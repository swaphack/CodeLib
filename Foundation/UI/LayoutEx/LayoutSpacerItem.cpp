#include "LayoutSpacerItem.h"

using namespace ui;

LayoutSpacerItem::LayoutSpacerItem()
{
	render::CtrlWidget* pCtrlWidget = render::createNode<render::CtrlWidget>();
	this->setWidget(pCtrlWidget);
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
		this->getSizePolicy().width = SizeType::EXPANDING;
		this->getSizePolicy().height = SizeType::FIXED;
	}
	else if (m_eOrientation == ESO_Vertial)
	{
		this->getSizePolicy().width = SizeType::FIXED;
		this->getSizePolicy().height = SizeType::EXPANDING;
	}
}

SpacerOrientation LayoutSpacerItem::getOrientation()
{
	return m_eOrientation;
}