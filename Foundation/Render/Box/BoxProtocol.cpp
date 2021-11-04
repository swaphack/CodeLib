#include "BoxProtocol.h"
#include "Graphic/import.h"
#include "Common/Scene/DebugDraw.h"
#include "Common/Scene/Camera.h"
#include "Common/Scene/Camera3D.h"
#include "Common/Scene/Cameras.h"
#include "BoxDraw.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "BoxSpace.h"

render::BoxProtocol::BoxProtocol()
{
}

render::BoxProtocol::~BoxProtocol()
{
	G_BOXSPACE->removeBox(this);
}

void render::BoxProtocol::setBoxID(int id)
{
	_boxID = id;
}

int render::BoxProtocol::getBoxID() const
{
	return _boxID;
}

void render::BoxProtocol::setBoxVisible(bool bVisible)
{
	if (_bBoxVisible == bVisible) return;

	_bBoxVisible = bVisible;
	if (_boxNode)
	{
		_boxNode->notify(render::NodeNotifyType::Draw);
	}
	//G_BOXSPACE->updateBox(this);
}

bool render::BoxProtocol::isBoxVisible() const
{
	return _bBoxVisible;
}

void render::BoxProtocol::setBoxColor(const phy::Color4B& color)
{
	_boxColor = color;
}

const phy::Color4B& render::BoxProtocol::getBoxColor() const
{
	return _boxColor;
}

float render::BoxProtocol::getBoxLineWidth() const
{
	return _boxLineWidth;
}

void render::BoxProtocol::setBoxLineWidth(float width)
{
	_boxLineWidth = width;
}

render::BoxDrawType render::BoxProtocol::getBoxDrawType() const
{
	return _boxDrawType;
}

render::Node* render::BoxProtocol::getBoxNode() const
{
	return _boxNode;
}

void render::BoxProtocol::getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const
{
	vecPoints = _boxPoints;
}

const std::vector<math::TrianglePoints>& render::BoxProtocol::getBoxPoints() const
{
	return _boxPoints;
}

void render::BoxProtocol::setBoxNode(render::Node* node)
{
	_boxNode = node;
}

/////////////////////////////////////////////////////////////////////////
render::Box2DProtocol::Box2DProtocol()
{
	_boxDrawType = BoxDrawType::TWO;
}

render::Box2DProtocol::~Box2DProtocol()
{

}

void render::Box2DProtocol::initBox2D(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	this->setBoxNode(node);

	// 添加属性改变监听
	this->getBoxNode()->addNotifyListener(NodeNotifyType::BODY, [this]() {
		onBox2DCubeChange();
	});
	this->getBoxNode()->addNotifyListener(NodeNotifyType::SPACE, [this]() {
		onBox2DWorldCubeChange();
	});


	G_BOXSPACE->addBox(this);
}

void render::Box2DProtocol::setBoxVertices(const render::RectVertex& rectVertex)
{
	_boxPoints.clear();
	rectVertex.toTriangles(_boxPoints);

	_boxPolygon = rectVertex;
	_boxRect = _boxPolygon.getBoundingBox();
}

const render::RectVertex& render::Box2DProtocol::getLocalRectVertex() const
{
	return _localRectVertex;
}

const render::RectVertex& render::Box2DProtocol::getWorldRectVertex() const
{
	return _worldRectVertex;
}

const math::Polygon& render::Box2DProtocol::getBoxPolygon() const
{
	return _boxPolygon;
}

const math::Rect& render::Box2DProtocol::getBoxRect() const
{
	return _boxRect;
}

void render::Box2DProtocol::setBoxRect(const math::Rect& rect)
{
	_boxRect = rect;
}

bool render::Box2DProtocol::isOverlap(const Box2DProtocol* box2d)
{
	if (box2d == nullptr)
	{
		return false;
	}
	if (!this->getBoxRect().isOverlap(box2d->getBoxRect()))
	{
		return false;
	}

	if (this->getBoxPolygon().getPointCount() == 0
		|| box2d->getBoxPolygon().getPointCount() == 0)
	{
		return true;
	}

	return this->getBoxPolygon().intersects(box2d->getBoxPolygon());
}

