#include "UIDesignMask.h"
#include "Panel/PanelEvent.h"

ue::UIDesignMask::UIDesignMask()
{
}

ue::UIDesignMask::~UIDesignMask()
{
}

template<typename T>
T* createCell(T* temp)
{
	return render::createNode<T>();
}

bool ue::UIDesignMask::init()
{
	if (!Panel::init())
	{
		return false;
	}

	G_PANELEVT->addEventListener(PANEL_SELECT_CONTROL_WIDGET, this, [this](const sys::Event* evt) {
		if (evt)
		{
			ui::CtrlButton* pNode = (ui::CtrlButton*)evt->getUserData();
			if (pNode == nullptr)
			{
				return;
			}

			if (m_pCloneWidget != nullptr) 
				m_pCloneWidget->removeFromParent();
			if (m_pMainLayout)
			{
				m_pCloneWidget = render::createNode<ui::CtrlImage>();
				m_pCloneWidget->setImagePath(pNode->getNormalImage());
				m_pCloneWidget->setPosition(m_pTempPosition);
				m_pMainLayout->addWidget(m_pCloneWidget);
			}
		}
	});

	return true;
}

void ue::UIDesignMask::initUI()
{
	m_pRootWidget->findWidgetByName("main", m_pMainLayout);
}

void ue::UIDesignMask::initEvent()
{
	if (m_pMainLayout)
	{
		m_pMainLayout->setTouchEnabled(true);
		m_pMainLayout->addTouchFunc(render::TouchType::BEGAN, [this](const math::Vector2& touchPoint) {
			if (m_pCloneWidget != nullptr)
			{
				m_pCloneWidget->removeFromParent();
				m_pCloneWidget = nullptr;
			}
			m_pTempPosition = touchPoint;
		});

		m_pMainLayout->addTouchFunc(render::TouchType::MOVED, [this](const math::Vector2& touchPoint) {
			if (m_pCloneWidget)
			{
				m_pCloneWidget->setPosition(touchPoint);
			}
		});

		m_pMainLayout->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint) {
			if (m_pCloneWidget != nullptr)
				m_pCloneWidget->removeFromParent();
			m_pCloneWidget = nullptr;
		});

		m_pMainLayout->addTouchFunc(render::TouchType::CANCELED, [this](const math::Vector2& touchPoint) {
			if (m_pCloneWidget != nullptr)
				m_pCloneWidget->removeFromParent();
			m_pCloneWidget = nullptr;
		});
	}
}

void ue::UIDesignMask::initText()
{
}
