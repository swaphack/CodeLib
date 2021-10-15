#include "DrawScale9Texture2D.h"
#include "Common/DrawNode/FragmentOperator.h"
#include "Common/Fragment/import.h"
#include "Common/Texture/Texture2D.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"
#include "Common/Texture/TextureCache.h"

using namespace render;

DrawScale9Texture2D::DrawScale9Texture2D()
	:_bFlipX(false)
	, _bFlipY(false)
{
	_texFrame = CREATE_OBJECT(TexFrame);
	_texFrame->retain();
}

DrawScale9Texture2D::~DrawScale9Texture2D()
{
	SAFE_RELEASE(_texFrame);
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
		//this->onScale9ImageChange();
		updateScale9ImageMeshData();
	});


	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->onScale9BodyChange();
		this->onScale9ImageChange();
	});

	return true;
}

void DrawScale9Texture2D::onScale9BodyChange()
{
	VertexTool::setTexture2DScale9Vertices(&_scale9Vertex, math::Vector3(), this->getVolume(), this->getAnchorPoint(), _scale9Margin);
	updateScale9ImageMeshData();
}

void DrawScale9Texture2D::onScale9ImageChange()
{
	VertexTool::setTexture2DScale9Coords(&_scale9Vertex, _texFrame->getRect(), _texFrame->isRotated(), _texFrame->getFrameSize(), _scale9Margin);

	updateScale9ImageMeshData();
}

void render::DrawScale9Texture2D::loadImage(const std::string& mixFilePath)
{
	auto pTexFrame = G_TEXTURE_CACHE->getTexFrame(mixFilePath);
	if (pTexFrame != nullptr)
	{
		this->setTexFrame(pTexFrame);
		return;
	}
	auto pTexture = G_TEXTURE_CACHE->getTexture2D(mixFilePath);
	if (pTexture)
	{
		this->loadTexture(pTexture);
	}
}

void DrawScale9Texture2D::loadTexture(const std::string& filepath)
{
	this->setTexture(filepath);
	auto pTexture = this->getTexture();
	_texFrame->loadTexture(pTexture);
	this->notify(NodeNotifyType::TEXTURE);
}

void render::DrawScale9Texture2D::loadTexture(const Texture* texture)
{
	this->setTexture(texture);
	_texFrame->loadTexture(texture);
	this->notify(NodeNotifyType::TEXTURE);
}

void render::DrawScale9Texture2D::loadTexture(const Texture* texture, const sys::TextureChip& chip)
{
	math::Size size;
	if (texture)
	{
		size.set(texture->getWidth(), texture->getHeight());
	}
	this->setTexture(texture);
	_texFrame->setTexture(texture);
	_texFrame->setName(chip.name);
	this->setUV(math::Rect(chip.x, chip.y, chip.width, chip.height), size, chip.rotate);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::DrawScale9Texture2D::loadTextureChip(const std::string& chipname)
{
	auto texFrame = G_TEXTURE_CACHE->getTexFrame(chipname);
	if (texFrame == nullptr) return;
	setTexFrame(texFrame);
}

void render::DrawScale9Texture2D::setNativeTextureSize()
{
	this->setVolume(_texFrame->getFrameSize());
}

void render::DrawScale9Texture2D::setUV(const math::Rect& rect, const math::Size& size, bool rotate)
{
	if (size.getWidth() == 0 || size.getHeight() == 0)
		return;

	math::Rect temp;
	temp.setOrigin(rect.getMinX() / size.getWidth(), rect.getMinY() / size.getHeight());
	temp.setSize(rect.getWidth() / size.getWidth(), rect.getHeight() / size.getHeight());

	_texFrame->setRect(temp);
	_texFrame->setRotate(rotate);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::DrawScale9Texture2D::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr || texFrame->getTexture() == nullptr) return;
	auto pTexture = texFrame->getTexture();
	this->setTexture(pTexture);
	auto pTexFrame = (TexFrame*)texFrame;
	SAFE_RETAIN(pTexFrame);
	SAFE_RELEASE(_texFrame);
	_texFrame = pTexFrame;
	this->notify(NodeNotifyType::GEOMETRY);
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

		render::VertexTool::setTexture2DScale9Flip(&uvs, _bFlipX, _bFlipY);

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
