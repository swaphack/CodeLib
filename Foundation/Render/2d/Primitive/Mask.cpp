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

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->onMaskBodyChange();
	});

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onMaskBodyChange();
	});

	this->setDrawMode(DrawMode::TRIANGLES);

	return true;
}

void render::Mask::onMaskBodyChange()
{
	this->removeAllPoints();
	this->appendPoint(_localRectPoints.leftDown, getColor());
	this->appendPoint(_localRectPoints.rightDown, getColor());
	this->appendPoint(_localRectPoints.rightUp, getColor());

	this->appendPoint(_localRectPoints.leftDown, getColor());
	this->appendPoint(_localRectPoints.rightUp, getColor());
	this->appendPoint(_localRectPoints.leftUp, getColor());
}
