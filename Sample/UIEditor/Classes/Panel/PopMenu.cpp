#include "PopMenu.h"

ue::PopMenu* ue::PopMenu::sPopMenu = nullptr;

ue::PopMenu::PopMenu()
{
	this->setTouchEnable(true);
}

ue::PopMenu::~PopMenu()
{
}

void ue::PopMenu::updatePosition(const ui::LayoutItem* item, sys::CSSDirection eDir)
{
	if (item == nullptr)
	{
		return;
	}

	auto pRectPoints = item->getRectPoints();
	if (pRectPoints == nullptr)
	{
		return;
	}

	if (eDir == sys::CSSDirection::Top)
	{
		float x = pRectPoints->leftUp.getX();
		float y = pRectPoints->leftUp.getY();
		this->setPositionLeftBottom(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Right)
	{
		float x = pRectPoints->rightUp.getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->rightUp.getY();
		this->setPositionLeftTop(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Bottom)
	{
		float x = pRectPoints->leftDown.getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->leftDown.getY();
		this->setPositionLeftTop(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Left)
	{
		float x = render::Tool::getGLViewWidth() - pRectPoints->leftUp.getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->leftUp.getY();
		this->setPositionRightTop(math::Vector2(x, y));
	}
}

void ue::PopMenu::setPositionLeftTop(const math::Vector2& pos)
{
	if (!_body)
	{
		return;
	}

	sys::CSSMargin margin;
	margin.setTop(sys::NumberType::Fixed, pos.getY());
	margin.setLeft(sys::NumberType::Fixed, pos.getX());

	ui::MarginState state;
	state.Top = true;
	state.Left = true;

	_body->setMargin(margin);
	_body->setMarginState(state);
	this->autoResize();
}

void ue::PopMenu::setPositionRightTop(const math::Vector2& pos)
{
	if (!_body)
	{
		return;
	}

	sys::CSSMargin margin;
	margin.setTop(sys::NumberType::Fixed, pos.getY());
	margin.setRight(sys::NumberType::Fixed, pos.getX());

	ui::MarginState state;
	state.Top = true;
	state.Right = true;

	_body->setMargin(margin);
	_body->setMarginState(state);
	this->autoResize();
}

void ue::PopMenu::setPositionLeftBottom(const math::Vector2& pos)
{
	if (!_body)
	{
		return;
	}

	sys::CSSMargin margin;
	margin.setBottom(sys::NumberType::Fixed, pos.getY());
	margin.setLeft(sys::NumberType::Fixed, pos.getX());

	ui::MarginState state;
	state.Bottom = true;
	state.Left = true;

	_body->setMargin(margin);
	_body->setMarginState(state);
	this->autoResize();
}

void ue::PopMenu::setPositionRightBottom(const math::Vector2& pos)
{
	if (!_body)
	{
		return;
	}

	sys::CSSMargin margin;
	margin.setBottom(sys::NumberType::Fixed, pos.getY());
	margin.setRight(sys::NumberType::Fixed, pos.getX());

	ui::MarginState state;
	state.Bottom = true;
	state.Right = true;

	_body->setMargin(margin);
	_body->setMarginState(state);
	this->autoResize();
}

void ue::PopMenu::initUI()
{
	auto layoutItem = m_pLayout->findItemByName("popMenu");
	if (layoutItem->getWidget() != nullptr)
	{
		_body = layoutItem->as<ui::Layout>();
	}
}

void ue::PopMenu::initEvent()
{
}

void ue::PopMenu::initText()
{
}

bool ue::PopMenu::onTouchBegan(float x, float y, bool include)
{
	if (!_body->containPoint(x, y))
	{
		hide();
	}
	return false;
}

bool ue::PopMenu::onTouchMoved(float x, float y, bool include)
{
	return false;
}

bool ue::PopMenu::onTouchEnded(float x, float y, bool include)
{
	return false;
}

void ue::PopMenu::show(const ui::LayoutItem* item, sys::CSSDirection eDir)
{
	if (item == nullptr)
	{
		return;
	}
	hide();
	sPopMenu = createPanel<PopMenu>("Default/Layout/main_view_pop_menu.xml");
	sPopMenu->updatePosition(item, eDir);
	render::RenderApplication::getInstance()->getCanvas()->getCurScene()->addChild(sPopMenu);
}

void ue::PopMenu::show(const math::Vector2& pos)
{
	hide();
	sPopMenu = createPanel<PopMenu>("Default/Layout/main_view_pop_menu.xml");
	sPopMenu->setPositionLeftTop(pos);
	render::RenderApplication::getInstance()->getCanvas()->getCurScene()->addChild(sPopMenu);
}

void ue::PopMenu::hide()
{
	if (sPopMenu)
	{
		sPopMenu->removeFromParent();
		sPopMenu = nullptr;
	}
}

bool ue::PopMenu::isShow()
{
	return sPopMenu != nullptr;
}

ue::PopMenu* ue::PopMenu::getInstance()
{
	return sPopMenu;
}
