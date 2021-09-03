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
		this->onDrawNode2DBodyChange();
	});

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onDrawNode2DColorChange();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->onDrawNode2DTextureChange();
	});

	return true;
}

void render::DrawNode2D::onDrawNode2DBodyChange()
{
	VertexTool::setTexture2DVertices(&_rectVertex, math::Vector3(), _volume, _anchor);

	updateDrawNode2DMesh();
}

void render::DrawNode2D::onDrawNode2DColorChange()
{
	_rectVertex.setLeftDownColor(_color);
	_rectVertex.setRightDownColor(_color);
	_rectVertex.setRightUpColor(_color);
	_rectVertex.setLeftUpColor(_color);

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

void render::DrawNode2D::updateDrawNode2DMesh()
{
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
	DrawNode::afterDraw();
}

