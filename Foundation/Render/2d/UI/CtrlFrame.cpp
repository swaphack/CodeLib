#include "CtrlFrame.h"

#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"

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

	_materiales->addTexture(MAT_TEXTURE_NAEM, texture);

	this->notify(NodeNotifyType::TEXTURE);
}

void CtrlFrame::setTextureWithRect(const Texture2D* texture)
{
	_materiales->addTexture(MAT_TEXTURE_NAEM, texture);
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
}

render::Materials* render::CtrlFrame::getMaterials()
{
	return _materiales;
}

render::Meshes* render::CtrlFrame::getMeshes()
{
	return _meshes;
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

	_materiales->setModelDetail(pModelDetail);
	_meshes->setModelDetail(pModelDetail);
}

void render::CtrlFrame::updateBufferData()
{
	auto pMesh = _meshes->getMesh(MESH_INDEX);
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _texRect.uvs, sizeof(uvs));
		render::TextureTool::setTexture2DFlip(uvs, _bFlipX, _bFlipY);
		pMesh->getMeshDetail()->setVertices(12, _texRect.vertices);
		pMesh->getMeshDetail()->setColors(16, _texRect.colors);
		pMesh->getMeshDetail()->setUVs(8, uvs);
		pMesh->getMeshDetail()->setIndices(6, _texRect.indices);
		pMesh->updateBufferData();
	}
}
