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

void View::initView()
{
	if (isDirty())
	{
		// 定义视窗位置
		GLPrimitive::setViewport(_position.getX(), _position.getY(), _size.getWidth(), _size.getHeight());

		this->applyConfig();

		setDirty(false);
	}
}

void View::updateView()
{
	GLPixels::clearBuffer(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	GLPixels::clearColor(0, 0, 0, 1.0f);
	GLPixels::clearDepth(1.0f);
	GLPixels::clearStencil(0);

	GLDebug::showError();
}

void View::applyConfig()
{
	GLSetting::setShadeModel(ShadingModel::SMOOTH);
	GLSetting::setPerspectiveCorrectionHint(HintMode::NICEST);

	GLState::enable(EnableModel::DEPTH_TEST);
	GLFragment::testDepth(DepthFunction::LEQUAL);
	GLPrimitive::setCullFace(CullFaceMode::BACK);
	GLPrimitive::setFrontFace(FrontFaceDirection::CCW);
	GLPrimitive::setPixelStore(PixelStore::UNPACK_ALIGNMENT, 1);

	GLDebug::showError();
}
