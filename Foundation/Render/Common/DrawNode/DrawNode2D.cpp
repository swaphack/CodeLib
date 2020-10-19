#include "DrawNode2D.h"
#include "Common/Tool/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"

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
	_notify->addListen(NodeNotifyType::BODY, [this]() {
		onDrawNode2DBodyChange();
	});

	_notify->addListen(NodeNotifyType::COLOR, [this]() {
		this->onDrawNode2DColorChange();
	});

	return true;
}

void render::DrawNode2D::setRectVisible(bool bVisible)
{
	_bRectVisible = bVisible;
}

bool render::DrawNode2D::isRectVisible()
{
	return _bRectVisible;
}

void render::DrawNode2D::setRectColor(const sys::Color4B& color)
{
	_rectColor = color;
}

const sys::Color4B& render::DrawNode2D::getRectColor() const
{
	return _rectColor;
}

void render::DrawNode2D::setMeshVisible(bool bVisible)
{
	_bMeshVisible = bVisible;
}

bool render::DrawNode2D::isMeshVisible()
{
	return _bMeshVisible;
}

const render::RectPoints& render::DrawNode2D::getRectVertex()
{
	return _rectPoints;
}

#include "Common/View/Camera.h"

bool render::DrawNode2D::containTouchPoint(float x, float y)
{
	/*
	math::Matrix4x4 projMat = Camera::getMainCamera()->getProjectMatrix();
	math::Matrix4x4 viewMat = Camera::getMainCamera()->getViewMatrix();
	math::Matrix4x4 modelMat = getWorldMatrix();

	math::Matrix4x4 mvpMat = projMat * viewMat * modelMat;

	render::RectPoints rectPoint;
	rectPoint.leftDown = math::Matrix4x4::transpose(_realRectPoints.leftDown, mvpMat);
	rectPoint.rightDown = math::Matrix4x4::transpose(_realRectPoints.rightDown, mvpMat);
	rectPoint.rightUp = math::Matrix4x4::transpose(_realRectPoints.rightUp, mvpMat);
	rectPoint.leftUp = math::Matrix4x4::transpose(_realRectPoints.leftUp, mvpMat);

	return rectPoint.containPointByPolygon(x, y);
	*/
	return _realRectPoints.containPointByPolygon(x, y);
}

void render::DrawNode2D::calRealRectPoints()
{
	Tool::calRect(math::Vector3(), _volume, _anchor, _rectPoints);

	_realRectPoints.leftDown = this->convertLocalPostitionToWorld(_rectPoints.leftDown);
	_realRectPoints.rightDown = this->convertLocalPostitionToWorld(_rectPoints.rightDown);
	_realRectPoints.rightUp = this->convertLocalPostitionToWorld(_rectPoints.rightUp);
	_realRectPoints.leftUp = this->convertLocalPostitionToWorld(_rectPoints.leftUp);
}

void render::DrawNode2D::onDrawNode2DBodyChange()
{
	calRealRectPoints();

	math::Size size = math::Size(this->getWidth(), this->getHeight());
	//math::Rect rect(math::Vector2(), size);
	//VertexTool::setTexture2DCoords(&_rectVertex, size, rect);
	VertexTool::setTexture2DVertices(&_rectVertex, math::Vector3(), _volume, _anchor);

	updateDrawNode2DMesh();
}

void render::DrawNode2D::onDrawNode2DColorChange()
{
	sys::Color4F color;
	convertColor4BTo4F(getColor(), color);
	_rectVertex.setLeftDownColor(color);
	_rectVertex.setRightDownColor(color);
	_rectVertex.setRightUpColor(color);
	_rectVertex.setLeftUpColor(color);

	updateDrawNode2DMesh();
}

void render::DrawNode2D::drawRect()
{
	if (!isRectVisible())
	{
		return;
	}
	GLVertex::setColor(_rectColor);
	GLState::setLineWidth(5);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_rectPoints.leftDown);
	GLVertex::setVertex(_rectPoints.rightDown);
	GLVertex::setVertex(_rectPoints.rightUp);
	GLVertex::setVertex(_rectPoints.leftUp);
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

