#include "CtrlFrame.h"

#include "Common/Texture/Texture.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Tool/Tool.h"
#include "Common/Shader/ShaderProgram.h"
#include "Common/View/import.h"
#include "Common/Buffer/import.h"
#include "Graphic/import.h"
#include "Common/DrawNode/import.h"

#define MAT_TEXTURE_NAEM "MAT_TEXTURE_NAEM"
#define MATERIAL_INDEX 0
#define MESH_INDEX 0

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
{
}

CtrlFrame::~CtrlFrame()
{
}

bool CtrlFrame::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this](){
		onTextureChange();		

		updateBufferData();
	});

	_notify->addListen(NodeNotifyType::TEXTURE, [this](){
		_material->updateMatTexture();

		onTextureChange();
		updateBufferData();
	});

	initBufferObject();

	return true;
}

void CtrlFrame::setTexture(const Texture2D* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_material->addTexture(MAT_TEXTURE_NAEM, texture);

	this->notify(NodeNotifyType::TEXTURE);
}

void CtrlFrame::setTextureWithRect(const Texture2D* texture)
{
	_material->addTexture(MAT_TEXTURE_NAEM, texture);
	this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDepth());

	this->notify(NodeNotifyType::TEXTURE);
}

void CtrlFrame::setTexRect(const math::Rect& rect)
{
	const auto& size = rect.getSize();
	this->setVolume(size.getWidth(), size.getHeight());

	this->notify(NodeNotifyType::TEXTURE);
} 

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(NodeNotifyType::TEXTURE);
}

bool CtrlFrame::isFlipY()
{
	return _bFlipY;
}

void CtrlFrame::onTextureChange()
{
	math::Size size = math::Size(this->getWidth(), this->getHeight());
	math::Rect rect(math::Vector2(), size);
	TextureTool::setTexture2DCoords(&_texRect, size, rect);
	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}

render::Material* render::CtrlFrame::getMaterial()
{
	return _material;
}

render::Mesh* render::CtrlFrame::getMesh()
{
	return _mesh;
}

void render::CtrlFrame::initBufferObject()
{
	sys::ModelDetail* pModelDetail = CREATE_OBJECT(sys::ModelDetail);

	auto pMat = CREATE_OBJECT(sys::MaterialDetail);
	pMat->setAmbientTextureMap(MAT_TEXTURE_NAEM);
	pModelDetail->addMaterial(MATERIAL_INDEX, pMat);

	auto pMesh = CREATE_OBJECT(sys::MeshDetail);
	pMesh->setMaterial(MATERIAL_INDEX);
	pModelDetail->addMesh(MESH_INDEX, pMesh);

	_material->setModelDetail(pModelDetail);
	_mesh->setModelDetail(pModelDetail);

	_mesh->initBufferData();
}

void render::CtrlFrame::updateBufferData()
{
	auto pMesh = _mesh->getMesh(MESH_INDEX);
	if (pMesh)
	{
		pMesh->setVertices(12, _texRect.vertices);
		pMesh->setColors(16, _texRect.colors);
		pMesh->setUVs(8, _texRect.uvs);
		pMesh->setIndices(6, _texRect.indices);
	}
}
