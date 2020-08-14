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

void render::DrawNode2D::setMeshVisible(bool bVisible)
{
	_bMeshVisible = bVisible;
}

bool render::DrawNode2D::isMeshVisible()
{
	return _bMeshVisible;
}

const render::RectVectices& render::DrawNode2D::getRectVertex()
{
	return _rectVertex;
}

bool render::DrawNode2D::containTouchPoint(float x, float y)
{
	return _realRectVertex.containPointByPolygon(x, y);
}

void render::DrawNode2D::onDrawNode2DBodyChange()
{
	Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);

	_realRectVertex.leftDown = this->convertLocalPostitionToWorld(_rectVertex.leftDown);
	_realRectVertex.rightDown = this->convertLocalPostitionToWorld(_rectVertex.rightDown);
	_realRectVertex.rightUp = this->convertLocalPostitionToWorld(_rectVertex.rightUp);
	_realRectVertex.leftUp = this->convertLocalPostitionToWorld(_rectVertex.leftUp);

	if (isMeshVisible())
	{
		math::Size size = math::Size(this->getWidth(), this->getHeight());
		math::Rect rect(math::Vector2(), size);
		VertexTool::setTexture2DCoords(&_rectPosition, size, rect);
		VertexTool::setTexture2DVertices(&_rectPosition, math::Vector3(), _volume, _anchor);

		auto pMesh = getMesh();
		if (pMesh)
		{
			float uvs[8] = { 0 };
			memcpy(uvs, _rectPosition.uvs, sizeof(uvs));

			pMesh->getMeshDetail()->setVertices(4, _rectPosition.vertices, 3);
			pMesh->getMeshDetail()->setColors(4, _rectPosition.colors, 4);
			pMesh->getMeshDetail()->setUVs(4, uvs, 2);
			pMesh->getMeshDetail()->setIndices(6, _rectPosition.indices);
		}

		this->updateMeshData();
	}
}

void render::DrawNode2D::drawRect()
{
	if (!isRectVisible())
	{
		return;
	}
	GLVertex::setColor(1.0f, 0.0f, 0.0f, 1.0f);
	GLState::setLineWidth(5);

	GLVertex::beginMode(ShapeMode::LINE_LOOP);
	GLVertex::setVertex(_rectVertex.leftDown);
	GLVertex::setVertex(_rectVertex.rightDown);
	GLVertex::setVertex(_rectVertex.rightUp);
	GLVertex::setVertex(_rectVertex.leftUp);
	GLVertex::endMode();
}

