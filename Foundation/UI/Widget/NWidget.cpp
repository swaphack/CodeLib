#include "NWidget.h"

using namespace ui;

NWidget::NWidget(render::Node* node)
{
	ASSERT(node != nullptr);
}

NWidget::~NWidget()
{

}

void NWidget::onViewSizeChanged()
{
	if (m_pNode == nullptr)
	{
		return;
	}

	const sys::Vector& anchorPoint = m_pNode->getAnchorPoint();

	m_pNode->setPosition(
		m_rGeometry.x + anchorPoint.x * m_rGeometry.width, 
		m_rGeometry.y + anchorPoint.y * m_rGeometry.height);

	m_pNode->setVolume(
		m_rGeometry.width, 
		m_rGeometry.height);
}
