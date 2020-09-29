#include "LayoutSpacerItem.h"

using namespace ui;

LayoutSpacerItem::LayoutSpacerItem()
{
	render::CtrlWidget* pCtrlWidget = render::createNode<render::CtrlWidget>();
	this->setWidget(pCtrlWidget);
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
		this->m_spAdjust.width = SizeType::EXPANDING;
		this->m_spAdjust.height = SizeType::FIXED;
	}
	else if (m_eOrientation == ESO_Vertial)
	{
		this->m_spAdjust.width = SizeType::FIXED;
		this->m_spAdjust.height = SizeType::EXPANDING;
	}
}

SpacerOrientation LayoutSpacerItem::getOrientation()
{
	return m_eOrientation;
}