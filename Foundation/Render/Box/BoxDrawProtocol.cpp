#include "BoxDrawProtocol.h"
#include "Graphic/import.h"
#include "Common/Scene/DebugDraw.h"
#include "Common/Scene/Camera.h"
#include "Common/Scene/Camera3D.h"
#include "Common/Scene/Cameras.h"
#include "BoxDraw.h"
#include "Common/Tool/VertexTool.h"

render::BoxDrawProtocol::BoxDrawProtocol()
{

}

render::BoxDrawProtocol::~BoxDrawProtocol()
{
	this->setBoxVisible(false);
}

void render::BoxDrawProtocol::setBoxVisible(bool bVisible)
{
	if (_bBoxVisible == bVisible) return;

	_bBoxVisible = bVisible;

	if (BoxDraw::getInstance() == nullptr) 
		return;

	if (bVisible)
	{
		BoxDraw::getInstance()->addBox(this);
	}
	else
	{
		BoxDraw::getInstance()->removeBox(this);
	}
}

bool render::BoxDrawProtocol::isBoxVisible() const
{
	return _bBoxVisible;
}

void render::BoxDrawProtocol::setBoxColor(const phy::Color4B& color)
{
	_boxColor = color;
}

const phy::Color4B& render::BoxDrawProtocol::getBoxColor() const
{
	return _boxColor;
}

float render::BoxDrawProtocol::getBoxLineWidth() const
{
	return _boxLineWidth;
}

void render::BoxDrawProtocol::setBoxLineWidth(float width)
{
	_boxLineWidth = width;
}

render::BoxDrawType render::BoxDrawProtocol::getBoxDrawType() const
{
	return _boxDrawType;
}

render::Node* render::BoxDrawProtocol::getBoxNode() const
{
	return m_pBoxNode;
}

bool render::BoxDrawProtocol::containsTouchPoint(const math::Vector2& touchPoint)
{
	return false;
}

void render::BoxDrawProtocol::getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const
{
	vecPoints = _boxPoints;
}

void render::BoxDrawProtocol::setBoxNode(render::Node* node)
{
	m_pBoxNode = node;
}

/////////////////////////////////////////////////////////////////////////
render::Box2DDrawProtocol::Box2DDrawProtocol()
{
	_boxDrawType = BoxDrawType::TWO;
}

render::Box2DDrawProtocol::~Box2DDrawProtocol()
{

}

void render::Box2DDrawProtocol::initBox2D(render::Node* node)
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
}

void render::Box2DDrawProtocol::setBoxVertices(const render::RectVertex& rectVertex)
{
	_boxPoints.clear();
	rectVertex.toTriangles(_boxPoints);
}

const render::RectVertex& render::Box2DDrawProtocol::getLocalRectVertex() const
{
	return _localRectVertex;
}

bool render::Box2DDrawProtocol::containsTouchPoint(const math::Vector2& touchPoint)
{
	math::Polygon rect = _worldRectVertex;

	return rect.contains(touchPoint);
}

void render::Box2DDrawProtocol::onBox2DCubeChange()
{
	if (this->getBoxNode() == nullptr)
	{
		return;
	}

	auto pBoxNode = this->getBoxNode();

	VertexTool::setTexture2DVertices(&_localRectVertex, math::Vector3(), pBoxNode->getVolume(), pBoxNode->getAnchorPoint());

	onBox2DWorldCubeChange();
}

void render::Box2DDrawProtocol::onBox2DWorldCubeChange()
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
}

/////////////////////////////////////////////////////////////////////////
render::Box3DDrawProtocol::Box3DDrawProtocol()
{
	_boxDrawType = BoxDrawType::THREE;
}

render::Box3DDrawProtocol::~Box3DDrawProtocol()
{

}
void render::Box3DDrawProtocol::initBox3D(render::Node* node)
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
}
void render::Box3DDrawProtocol::setBoxVertices(const render::CubeVertex& cubeVertex)
{
	_boxPoints.clear();
	cubeVertex.toTriangles(_boxPoints);
}
const render::CubeVertex& render::Box3DDrawProtocol::getLocalCubeVertex() const
{
	return _localCubeVertex;
}
bool render::Box3DDrawProtocol::containsTouchPoint(const math::Vector2& touchPoint)
{
	if (this->getBoxNode() == nullptr || this->getBoxNode()->getCamera() == nullptr)
		return false;
	auto pCamera = this->getBoxNode()->getCamera();
	math::Ray cameraRay = pCamera->convertScreenPointToWorldRay(touchPoint);
	pCamera->getDebugDraw()->drawW2LLine(cameraRay.getSrcPoint(), cameraRay.getDestPoint(10000), phy::Color4F(1.0f,0,0,1.0f));

	std::vector<math::TrianglePoints> trianglePoints;
	_worldCubeVertex.toTriangles(trianglePoints);

	math::Vector3 point;
	for (auto item : trianglePoints)
	{
		if (math::Physics::raycast(cameraRay, item, point))
		{
			return true;
		}
	}
	return false;
}

void render::Box3DDrawProtocol::onBox3DCubeChange()
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

void render::Box3DDrawProtocol::onBox3DWorldCubeChange()
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
}
