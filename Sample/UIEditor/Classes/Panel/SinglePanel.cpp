#include "SinglePanel.h"

ue::SinglePanel::SinglePanel()
{

	this->setTouchEnable(true);
}

ue::SinglePanel::~SinglePanel()
{
}

const char* ue::SinglePanel::getPanelPath()
{
	return nullptr;
}

void ue::SinglePanel::updatePosition(const ui::LayoutItem* item, sys::CSSDirection eDir)
{
	if(item == nullptr)
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

void ue::SinglePanel::show()
{
	render::RenderApplication::getInstance()->getCanvas()->getCurScene()->addChild(this);
}

void ue::SinglePanel::showWithTarget(const ui::LayoutItem* item, sys::CSSDirection eDir)
{
	this->updatePosition(item, eDir);
	this->show();
}

void ue::SinglePanel::close()
{
	this->removeFromParent();
}

void ue::SinglePanel::setPositionLeftTop(const math::Vector2& pos)
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

void ue::SinglePanel::setPositionRightTop(const math::Vector2& pos)
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

void ue::SinglePanel::setPositionLeftBottom(const math::Vector2& pos)
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

void ue::SinglePanel::setPositionRightBottom(const math::Vector2& pos)
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

bool ue::SinglePanel::onTouchBegan(float x, float y, bool include)
{
	if (!_body->containPoint(x, y))
	{
		close();
	}
	return false;
}

bool ue::SinglePanel::onTouchMoved(float x, float y, bool include)
{
	return false;
}

bool ue::SinglePanel::onTouchEnded(float x, float y, bool include)
{
	return false;
}
