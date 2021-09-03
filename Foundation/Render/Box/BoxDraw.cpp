#include "BoxDraw.h"
#include "2d/Primitive/PrimitiveNode.h"
#include "BoxDrawProtocol.h"

static render::BoxDraw* sIntance = nullptr;

render::BoxDraw::BoxDraw()
{
	sIntance = this;
}

render::BoxDraw::~BoxDraw()
{
	sIntance = nullptr;
}

render::BoxDraw* render::BoxDraw::getInstance()
{
	return sIntance;
}

bool render::BoxDraw::init()
{
	if (!Node::init())
	{
		return false;
	}

	_drawNode = CREATE_NODE(PrimitiveNode);
	_drawNode->setDrawMode(DrawMode::TRIANGLES);
	this->addChild(_drawNode);

	return true;
}

void render::BoxDraw::addBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	_boxes.insert(box);
}

void render::BoxDraw::removeBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	_boxes.erase(box);
}

void render::BoxDraw::updateNode()
{
	_drawNode->removeAllPoints();
	for (auto item : _boxes)
	{
		if (!item->isBoxVisible()) continue;
		std::vector<math::TrianglePoints> vecPoints;
		item->getBoxPoints(vecPoints);
		for (auto point : vecPoints)
		{
			phy::Color4F color;
			phy::convertColor4BTo4F(item->getBoxColor(), color);
			_drawNode->appendPoints(point.getLength(), point.getValue(), color);
		}
	}

	Node::updateNode();
}

render::DrawNode* render::BoxDraw::getRenderNode()
{
	return _drawNode;
}
