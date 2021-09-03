#include "SinglePanel.h"

ue::SinglePanel::SinglePanel()
{
	this->setTouchEnabled(true);
	this->setTouchSwallowed(true);
}

ue::SinglePanel::~SinglePanel()
{
}

bool ue::SinglePanel::init()
{
	if (!Panel::init())
	{
		return false;
	}

	this->addTouchFunc(render::TouchType::ENDED, [this](const math::Vector2& touchPoint) {
		if (!_body->containTouchPoint(touchPoint))
		{
			close();
		}
	});

	return true;
}

const char* ue::SinglePanel::getPanelPath()
{
	return nullptr;
}

void ue::SinglePanel::updatePosition(const ui::CtrlWidget* item, sys::CSSDirection eDir)
{
	if(item == nullptr)
	{
		return;
	}

	auto pRectPoints = &item->getBoxVertex();

	if (eDir == sys::CSSDirection::Top)
	{
		float x = pRectPoints->getLeftTop().getX();
		float y = pRectPoints->getLeftTop().getY();
		this->setPositionLeftBottom(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Right)
	{
		float x = pRectPoints->getRightBottom().getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->getRightBottom().getY();
		this->setPositionLeftTop(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Bottom)
	{
		float x = pRectPoints->getLeftBottom().getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->getLeftBottom().getY();
		this->setPositionLeftTop(math::Vector2(x, y));
	}
	else if (eDir == sys::CSSDirection::Left)
	{
		float x = render::Tool::getGLViewWidth() - pRectPoints->getLeftTop().getX();
		float y = render::Tool::getGLViewHeight() - pRectPoints->getLeftTop().getY();
		this->setPositionRightTop(math::Vector2(x, y));
	}
}

void ue::SinglePanel::show()
{
	render::Canvas::getInstance()->getCurScene()->addChild(this, 0);
}

void ue::SinglePanel::showWithTarget(const ui::CtrlWidget* item, sys::CSSDirection eDir)
{
	this->updatePosition(item, eDir);
	this->show();
}

void ue::SinglePanel::close()
{
	this->getActionProxy()->runAction(render::SequenceAction::create(
		render::DelayAction::create(1),
		render::CallFunc::create([this]() { this->removeFromParent(); })
	));
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

	getLayoutItem()->setMargin(margin);
	getLayoutItem()->setMarginState(state);
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

	getLayoutItem()->setMargin(margin);
	getLayoutItem()->setMarginState(state);
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

	getLayoutItem()->setMargin(margin);
	getLayoutItem()->setMarginState(state);
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

	getLayoutItem()->setMargin(margin);
	getLayoutItem()->setMarginState(state);
}