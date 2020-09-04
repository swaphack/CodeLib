#include "MapNode.h"


alg::MapNode::MapNode()
{

}


alg::MapNode::~MapNode()
{

}

alg::MapNode::MapNode(const math::Vector2& position)
{
	_position = position;
}

alg::MapNode::MapNode(const math::Vector3& position)
{
	_position = position;
}

void alg::MapNode::setPosition(const math::Vector2& pos)
{
	_position = pos;
}


void alg::MapNode::setPosition(const math::Vector3& pos)
{
	_position = pos;
}

const math::Vector3& alg::MapNode::getPosition() const
{
	return _position;
}


