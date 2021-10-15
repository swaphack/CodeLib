#include "DrawTexture2D.h"
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

DrawTexture2D::DrawTexture2D()
	:_bFlipX(false)
	, _bFlipY(false)
{
	_texFrame = CREATE_OBJECT(TexFrame);
	_texFrame->retain();
}

DrawTexture2D::~DrawTexture2D()
{
	SAFE_RELEASE(_texFrame);
}

bool DrawTexture2D::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->updateTexture2DMeshData();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->updateTexture2DMeshData();
	});

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->updateUVWithTexture();
	});

	return true;
}

void DrawTexture2D::loadImage(const std::string& mixFilePath)
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

void DrawTexture2D::loadTexture(const std::string& filepath)
{
	this->setTexture(filepath);

	auto pTexture = this->getTexture();
	_texFrame->loadTexture(pTexture);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::DrawTexture2D::loadTexture(const Texture* texture)
{
	this->setTexture(texture);
	_texFrame->loadTexture(texture);
	this->notify(NodeNotifyType::GEOMETRY);
}

void render::DrawTexture2D::loadTexture(const Texture* texture, const sys::TextureChip& chip)
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

void render::DrawTexture2D::loadTextureChip(const std::string& chipname)
{
	auto texFrame = G_TEXTURE_CACHE->getTexFrame(chipname);
	if (texFrame == nullptr) return;
	setTexFrame(texFrame);
}

void render::DrawTexture2D::setNativeTextureSize()
{
	this->setVolume(_texFrame->getFrameSize());
}

void render::DrawTexture2D::setUV(const math::Rect& rect, const math::Size& size, bool rotate)
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

void render::DrawTexture2D::setTexFrame(const TexFrame* texFrame)
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

void DrawTexture2D::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool DrawTexture2D::isFlipX()
{
	return _bFlipX;
}

void DrawTexture2D::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool DrawTexture2D::isFlipY()
{
	return _bFlipY;
}

void render::DrawTexture2D::updateUVWithTexture()
{
	VertexTool::setTexture2DCoords(&_rectVertex, _texFrame->getRect(), _texFrame->isRotated());
	this->updateTexture2DMeshData();
}

void DrawTexture2D::updateTexture2DMeshData()
{
	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _rectVertex.uvs, sizeof(uvs));

		render::VertexTool::setTexture2DFlip(&uvs, _bFlipX, _bFlipY);

		pMesh->setVertices(4, _rectVertex.vertices, 3);
		pMesh->setColors(4, _rectVertex.colors, 4);
		pMesh->setUVs(4, uvs, 2);

		if (getTexture() != nullptr)
		{
			pMesh->setIndices(6, _rectVertex.indices);
		}
		else
		{
			pMesh->setIndices(0, nullptr);
		}
	}
	this->updateMeshData();
}
