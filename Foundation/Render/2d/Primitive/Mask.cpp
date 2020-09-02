#include "Mask.h"
#include "Graphic/import.h"
using namespace render;

Mask::Mask()
{
}

Mask::~Mask()
{

}

bool render::Mask::init()
{
	if (!PrimitiveNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->onMaskBodyChange();
	});

	_notify->addListen(NodeNotifyType::COLOR, [this]() {
		this->onMaskBodyChange();
	});

	this->setDrawMode(DrawMode::TRIANGLES);

	return true;
}

void render::Mask::onMaskBodyChange()
{
	this->removeAllPoints();
	this->appendPoint(_rectVertex.leftDown, getColor());
	this->appendPoint(_rectVertex.rightDown, getColor());
	this->appendPoint(_rectVertex.rightUp, getColor());

	this->appendPoint(_rectVertex.leftDown, getColor());
	this->appendPoint(_rectVertex.rightUp, getColor());
	this->appendPoint(_rectVertex.leftUp, getColor());
}
