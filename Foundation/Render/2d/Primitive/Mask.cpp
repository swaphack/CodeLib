#include "Mask.h"
#include "Graphic/import.h"
#include "Common/Tool/VertexTool.h"
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
	render::RectVertex rectVertex;
	render::VertexTool::setTexture2DVertices(&rectVertex, math::Vector3(), _volume, _anchor);

	this->removeAllPoints();
	this->appendPoint(rectVertex.getLeftBottomPosition(), getColor());
	this->appendPoint(rectVertex.getRightBottomPosition(), getColor());
	this->appendPoint(rectVertex.getRightTopPosition(), getColor());

	this->appendPoint(rectVertex.getLeftBottomPosition(), getColor());
	this->appendPoint(rectVertex.getRightTopPosition(), getColor());
	this->appendPoint(rectVertex.getLeftTopPosition(), getColor());
}