void render::Box2DProtocol::onBox2DCubeChange()
{
	if (this->getBoxNode() == nullptr)
	{
		return;
	}

	auto pBoxNode = this->getBoxNode();

	VertexTool::setTexture2DVertices(&_localRectVertex, math::Vector3(), pBoxNode->getVolume(), pBoxNode->getAnchorPoint());

	onBox2DWorldCubeChange();
}

void render::Box2DProtocol::onBox2DWorldCubeChange()
{
	if (this->getBoxNode() == nullptr)
	{
		return;
	}

	auto pBoxNode = this->getBoxNode();

	_worldRectVertex.setLeftBottomPosition(pBoxNode->convertLocalToWorldPoint(_localRectVertex.getLeftBottomPosition()));
	_worldRectVertex.setRightBottomPosition(pBoxNode->convertLocalToWorldPoint(_localRectVertex.getRightBottomPosition()));
	_worldRectVertex.setRightTopPosition(pBoxNode->convertLocalToWorldPoint(_localRectVertex.getRightTopPosition()));
	_worldRectVertex.setLeftTopPosition(pBoxNode->convertLocalToWorldPoint(_localRectVertex.getLeftTopPosition()));

	setBoxVertices(_worldRectVertex);

	G_BOXSPACE->updateBox(this);
}

/////////////////////////////////////////////////////////////////////////
render::Box3DProtocol::Box3DProtocol()
{
	_boxDrawType = BoxDrawType::THREE;
}

render::Box3DProtocol::~Box3DProtocol()
{

}
void render::Box3DProtocol::initBox3D(render::Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	this->setBoxNode(node);

	// 添加属性改变监听
	this->getBoxNode()->addNotifyListener(NodeNotifyType::BODY, [this]() {
		onBox3DCubeChange();
	});
	this->getBoxNode()->addNotifyListener(NodeNotifyType::SPACE, [this]() {
		onBox3DWorldCubeChange();
	});

	G_BOXSPACE->addBox(this);
}
void render::Box3DProtocol::setBoxVertices(const render::CubeVertex& cubeVertex)
{
	_boxPoints.clear();
	cubeVertex.toTriangles(_boxPoints);

	//_boxPolygon = rectVertex;
	//_boxCuboids = _boxPolygon.getBoundingBox();
}	

const render::CubeVertex& render::Box3DProtocol::getLocalCubeVertex() const
{
	return _localCubeVertex;
}

const render::CubeVertex& render::Box3DProtocol::getWorldCubeVertex() const
{
	return _worldCubeVertex;
}

const math::Cuboids& render::Box3DProtocol::getBoxCuboids() const
{
	return _boxCuboids;
}

void render::Box3DProtocol::setBoxCuboids(const math::Cuboids& cuboids)
{
	_boxCuboids = cuboids;
}

void render::Box3DProtocol::onBox3DCubeChange()
{
	if (this->getBoxNode() == nullptr)
	{
		return;
	}
	auto pBoxNode = this->getBoxNode();

	render::VertexTool::setTexture3DVertices(&_localCubeVertex, 
		math::Vector3(), pBoxNode->getVolume(), pBoxNode->getAnchorPoint());
	onBox3DWorldCubeChange();
}

void render::Box3DProtocol::onBox3DWorldCubeChange()
{
	if (this->getBoxNode() == nullptr)
	{
		return;
	}

	auto pBoxNode = this->getBoxNode();

	_worldCubeVertex.setFrontLeftBottomPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.front.getLeftBottomPosition()));
	_worldCubeVertex.setFrontRightBottomPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.front.getRightBottomPosition()));
	_worldCubeVertex.setFrontRightTopPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.front.getRightTopPosition()));
	_worldCubeVertex.setFrontLeftTopPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.front.getLeftTopPosition()));

	_worldCubeVertex.setBackLeftBottomPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.back.getLeftBottomPosition()));
	_worldCubeVertex.setBackRightBottomPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.back.getRightBottomPosition()));
	_worldCubeVertex.setBackRightTopPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.back.getRightTopPosition()));
	_worldCubeVertex.setBackLeftTopPosition(pBoxNode->convertLocalToWorldPoint(_localCubeVertex.back.getLeftTopPosition()));

	setBoxVertices(_worldCubeVertex);

	G_BOXSPACE->updateBox(this);
}
