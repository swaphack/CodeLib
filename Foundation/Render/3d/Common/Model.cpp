#include "Model.h"

using namespace render;


Model::Model()
{
	this->setBoxNode(this);
}

Model::~Model()
{
}

bool render::Model::init()
{
	if (!DrawNode3D::init())
	{
		return false;
	}

	Box3DDrawProtocol::initBox3D(this);

	return true;
}

bool render::Model::containPoint(const math::Vector2& touchPoint)
{
	return Box3DDrawProtocol::containsTouchPoint(touchPoint);
}

