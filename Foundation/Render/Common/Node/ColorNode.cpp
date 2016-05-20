#include "ColorNode.h"

using namespace render;


ColorNode::ColorNode()
{

}

ColorNode::~ColorNode()
{

}

void ColorNode::draw()
{
	Node::draw();
}

void ColorNode::setBlend(int src, int dest)
{
	_blend.src = src;
	_blend.dest = dest;
}

const BlendParam& ColorNode::getBlend()
{
	return _blend;
}


