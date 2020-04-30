#include "DrawNode.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
using namespace render;


DrawNode::DrawNode()
{
}

DrawNode::~DrawNode()
{
}

void DrawNode::drawSample()
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
		GLVertex::setVertex((item));
	}
	GLVertex::endMode();
}

void DrawNode::setWidth( float width )
{
	_width = width;
}

float DrawNode::getWidth()
{
	return _width;
}

void DrawNode::setDrawMode(ShapeMode mode)
{
	_drawMode = mode;
}

ShapeMode DrawNode::getDrawMode()
{
	return _drawMode;
}

void DrawNode::appendPoint(const math::Vector3& point)
{
	math::Vector3 pos;
	Tool::convertToOGLPoisition(point, pos);
	_points.push_back(pos);
}

void DrawNode::appendPoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->appendPoint(temp);
}

void DrawNode::removePoint(const math::Vector3& point)
{
	math::Vector3 pos;
	Tool::convertToOGLPoisition(point, pos);

	std::vector<math::Vector3>::iterator it = _points.begin();
	while (it != _points.end())
	{
		if ((*it) == pos)
		{
			_points.erase(it);
			return;
		}
		it++;
	}
}

void DrawNode::removePoint(const math::Vector2& point)
{
	math::Vector3 temp = point;
	this->removePoint(temp);
}

void DrawNode::removeAllPoints()
{
	_points.clear();
}

void DrawNode::setPoints(const std::vector<math::Vector3>& points)
{
	_points.clear();

	std::vector<math::Vector3>::const_iterator it = points.begin();
	while (it != points.end())
	{
		math::Vector3 pos;
		Tool::convertToOGLPoisition(*it, pos);
		_points.push_back(pos);
		it++;
	}
}
