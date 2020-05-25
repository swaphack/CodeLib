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

	return true;
}

void CtrlFrame::setTexture(const Texture2D* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_materiales->addTexture(MAT_TEXTURE_NAEM, texture);
	getMaterial(DRAW_MATERIAL_INDEX)->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAEM);

	this->notify(NodeNotifyType::TEXTURE);
}

void CtrlFrame::setTextureWithRect(const Texture2D* texture)
{
	_materiales->addTexture(MAT_TEXTURE_NAEM, texture);
	getMaterial(DRAW_MATERIAL_INDEX)->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAEM);

	this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDepth());

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
	TextureTool::setTexture2DCoords(&_vertexes, size, rect);
	TextureTool::setTexture2DVertexts(&_vertexes, math::Vector3(), _volume, _anchor);
}

void render::CtrlFrame::updateBufferData()
{
	auto pMesh = _meshes->getMesh(DRAW_MESH_INDEX);
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _vertexes.uvs, sizeof(uvs));
		render::TextureTool::setTexture2DFlip(uvs, _bFlipX, _bFlipY);
		pMesh->getMeshDetail()->setVertices(12, _vertexes.vertices);
		pMesh->getMeshDetail()->setColors(16, _vertexes.colors);
		pMesh->getMeshDetail()->setUVs(8, uvs);
		pMesh->getMeshDetail()->setIndices(6, _vertexes.indices);
		pMesh->updateBufferData();
	}
}
