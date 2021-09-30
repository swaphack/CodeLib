#include "DrawScale9Texture2D.h"
#include "Common/DrawNode/FragmentOperator.h"
#include "Common/Fragment/import.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"

using namespace render;

DrawScale9Texture2D::DrawScale9Texture2D()
	:_bFlipX(false)
	, _bFlipY(false)
{
}

DrawScale9Texture2D::~DrawScale9Texture2D()
{
}

bool DrawScale9Texture2D::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		onScale9BodyChange();
		updateScale9ImageMeshData();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->onScale9ImageChange();
		updateScale9ImageMeshData();
	});


	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->onScale9BodyChange();
		this->onScale9ImageChange();
		updateScale9ImageMeshData();
	});

	return true;
}

void DrawScale9Texture2D::onScale9BodyChange()
{
	VertexTool::setTexture2DScale9Vertices(&_scale9Vertex, math::Vector3(), this->getVolume(), this->getAnchorPoint(), _scale9Margin);
}

void DrawScale9Texture2D::onScale9ImageChange()
{
	if (getTexture() != nullptr)
	{
		VertexTool::setTexture2DScale9Coords(&_scale9Vertex, math::Size(getTexture()->getWidth(), getTexture()->getHeight()), _scale9Margin);
	}
}

void DrawScale9Texture2D::setTextureWithRect(const std::string& filepath)
{
	this->setTexture(filepath);

	auto pTexture = this->getTexture();
	if (pTexture)
	{
		this->setVolume(pTexture->getWidth(), pTexture->getHeight(), pTexture->getDepth());
	}
	else
	{
		this->setVolume(0, 0, 0);
	}

	this->notify(NodeNotifyType::TEXTURE);
}

void render::DrawScale9Texture2D::setTextureWithRect(const Texture* texture)
{
	this->setTexture(texture);

	if (texture)
	{
		this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDepth());
	}
	else
	{
		this->setVolume(0, 0, 0);
	}

	this->notify(NodeNotifyType::TEXTURE);
}

void render::DrawScale9Texture2D::setUV(const math::Rect& rect, const math::Size& size)
{
	if (size.getWidth() == 0 || size.getHeight() == 0)
		return;

	float x0 = rect.getMinX();
	float x1 = rect.getMinX() + _scale9Margin.getLeft().getRealValue(size.getWidth());
	float x2 = rect.getMaxX() - _scale9Margin.getRight().getRealValue(size.getWidth());
	float x3 = rect.getMaxX();

	x0 /= size.getWidth(); x1 /= size.getWidth(); x2 /= size.getWidth(); x3 /= size.getWidth();

	float y0 = rect.getMinY();
	float y1 = rect.getMinY() + _scale9Margin.getBottom().getRealValue(size.getHeight());
	float y2 = rect.getMaxY() - _scale9Margin.getTop().getRealValue(size.getHeight());
	float y3 = rect.getMaxY();

	y0 /= size.getHeight(); y1 /= size.getHeight(); y2 /= size.getHeight(); y3 /= size.getHeight();

	_scale9Vertex.setLayerUVs0(math::Vector2(x0, y0), math::Vector2(x1, y0), math::Vector2(x2, y0), math::Vector2(x3, y0));
	_scale9Vertex.setLayerUVs1(math::Vector2(x0, y1), math::Vector2(x1, y1), math::Vector2(x2, y1), math::Vector2(x3, y1));
	_scale9Vertex.setLayerUVs2(math::Vector2(x0, y2), math::Vector2(x1, y2), math::Vector2(x2, y2), math::Vector2(x3, y2));
	_scale9Vertex.setLayerUVs3(math::Vector2(x0, y3), math::Vector2(x1, y3), math::Vector2(x2, y3), math::Vector2(x3, y3));
}

void DrawScale9Texture2D::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool DrawScale9Texture2D::isFlipX()
{
	return _bFlipX;
}

void DrawScale9Texture2D::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool DrawScale9Texture2D::isFlipY()
{
	return _bFlipY;
}

void DrawScale9Texture2D::setMargin(float top, float right, float bottom, float left)
{
	_scale9Margin.setLeft(sys::NumberType::Fixed, left);
	_scale9Margin.setRight(sys::NumberType::Fixed, right);
	_scale9Margin.setTop(sys::NumberType::Fixed, top);
	_scale9Margin.setBottom(sys::NumberType::Fixed, bottom);
	this->notify(NodeNotifyType::GEOMETRY);
}

void DrawScale9Texture2D::setMargin(const sys::CSSMargin& margin)
{
	_scale9Margin = margin;
	this->notify(NodeNotifyType::GEOMETRY);
}

const sys::CSSMargin& DrawScale9Texture2D::getMargin() const
{
	return _scale9Margin;
}

void DrawScale9Texture2D::updateScale9ImageMeshData()
{
	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[32] = { 0 };
		memcpy(uvs, _scale9Vertex.uvs, sizeof(uvs));

		pMesh->setVertices(16, _scale9Vertex.vertices, 3);
		pMesh->setColors(16, _scale9Vertex.colors, 4);
		pMesh->setUVs(16, uvs, 2);

		if (getTexture() != nullptr)
		{
			pMesh->setIndices(54, _scale9Vertex.indices);
		}
		else
		{
			pMesh->setIndices(0, nullptr);
		}
	}
	this->updateMeshData();
}
