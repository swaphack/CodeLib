#include "PrimitiveNode.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

using namespace render;


PrimitiveNode::PrimitiveNode()
{
}

PrimitiveNode::~PrimitiveNode()
{
}

void PrimitiveNode::drawing()
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
