#include "CtrlFrame.h"

#include "Common/Texture/Texture2D.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Tool/Tool.h"
#include "Common/View/import.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"

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

	addMaterialTexture(MAT_TEXTURE_NAME, texture);
	setTextureName(MAT_TEXTURE_NAME);

	this->notify(NodeNotifyType::TEXTURE);
}

void CtrlFrame::setTextureWithRect(const Texture2D* texture)
{
	addMaterialTexture(MAT_TEXTURE_NAME, texture);
	setTextureName(MAT_TEXTURE_NAME);

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
	VertexTool::setTexture2DCoords(&_vertexes, size, rect);
	VertexTool::setTexture2DVertices(&_vertexes, math::Vector3(), _volume, _anchor);

	auto pMesh = getMesh(DRAW_MESH_INDEX);
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _vertexes.uvs, sizeof(uvs));
		render::VertexTool::setTexture2DFlip(uvs, _bFlipX, _bFlipY);
		pMesh->getMeshDetail()->setVertices(4, _vertexes.vertices, 3);
		pMesh->getMeshDetail()->setColors(4, _vertexes.colors, 4);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, _vertexes.indices);
	}
}
