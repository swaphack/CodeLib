#include "CtrlScale9Image.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"

render::CtrlScale9Image::CtrlScale9Image()
{
}

render::CtrlScale9Image::~CtrlScale9Image()
{
}

bool render::CtrlScale9Image::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}
	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->onScale9BodyChange();
	});

	_notify->addListen(NodeNotifyType::GEOMETRY, [this]() {
		this->onScale9BodyChange();
		this->onScale9ImageChange();
	});
	_notify->addListen(NodeNotifyType::TEXTURE, [this]() {
		this->onScale9ImageChange();
	});

	return true;
}

void render::CtrlScale9Image::setMarginLeft(float value)
{
	_scale9Margin.setLeft(sys::NumberType::Fixed, value);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlScale9Image::setMarginRight(float value)
{
	_scale9Margin.setRight(sys::NumberType::Fixed, value);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlScale9Image::setMarginTop(float value)
{
	_scale9Margin.setTop(sys::NumberType::Fixed, value);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlScale9Image::setMarginBottom(float value)
{
	_scale9Margin.setBottom(sys::NumberType::Fixed, value);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlScale9Image::setMargin(float top, float right, float bottom, float left)
{
	_scale9Margin.setLeft(sys::NumberType::Fixed, left);
	_scale9Margin.setRight(sys::NumberType::Fixed, right);
	_scale9Margin.setTop(sys::NumberType::Fixed, top);
	_scale9Margin.setBottom(sys::NumberType::Fixed, bottom);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::CtrlScale9Image::setMargin(const sys::CSSMargin& margin)
{
	_scale9Margin = margin;
	this->notify(NodeNotifyType::GEOMETRY);
}

const sys::CSSMargin& render::CtrlScale9Image::getMargin() const
{
	return _scale9Margin;
}

void render::CtrlScale9Image::onScale9BodyChange()
{
	VertexTool::setTexture2DScale9Vertices(&_scale9Vertex, math::Vector3(), this->getVolume(), this->getAnchorPoint(), _scale9Margin);

	updateScale9ImageMeshData();
}

void render::CtrlScale9Image::onScale9ImageChange()
{
	if (getTexture() != nullptr)
	{
		VertexTool::setTexture2DScale9Coords(&_scale9Vertex, math::Size(getTexture()->getWidth(), getTexture()->getHeight()), _scale9Margin);
		updateScale9ImageMeshData();
	}
}

void render::CtrlScale9Image::updateScale9ImageMeshData()
{
	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[32] = { 0 };
		memcpy(uvs, _scale9Vertex.uvs, sizeof(uvs));

		pMesh->getMeshDetail()->setVertices(16, _scale9Vertex.vertices, 3);
		pMesh->getMeshDetail()->setColors(16, _scale9Vertex.colors, 4);
		pMesh->getMeshDetail()->setUVs(16, uvs, 2);

		if (getTexture() != nullptr)
		{
			pMesh->getMeshDetail()->setIndices(54, _scale9Vertex.indices);
		}
		else
		{
			pMesh->getMeshDetail()->setIndices(0, nullptr);
		}
	}
	this->updateMeshData();
}
