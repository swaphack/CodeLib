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

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		updateCtrlFrameMeshData();
	});

	_notify->addListen(NodeNotifyType::TEXTURE, [this](){
		updateCtrlFrameMeshData();
	});

	return true;
}

void CtrlFrame::setTextureWithRect(const std::string& filepath)
{
	this->setTexture(filepath);

	auto pTexture = this->getTexture();
	if (pTexture)
	{
		this->setVolume(pTexture->getWidth(), pTexture->getHeight(), pTexture->getDepth());
	}

	this->notify(NodeNotifyType::TEXTURE);
}

void render::CtrlFrame::setTextureWithRect(const Texture* texture)
{
	this->setTexture(texture);

	if (texture)
	{
		this->setVolume(texture->getWidth(), texture->getHeight(), texture->getDepth());
	}

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

void CtrlFrame::updateCtrlFrameMeshData()
{
	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _rectVertex.uvs, sizeof(uvs));
		render::VertexTool::setTexture2DFlip(uvs, _bFlipX, _bFlipY);

		pMesh->getMeshDetail()->setVertices(4, _rectVertex.vertices, 3);
		pMesh->getMeshDetail()->setColors(4, _rectVertex.colors, 4);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, _rectVertex.indices);
	}

	this->updateMeshData();
}
