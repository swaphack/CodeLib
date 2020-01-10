#include "DrawNode.h"
#include "Graphic/import.h"
using namespace render;


DrawNode::DrawNode()
:_width(1.0)
, _drawMode(EBM_POINTS)
{
}

DrawNode::~DrawNode()
{
}

void DrawNode::draw()
{
	ColorNode::draw();	

	G_DRAWCOMMANDER->addCommand(DCDraw::create(_drawMode, _points, _width, _color, _opacity, _blend));
}

void DrawNode::setWidth( float width )
{
	_width = width;
}

float DrawNode::getWidth()
{
	return _width;
}

void DrawNode::setDrawMode(BeginMode mode)
{
	_drawMode = mode;
}

int DrawNode::getDrawMode()
{
	return _drawMode;
}

void DrawNode::initSelf()
{
	Node::initSelf();
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
