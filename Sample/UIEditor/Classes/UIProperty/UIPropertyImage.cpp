#include "UIPropertyImage.h"

ue::UIPropertyImage::UIPropertyImage()
{
}

ue::UIPropertyImage::~UIPropertyImage()
{
}

void ue::UIPropertyImage::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}
	UIPropertyWidget::initPropertyUI(root);

	root->findWidgetByName("Filepath", m_pFilepath);
	root->findWidgetByName("ReverseX", m_pReverseX);
	root->findWidgetByName("ReverseY", m_pReverseY);


	ADD_CLICK_FUNC(m_pReverseX, ui::CtrlImage, setFlipX);
	ADD_CLICK_FUNC(m_pReverseY, ui::CtrlImage, setFlipY);
}

void ue::UIPropertyImage::readWidgetProperty()
{
	if (m_pTarget == nullptr) return;

	UIPropertyWidget::readWidgetProperty();

	auto pImage = m_pTarget->as<ui::CtrlImage>();
	if (pImage == nullptr)
	{
		return;
	}

	if (m_pFilepath)
	{
		m_pFilepath->setNormalImage(pImage->getImagePath());
	}
	if (m_pReverseX)
	{
		m_pReverseX->setSelectState(pImage->isFlipX());
	}
	if (m_pReverseY)
	{
		m_pReverseY->setSelectState(pImage->isFlipY());
	}

}

void ue::UIPropertyImage::writeWidgetProperty()
{
	if (m_pTarget == nullptr) return;

	auto pImage = m_pTarget->as<ui::CtrlImage>();
	if (pImage == nullptr)
	{
		return;
	}

	if (m_pFilepath)
	{
		pImage->setImagePath(m_pFilepath->getNormalImage());
	}

	if (m_pReverseX)
	{
		pImage->setFlipX(m_pReverseX->isSelected());
	}

	if (m_pReverseY)
	{
		pImage->setFlipY(m_pReverseY->isSelected());
	}

	UIPropertyWidget::writeWidgetProperty();
}
