#include "ViewPort.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
using namespace render;


ViewPort::ViewPort()
{
}

ViewPort::~ViewPort()
{
}

void render::ViewPort::setViewRect(float x, float y, float width, float height)
{
	_viewRect.set(x, y, width, height);
	this->setDirty(true);
}

void render::ViewPort::setSubViewRect(uint32_t index, float x, float y, float width, float height)
{
	_subViewRect[index] = math::Rect(x, y, width, height);
	this->setDirty(true);
}

math::Rect render::ViewPort::getSubViewRect(uint32_t index) const
{
	// TODO: 在此处插入 return 语句
	auto it = _subViewRect.find(index);
	if (it == _subViewRect.end())
	{
		return math::Rect();
	}
	return it->second;
}

void ViewPort::updateView()
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

void render::ViewPort::initViewPort()
{
	if (!isDirty())
	{
		return;
	}
	GLState::setViewport(_viewRect);

	if (_subViewRect.size() != 0)
	{
		for (const auto& item : _subViewRect)
		{
			GLState::setViewportIndexed(item.first, item.second);
		}
	}

	setDirty(false);
}

void ViewPort::applyConfig()
{
	GLState::enable(EnableMode::PROGRAM_POINT_SIZE);
	GLDebug::showError();
	GLState::enable(EnableMode::DEPTH_TEST);
	GLState::setDepthFunc(DepthFunction::LEQUAL);

	GLState::enable(EnableMode::STENCIL_TEST);
	GLState::enable(EnableMode::ALPHA_TEST);

	GLFixedFunction::setShadeModel(ShadingModel::SMOOTH);
	GLState::setPerspectiveCorrectionHint(HintMode::NICEST);

	GLState::enable(EnableMode::CULL_FACE);
	GLState::setCullFace(FaceType::BACK);
	GLState::setFrontFace(FrontFaceDirection::CCW);
	GLDebug::showError();
}
