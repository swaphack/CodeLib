#include "Display.h"
#include "UIProxy.h"
#include "Layout/Layout.h"

using namespace ui;


Display::Display()
{
	render::RenderApplication::getInstance()->addWndProtocol(this);
}

Display::~Display()
{
	render::RenderApplication::getInstance()->removeWndProtocol(this);

	SAFE_RELEASE(m_pLayout);
}

void Display::show()
{
	if (m_pLayout == nullptr)
	{
		if (!loadFile())
		{
			return;
		}
		initUI();
		initText();
		initEvent();
	}

	if (m_pLayout->getWidget())
	{
		m_pLayout->getWidget()->setVisible(true);
	}
}

void Display::hide()
{
	if (m_pLayout == nullptr)
	{
		return;
	}

	if (m_pLayout->getWidget())
	{
		m_pLayout->getWidget()->setVisible(false);
	}
}

void Display::reload()
{
	if (m_pLayout == nullptr)
	{
		if (!loadFile())
			return;
	}

	initUI();
	initText();
	initEvent();
}

void Display::load(const std::string& filepath)
{
	m_strFilePath = filepath;

	this->show();
}

const std::string& Display::getFilePath()
{
	return m_strFilePath;
}

LayoutDirection Display::getLayoutDirection()
{
	return m_eLayoutDirection;
}

Layout* Display::getLayout()
{
	return m_pLayout;
}

void Display::onWindowSizeChange(const math::Size& inputSize)
{
	if (m_pLayout == nullptr)
	{
		return;
	}
	m_pLayout->resize(inputSize);
}

bool Display::loadFile()
{
	std::string fullpath = G_FILEPATH->getFilePath(m_strFilePath.c_str());
	if (fullpath.empty())
	{
		return false;
	}
	Layout* pLayout = UIProxy::getInstance()->loadFile(fullpath.c_str());
	if (pLayout == nullptr)
	{
		return false;
	}

	SAFE_RELEASE(m_pLayout);
	SAFE_RETAIN(pLayout);

	m_pLayout = pLayout;
	m_sViewSize = UIProxy::getInstance()->getDesignSize();
	m_eLayoutDirection = UIProxy::getInstance()->getDesignDirection();

	this->autoResize();

	if (m_pLayout->getWidget())
	{
		this->addChild(m_pLayout->getWidget());
	}

	return true;
}

void Display::initUI()
{
}

void Display::initEvent()
{

}

void Display::initText()
{

}

void Display::autoResize()
{
	math::Size viewSize(render::Tool::getGLViewWidth(), render::Tool::getGLViewHeight());

	this->onWindowSizeChange(viewSize);
}

const math::Size& ui::Display::getViewSize()
{
	return m_sViewSize;
}
