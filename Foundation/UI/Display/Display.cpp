#include "Display.h"
#include "../File/UIProxy.h"

using namespace ui;


Display::Display()
:m_pLayout(nullptr)
,m_eLayoutDirection(ELD_NONE)
{

}

Display::~Display()
{
	this->close();
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
	if (m_pLayout && m_pLayout->getWidget())
	{
		m_pLayout->getWidget()->removeFromParent();
	}
	SAFE_RELEASE(m_pLayout);
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

void Display::setFilePath(const char* filepath)
{
	if (filepath)
	{
		m_strFilePath = filepath;
	}
}

const char* Display::getFilePath()
{
	return m_strFilePath.c_str();
}

void Display::setViewSize(const sys::Size& inputSize)
{
	if (m_sViewSize.equal(inputSize))
	{
		return;
	}

	m_sViewSize = inputSize;

	onViewSizeChanged(inputSize);
}

const sys::Size& Display::getViewSize()
{
	return m_sViewSize;
}

void Display::setLayoutDirection(LayoutDirection eDirection)
{
	if (m_eLayoutDirection == eDirection)
	{
		return;
	}
	m_eLayoutDirection = eDirection;

	Layout* pNewLayout = nullptr;

	switch (eDirection)
	{
	case ui::ELD_NONE:
		break;
	case ui::ELD_HORIZONTAL:
		pNewLayout = new HorizontalLayout();
		break;
	case ui::ELD_VERTICAL:
		pNewLayout = new VerticalLayout();
		break;
	default:
		break;
	}

	if (pNewLayout == nullptr)
	{
		return;
	}

	pNewLayout->copy(m_pLayout);
}

LayoutDirection Display::getLayoutDirection()
{
	return m_eLayoutDirection;
}

void Display::onViewSizeChanged(const sys::Size& inputSize)
{
	if (m_pLayout == nullptr)
	{
		return;
	}

	sys::Size minSize = m_pLayout->getLayoutMinSize();
	sys::Size maxSize = m_pLayout->getLayoutMaxSize();

	// 超出限定范围的不做处理
	if (minSize.width > inputSize.width || minSize.height > inputSize.height
		|| maxSize.width < inputSize.width || maxSize.height < inputSize.height)
	{
		return;
	}
	sys::Size size;
	size.width = inputSize.width;
	size.height = inputSize.height;

	m_pLayout->resize(size);
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
