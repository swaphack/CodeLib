#include "BoxDraw.h"
#include "2d/Primitive/PrimitiveNode.h"
#include "BoxDrawProtocol.h"
#include "Common/Scene/Cameras.h"

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

	_drawNode3d = CREATE_NODE(PrimitiveNode);
	_drawNode3d->setDrawMode(DrawMode::LINES);
	_drawNode3d->setCamera(G_CAMERAS->getCamera3D());
	this->addChild(_drawNode3d);


	_drawNode2d = CREATE_NODE(PrimitiveNode);
	_drawNode2d->setDrawMode(DrawMode::LINES);
	_drawNode2d->setCamera(G_CAMERAS->getCamera2D());
	this->addChild(_drawNode2d);

	addNotifyListener(render::NodeNotifyType::GEOMETRY, [this]() {
		this->onBoxChanged();
	});

	return true;
}

void render::BoxDraw::addBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	_boxes.insert(box);

	if (box->getBoxNode())
	{
		box->getBoxNode()->addNotifyListener(render::NodeNotifyType::SPACE, this,  [this]() {
			this->onBoxChanged();
		});
	}

	this->notify(render::NodeNotifyType::GEOMETRY);
}

void render::BoxDraw::removeBox(BoxDrawProtocol* box)
{
	if (box == nullptr) return;

	_boxes.erase(box);
	if (box->getBoxNode())
	{
		box->getBoxNode()->removeNotifyListener(render::NodeNotifyType::SPACE, this);
	}
	this->notify(render::NodeNotifyType::GEOMETRY);
}
render::PrimitiveNode* render::BoxDraw::getRenderNode2d()
{
	return _drawNode2d;
}

render::PrimitiveNode* render::BoxDraw::getRenderNode3d()
{
	return _drawNode3d;
}

void render::BoxDraw::onBoxChanged()
{
	_drawNode2d->removeAllPoints();
	_drawNode3d->removeAllPoints();

	for (auto item : _boxes)
	{
		std::vector<math::TrianglePoints> vecPoints;
		item->getBoxPoints(vecPoints);
		for (auto point : vecPoints)
		{
			phy::Color4F color;
			phy::convertColor4BTo4F(item->getBoxColor(), color);
			if (item->getBoxDrawType() == render::BoxDrawType::TWO)
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
