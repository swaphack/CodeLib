#include "View.h"
#include "Graphic/import.h"
#include "Camera.h"
using namespace render;


View::View()
{
}

View::~View()
{
}

const ViewConfig* View::getConfig()
{
	return &_viewConfig;
}

void View::setPosition(float x, float y)
{
	_position.set(x, y);
	this->setDirty(true);
}

const math::Vector2& View::getPosition()
{
	return _position;
}

void View::setFrameSize(float width, float height)
{
	_size.setWidth(width);
	_size.setHeight(height);
	this->setDirty(true);
}

const math::Size& View::getFrameSize()
{
	return _size;
}

void View::updateView()
{
	GLState::setStencilMask(0xff);
	uint32_t bitfield = (uint32_t)ClearBufferBitType::COLOR_BUFFER_BIT | (uint32_t)ClearBufferBitType::DEPTH_BUFFER_BIT | (uint32_t)ClearBufferBitType::STENCIL_BUFFER_BIT;
	GLRender::clearColor(0, 0, 0, 0);
	GLRender::clearDepth(1.0f);
	GLRender::clearStencil(0x0);
	GLRender::clear(bitfield);
	GLState::setStencilMask(0x00);

	GLDebug::showError();
}

void render::View::initViewPort()
{
	GLState::setViewport(_position.getX(), _position.getY(), _size.getWidth(), _size.getHeight());
}

void View::applyConfig()
{
	GLDebug::showError();
	GLState::enable(EnableMode::DEPTH_TEST);
	GLState::setDepthFunc(DepthFunction::LEQUAL);

	GLState::enable(EnableMode::STENCIL_TEST);

	GLFixedFunction::setShadeModel(ShadingModel::SMOOTH);
	GLState::setPerspectiveCorrectionHint(HintMode::NICEST);

	GLState::enable(EnableMode::CULL_FACE);
	GLState::setCullFace(FaceType::BACK);
	GLState::setFrontFace(FrontFaceDirection::CCW);
	GLDebug::showError();
}
