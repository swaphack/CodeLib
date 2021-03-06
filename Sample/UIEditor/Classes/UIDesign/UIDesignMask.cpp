#include "UIDesignMask.h"
#include "Panel/PanelEvent.h"
#include "UIDesignView.h"

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
			{
				m_pCloneWidget->removeFromParent();
			}

			if (m_pMainLayout)
			{
				ui::CtrlImage* pImage = render::createNode<ui::CtrlImage>();
				if (pImage == nullptr) return;
				pImage->setImagePath(pNode->getNormalImage());
				pImage->setPosition(m_pTempPosition);


				std::string name = pNode->getString();
				pImage->setName(name);

				m_pCloneWidget = pImage;
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
			{
				auto pViewPanel = G_PANELEVT->getViewPanel();
				if (pViewPanel != nullptr)
				{
					auto pRoot = pViewPanel->getUIRoot();
					if (pViewPanel)
					{
						touchFrontWidget(pViewPanel, touchPoint, [this, pViewPanel](ui::CtrlWidget* widget) {
							auto pWidget = createWidget(m_pCloneWidget->getName());
							widget->addWidget(pWidget);

							m_pCloneWidget->removeFromParent();
							m_pCloneWidget = nullptr;
							pViewPanel->saveAndReload();
						});
					}
				}

				if (m_pCloneWidget != nullptr)
				{
					m_pCloneWidget->removeFromParent();
					m_pCloneWidget = nullptr;
				}
			}
		});

		m_pMainLayout->addTouchFunc(render::TouchType::CANCELED, [this](const math::Vector2& touchPoint) {
			if (m_pCloneWidget != nullptr)
			{
				m_pCloneWidget->removeFromParent();
				m_pCloneWidget = nullptr;
			}
		});
	}
}

void ue::UIDesignMask::initText()
{
}

ui::CtrlWidget* ue::UIDesignMask::createWidget(const std::string& name)
{
	auto pCloneWidget = ui::UIProxy::getInstance()->createWidget(name);
	if (pCloneWidget == nullptr)
	{
		return nullptr;
	}
	auto pLayoutItem = pCloneWidget->getLayoutItem();
	if (pLayoutItem)
	{
		pLayoutItem->setName(name);
		pLayoutItem->setWidgetName(name);
		pLayoutItem->setWidth(100);
		pLayoutItem->setHeight(100);
		pLayoutItem->setMargin(0, 0, 0, 0);
	}

	return pCloneWidget;
}
