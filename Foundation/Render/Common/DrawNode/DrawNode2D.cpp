#include "DrawNode2D.h"
#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"
#include "Common/Texture/Texture2D.h"

render::DrawNode2D::DrawNode2D()
{

}

render::DrawNode2D::~DrawNode2D()
{

}

bool render::DrawNode2D::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		calRealRectPoints();
		onDrawNode2DBodyChange();
	});

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::SPACE, [this]() {
		calRealRectPoints();
	});

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onDrawNode2DColorChange();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->onDrawNode2DTextureChange();
	});

	return true;
}

void render::DrawNode2D::setMeshVisible(bool bVisible)
{
	_bMeshVisible = bVisible;
}

bool render::DrawNode2D::isMeshVisible() const
{
	return _bMeshVisible;
}

const render::RectPoints& render::DrawNode2D::getLocalRectVertex() const
{
	return _localRectPoints;
}

const render::RectPoints& render::DrawNode2D::getWorldRectVertex() const
{
	return _worldRectPoints;
}

#include "Common/View/Camera.h"

bool render::DrawNode2D::containPoint(const math::Vector2& touchPoint)
{
	math::Vector3 localPosition = this->convertWorldPostitionToLocal(touchPoint);
	return _localRectPoints.containPointByPolygon(localPosition.getX(), localPosition.getY());

	//return _realRectPoints.containPointByPolygon(touchPoint.getX(), touchPoint.getY());
}

void render::DrawNode2D::calRealRectPoints()
{
	Tool::calRect(math::Vector3(), _volume, _anchor, _localRectPoints);

	if (isClippingEnabled())
	{
		_worldRectPoints.leftDown = this->convertLocalPostitionToWorld(_localRectPoints.leftDown);
		_worldRectPoints.rightDown = this->convertLocalPostitionToWorld(_localRectPoints.rightDown);
		_worldRectPoints.rightUp = this->convertLocalPostitionToWorld(_localRectPoints.rightUp);
		_worldRectPoints.leftUp = this->convertLocalPostitionToWorld(_localRectPoints.leftUp);
	}	
}

void render::DrawNode2D::onDrawNode2DBodyChange()
{
	VertexTool::setTexture2DVertices(&_rectVertex, math::Vector3(), _volume, _anchor);

	updateDrawNode2DMesh();
}

void render::DrawNode2D::onDrawNode2DColorChange()
{
	phy::Color4F color;
	convertColor4BTo4F(getColor(), color);
	_rectVertex.setLeftDownColor(color);
	_rectVertex.setRightDownColor(color);
	_rectVertex.setRightUpColor(color);
	_rectVertex.setLeftUpColor(color);

	updateDrawNode2DMesh();
}

void render::DrawNode2D::onDrawNode2DTextureChange()
{
	if (getTexture() != nullptr)
	{
		math::Size size(getTexture()->getWidth(), getTexture()->getHeight());
		math::Rect rect(math::Vector2(), math::Size(this->getWidth(), this->getHeight()));
		VertexTool::setTexture2DCoords(&_rectVertex, size, rect);
	}

	updateDrawNode2DMesh();
}

void render::DrawNode2D::drawRect()
{
	if (!isBoxVisible())
	{
		return;
	}
	GLVertex::setColor(_boxColor);
	GLState::setLineWidth(_boxWidth);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_localRectPoints.leftDown);
	GLVertex::setVertex(_localRectPoints.rightDown);
	GLVertex::setVertex(_localRectPoints.rightUp);
	GLVertex::setVertex(_localRectPoints.leftUp);
	GLVertex::endMode();
}

void render::DrawNode2D::updateDrawNode2DMesh()
{
	if (!isMeshVisible())
	{
		return;
	}
	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _rectVertex.uvs, sizeof(uvs));

		pMesh->getMeshDetail()->setVertices(4, _rectVertex.vertices, 3);
		pMesh->getMeshDetail()->setColors(4, _rectVertex.colors, 4);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, _rectVertex.indices);
	}

	this->updateMeshData();
}

void render::DrawNode2D::afterDraw()
{
	this->drawRect();
	DrawNode::afterDraw();
}

