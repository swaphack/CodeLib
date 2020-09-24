#include "Display.h"
#include "UIProxy.h"
#include "Layout/Layout.h"

using namespace ui;


Display::Display()
:m_pLayout(nullptr)
,m_eLayoutDirection(LayoutDirection::NONE)
, m_pRoot(nullptr)
{

}

Display::~Display()
{
	this->close();
}

void Display::setUIRoot(render::Node* root)
{
	m_pRoot = root;
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

void Display::close()
{
	SAFE_DELETE(m_pLayout);
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

void Display::setFilePath(const std::string& filepath)
{
	m_strFilePath = filepath;
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

void Display::onViewSizeChanged(const math::Size& inputSize)
{
	if (m_pLayout == nullptr)
	{
		return;
	}

	math::Vector2 point;
	math::Size size;
	Layout::calLayoutSpace(m_pLayout, m_sViewSize, inputSize, point, size);

	m_pLayout->resize(math::Rect(point, size));
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

	SAFE_DELETE(m_pLayout);
	m_pLayout = pLayout;
	m_sViewSize = UIProxy::getInstance()->getDesignSize();
	m_eLayoutDirection = UIProxy::getInstance()->getDesignDirection();

	this->autoResize();

	if (m_pRoot && m_pLayout->getWidget())
	{
		m_pRoot->addChild(m_pLayout->getWidget());
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

	this->onViewSizeChanged(viewSize);
}

const math::Size& ui::Display::getViewSize()
{
	return m_sViewSize;
}
