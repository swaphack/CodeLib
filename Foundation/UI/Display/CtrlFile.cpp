#include "CtrlFile.h"
#include "UIProxy.h"

using namespace ui;


CtrlFile::CtrlFile()
{
	this->setAnchorPoint(0.0f, 0.0f, 0.0f);
}

CtrlFile::~CtrlFile()
{
	render::RenderApplication::getInstance()->removeWndProtocol(this);
}

bool ui::CtrlFile::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	return true;
}

void CtrlFile::show()
{
	initUI();
	initText();
	initEvent();
}

void ui::CtrlFile::setFilePath(const std::string& filepath)
{
	m_strFilePath = filepath;

	if (this->loadFile())
	{
		this->show();
	}
}

const std::string& CtrlFile::getFilePath()
{
	return m_strFilePath;
}

void ui::CtrlFile::reload()
{
	setFilePath(m_strFilePath);
}

void ui::CtrlFile::save()
{
	this->saveTo(m_strFilePath);
}

void ui::CtrlFile::saveTo(const std::string& filepath)
{
	if (m_pRootWidget == nullptr) return;
	UIProxy::getInstance()->saveFile(m_pRootWidget, filepath, m_sViewSize);
}

LayoutDirection CtrlFile::getLayoutDirection() const
{
	return m_eLayoutDirection;
}

void ui::CtrlFile::setRootView(bool root)
{
	if (m_bRootView == root) return;

	m_bRootView = root;
	if (root)
	{
		render::RenderApplication::getInstance()->addWndProtocol(this);
	}
	else
	{
		render::RenderApplication::getInstance()->removeWndProtocol(this);
	}
}

bool ui::CtrlFile::isRootView() const
{
	return m_bRootView;
}

void CtrlFile::onWindowSizeChange(const math::Size& inputSize)
{
	this->setVolume(inputSize);
}

bool CtrlFile::loadFile()
{
	std::string fullpath = G_FILEPATH->getFilePath(m_strFilePath);
	if (fullpath.empty())
	{
		return false;
	}
	auto widget = UIProxy::getInstance()->loadFile(fullpath, this->getSize());
	if (widget == nullptr)
	{
		return false;
	}

	m_sViewSize = UIProxy::getInstance()->getDesignSize();
	m_eLayoutDirection = UIProxy::getInstance()->getDesignDirection();

	m_pRootWidget = widget;
	this->removeAllWidgets();
	if (widget)
	{
		this->addWidget(widget);
	}

	return true;
}

void CtrlFile::initUI()
{
}

void CtrlFile::initEvent()
{

}

void CtrlFile::initText()
{

}

void CtrlFile::autoResize()
{
	math::Size viewSize;
	if (this->isRootView() || !this->isRelativeWithParent())
	{
		viewSize.set(render::Tool::getGLViewWidth(), render::Tool::getGLViewHeight());
	}
	else if (this->getParent() == nullptr)
	{
		viewSize.set(render::Tool::getGLViewWidth(), render::Tool::getGLViewHeight());
	}
	else
	{
		viewSize = this->getParent()->getSize();
	}

	this->setVolume(viewSize);
}

const math::Size& ui::CtrlFile::getViewSize() const
{
	return m_sViewSize;
}
