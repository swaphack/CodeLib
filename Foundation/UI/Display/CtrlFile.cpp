#include "CtrlFile.h"
#include "UIProxy.h"
#include "Layout/Layout.h"

using namespace ui;


CtrlFile::CtrlFile()
{
	this->setAnchorPoint(0.0f, 0.0f, 0.0f);
}

CtrlFile::~CtrlFile()
{
	render::RenderApplication::getInstance()->removeWndProtocol(this);

	SAFE_RELEASE(m_pLayout);
}

bool ui::CtrlFile::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(render::NodeNotifyType::BODY, [this]() {
		math::Size size = this->getSize();
		if (m_pLayout)
		{
			m_pLayout->resize(size);
		}
	});

	return true;
}

void CtrlFile::show()
{
	if (m_pLayout == nullptr)
	{
		return;
	}

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

LayoutDirection CtrlFile::getLayoutDirection()
{
	return m_eLayoutDirection;
}

Layout* CtrlFile::getLayout()
{
	return m_pLayout;
}

void ui::CtrlFile::setRootView(bool root)
{
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

	if (m_pLayout->getWidget())
	{
		this->addWidget(m_pLayout->getWidget());
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
	if (m_pLayout)
	{
		m_pLayout->resize(viewSize);
	}
}

const math::Size& ui::CtrlFile::getViewSize()
{
	return m_sViewSize;
}
