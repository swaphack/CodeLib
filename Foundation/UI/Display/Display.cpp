#include "Display.h"
#include "../File/UIProxy.h"

using namespace ui;


Display::Display()
{

}

Display::~Display()
{

}

void Display::show()
{
	if (m_pLayoutItem == nullptr)
	{
		if (!loadFile())
			return;
		initUI();
		initText();
		initEvent();
	}

	if (getWidget() == nullptr)
	{
		return;
	}

	if (!getWidget()->isVisible())
	{
		getWidget()->setVisible(true);
	}
}

void Display::hide()
{
	if (m_pLayoutItem == nullptr)
	{
		return;
	}

	if (getWidget() == nullptr)
	{
		return;
	}

	if (getWidget()->isVisible())
	{
		getWidget()->setVisible(false);
	}
}

void Display::dispose()
{
	delete m_pLayoutItem;
	m_pLayoutItem = nullptr;
}

void Display::reload()
{
	if (m_pLayoutItem == nullptr)
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

void Display::onViewSizeChanged(const sys::Size& inputSize)
{
	if (m_pLayoutItem == nullptr)
	{
		return;
	}

	sys::Size minSize = m_pLayoutItem->getLayoutItemMinSize();
	sys::Size maxSize = m_pLayoutItem->getLayoutItemMaxSize();

	// 超出限定范围的不做处理
	if (minSize.width > inputSize.width || minSize.height > inputSize.height
		|| maxSize.width < inputSize.width || maxSize.height < inputSize.height)
	{
		return;
	}

	sys::Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.width = inputSize.width;
	rect.height = inputSize.height;

	m_pLayoutItem->setLayoutItemGeometry(rect);
}

bool Display::loadFile()
{
	std::string fullpath = G_FILEPATH->getFilePath(m_strFilePath.c_str());
	if (fullpath.empty())
	{
		return false;
	}
	Widget* pWidget = UIProxy::getInstance()->loadFile(fullpath.c_str());
	if (pWidget == nullptr)
	{
		return false;
	}

	// 水平布局
	m_pLayoutItem = new HorizontalLayout();
	m_pLayoutItem->setWidget(pWidget);

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

Widget* Display::getWidget()
{
	if (m_pLayoutItem == nullptr)
	{
		return nullptr;
	}

	return m_pLayoutItem->getWidget();
}
