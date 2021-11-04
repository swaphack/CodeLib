#include "BoxDraw.h"
#include "2d/Primitive/PrimitiveNode.h"
#include "BoxProtocol.h"
#include "Common/Scene/Cameras.h"
#include "BoxSpace.h"

static render::BoxDraw* sIntance = nullptr;

render::BoxDraw::BoxDraw()
{
	G_BOXSPACE->setBoxDraw(this);
}

render::BoxDraw::~BoxDraw()
{
	G_BOXSPACE->setBoxDraw(nullptr);
}

bool render::BoxDraw::init()
{
	if (!Node::init())
	{
		return false;
	}

	_drawNode3d = CREATE_NODE(PrimitiveNode);
	_drawNode3d->setDrawMode(DrawMode::LINES);
	_drawNode3d->setCamera(G_CAMERAS->getCamera3D());
	this->addChild(_drawNode3d);


	_drawNode2d = CREATE_NODE(PrimitiveNode);
	_drawNode2d->setDrawMode(DrawMode::LINES);
	_drawNode2d->setCamera(G_CAMERAS->getCamera2D());
	this->addChild(_drawNode2d);

	addNotifyListener(render::NodeNotifyType::GEOMETRY, [this]() {
		this->refreshBoxes();
	});

	return true;
}

void render::BoxDraw::setAllBoxesVisibled(bool status)
{
	if (_showAllBoxes == status)
	{
		return;
	}
	_showAllBoxes = status;
	this->notify(render::NodeNotifyType::GEOMETRY);
}

bool render::BoxDraw::isAllBoxesVisibled() const
{
	return _showAllBoxes;
}

render::PrimitiveNode* render::BoxDraw::getRenderNode2d()
{
	return _drawNode2d;
}

render::PrimitiveNode* render::BoxDraw::getRenderNode3d()
{
	return _drawNode3d;
}

void render::BoxDraw::refreshBoxes()
{
	_drawNode2d->removeAllPoints();
	_drawNode3d->removeAllPoints();

	for (const auto& item : G_BOXSPACE->getAllBoxes())
	{
		auto pBoxNode = item.second->getBoxNode();
		if (pBoxNode == nullptr) continue;
		if (!isAllBoxesVisibled())
		{
			if (!pBoxNode->isVisible() || !item.second->isBoxVisible()) continue;
		}

		std::vector<math::TrianglePoints> vecPoints;
		item.second->getBoxPoints(vecPoints);
		if (vecPoints.size() == 0) continue;
		for (auto point : vecPoints)
		{
			phy::Color4F color;
			phy::convertColor4BTo4F(item.second->getBoxColor(), color);
			if (item.second->getBoxDrawType() == render::BoxDrawType::TWO)
			{
				_drawNode2d->appendPoint(point.getPoint0(), color);
				_drawNode2d->appendPoint(point.getPoint1(), color);

				_drawNode2d->appendPoint(point.getPoint1(), color);
				_drawNode2d->appendPoint(point.getPoint2(), color);

				_drawNode2d->appendPoint(point.getPoint2(), color);
				_drawNode2d->appendPoint(point.getPoint0(), color);
				
			}
			else
			{
				_drawNode3d->appendPoint(point.getPoint0(), color);
				_drawNode3d->appendPoint(point.getPoint1(), color);

				_drawNode3d->appendPoint(point.getPoint1(), color);
				_drawNode3d->appendPoint(point.getPoint2(), color);

				_drawNode3d->appendPoint(point.getPoint2(), color);
				_drawNode3d->appendPoint(point.getPoint0(), color);
			}
		}
	}
}
