#include "PrimitiveNode.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"
using namespace render;


PrimitiveNode::PrimitiveNode()
{
}

PrimitiveNode::~PrimitiveNode()
{
}

bool render::PrimitiveNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	return false;
}

void PrimitiveNode::onDraw()
{
	if (_drawMode == ShapeMode::POINTS)
	{
		GLState::setPointSize(_width);
	}
	else
	{
		GLState::setLineWidth(_width);
	}

	GLVertex::beginMode(_drawMode);
	GLVertex::setColor(getColor());
	for (auto item : _points)
	{
		GLVertex::setVertex(item);
	}
	GLVertex::endMode();
}

void PrimitiveNode::setWidth( float width )
{
	_width = width;
}

float PrimitiveNode::getWidth()
{
	return _width;
}

void PrimitiveNode::setDrawMode(ShapeMode mode)
{
	_drawMode = mode;
}

ShapeMode PrimitiveNode::getDrawMode()
{
	return _drawMode;
}

void PrimitiveNode::appendPoint(const math::Vector3& point)
{
	_points.push_back(point);
}

void PrimitiveNode::appendPoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->appendPoint(temp);
}

void PrimitiveNode::removePoint(const math::Vector3& point)
{
	std::vector<math::Vector3>::iterator it = _points.begin();
	while (it != _points.end())
	{
		if ((*it) == point)
		{
			_points.erase(it);
			return;
		}
		it++;
	}
}

void PrimitiveNode::removePoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->removePoint(temp);
}

void PrimitiveNode::removeAllPoints()
{
	_points.clear();
}

void render::PrimitiveNode::setColor(const sys::Color4F& color)
{
	_color = color;
}

const sys::Color4F& render::PrimitiveNode::getColor() const
{
	return _color;
}

void PrimitiveNode::setPoints(const std::vector<math::Vector3>& points)
{
	_points.clear();

	std::vector<math::Vector3>::const_iterator it = points.begin();
	while (it != points.end())
	{
		math::Vector3 pos;
		_points.push_back(pos);
		it++;
	}
}
