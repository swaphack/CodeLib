#include "UIPropertyWidget.h"
#include "UIHelper/File.h"

ue::UIPropertyWidget::UIPropertyWidget()
{
}

ue::UIPropertyWidget::~UIPropertyWidget()
{
}

void ue::UIPropertyWidget::initPropertyUI(ui::CtrlWidget* root)
{
	if (root == nullptr)
	{
		return;
	}

	ue::UIPropertyNode::initPropertyUI(root);

	root->findWidgetByName("MarginTop", m_pBtnMarginTop);
	root->findWidgetByName("MarginRight", m_pBtnMarginRight);
	root->findWidgetByName("MarginBottom", m_pBtnMarginBottom);
	root->findWidgetByName("MarginLeft", m_pBtnMarginLeft);

	root->findWidgetByName("TopValue", m_pEditTopValue);
	root->findWidgetByName("RightValue", m_pEditRightValue);
	root->findWidgetByName("BottomValue", m_pEditBottomValue);
	root->findWidgetByName("LeftValue", m_pEditLeftValue);

	root->findWidgetByName("WidthValue", m_pEditWidthValue);
	root->findWidgetByName("HeightValue", m_pEditHeightValue);

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginTop->setSelectState(!m_pBtnMarginTop->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginRight->setSelectState(!m_pBtnMarginRight->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginBottom->setSelectState(!m_pBtnMarginBottom->isSelected());
			this->saveProperty();
		});
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->addClickFunc([this](ui::CtrlWidget* target) {
			m_pBtnMarginLeft->setSelectState(!m_pBtnMarginLeft->isSelected());
			this->saveProperty();
		});
	}
}

void ue::UIPropertyWidget::readWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}


	ue::UIPropertyNode::readWidgetProperty();

	auto layoutItem = ui::UIProxy::getLayoutItem(m_pTarget);
	if (layoutItem == nullptr)
	{
		return;
	}

	if (m_pBtnMarginTop)
	{
		m_pBtnMarginTop->setSelectState(layoutItem->getMarginState().Top);
	}

	if (m_pBtnMarginRight)
	{
		m_pBtnMarginRight->setSelectState(layoutItem->getMarginState().Right);
	}

	if (m_pBtnMarginBottom)
	{
		m_pBtnMarginBottom->setSelectState(layoutItem->getMarginState().Bottom);
	}

	if (m_pBtnMarginLeft)
	{
		m_pBtnMarginLeft->setSelectState(layoutItem->getMarginState().Left);
	}

	const sys::CSSMargin& margin = layoutItem->getMargin();
	const sys::CSSSize& size = layoutItem->getSize();

	if (m_pEditTopValue)
	{
		m_pEditTopValue->setString(margin.getTop().toString(2));
	}

	if (m_pEditRightValue)
	{
		m_pEditRightValue->setString(margin.getRight().toString(2));
	}

	if (m_pEditBottomValue)
	{
		m_pEditBottomValue->setString(margin.getBottom().toString(2));
	}

	if (m_pEditLeftValue)
	{
		m_pEditLeftValue->setString(margin.getLeft().toString(2));
	}

	if (m_pEditWidthValue)
	{
		m_pEditWidthValue->setString(size.getWidth().toString(2));
	}

	if (m_pEditHeightValue)
	{
		m_pEditHeightValue->setString(size.getHeight().toString(2));
	}
}

void ue::UIPropertyWidget::writeWidgetProperty()
{
	if (m_pTarget == nullptr)
	{
		return;
	}

	

	auto layoutItem = ui::UIProxy::getLayoutItem(m_pTarget);

	if (m_pBtnMarginTop)
	{
		layoutItem->getMarginState().Top = m_pBtnMarginTop->isSelected();
	}

	if (m_pBtnMarginRight)
	{
		layoutItem->getMarginState().Right = m_pBtnMarginRight->isSelected();
	}

	if (m_pBtnMarginBottom)
	{
		layoutItem->getMarginState().Bottom = m_pBtnMarginBottom->isSelected();
	}

	if (m_pBtnMarginLeft)
	{
		layoutItem->getMarginState().Left = m_pBtnMarginLeft->isSelected();
	}

	if (m_pEditTopValue)
	{
		std::string strText = m_pEditTopValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setTop(number);
	}

	if (m_pEditRightValue)
	{
		std::string strText = m_pEditRightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setRight(number);
	}

	if (m_pEditBottomValue)
	{
		std::string strText = m_pEditBottomValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setBottom(number);
	}

	if (m_pEditLeftValue)
	{
		std::string strText = m_pEditLeftValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getMargin().setLeft(number);
	}

	if (m_pEditWidthValue)
	{
		std::string strText = m_pEditWidthValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getSize().setWidth(number);
	}

	if (m_pEditHeightValue)
	{
		std::string strText = m_pEditHeightValue->getString();
		sys::CSSNumber number = sys::CSSNumber::load(strText);
		layoutItem->getSize().setHeight(number);
	}

	layoutItem->refresh();

	ue::UIPropertyNode::writeWidgetProperty();

	this->readWidgetProperty();
}

void ue::UIPropertyWidget::addSelectImageFile(ui::CtrlButton* btn)
{
	if (btn == nullptr) return;

	std::vector<std::string> vecFormat;
	vecFormat.push_back(IMAGE_FORMAT_PNG);
	vecFormat.push_back(IMAGE_FORMAT_JPG);

	File* pFile = Panel::show<File>();
	pFile->setFileFormat(vecFormat);
	pFile->setSelectFileFunc([this, btn](const std::string& filepath) {
		btn->setNormalImage(filepath);
		saveProperty();
	});
}

void ue::UIPropertyWidget::addSelectImageFile(ui::CtrlImage* image)
{
	if (image == nullptr) return;

	std::vector<std::string> vecFormat;
	vecFormat.push_back(IMAGE_FORMAT_PNG);
	vecFormat.push_back(IMAGE_FORMAT_JPG);

	File* pFile = Panel::show<File>();
	pFile->setFileFormat(vecFormat);
	pFile->setSelectFileFunc([this, image](const std::string& filepath) {
		image->loadImage(filepath);
		saveProperty();
	});
}
