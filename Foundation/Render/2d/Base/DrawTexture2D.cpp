#include "DrawTexture2D.h"
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

DrawTexture2D::DrawTexture2D()
	:_bFlipX(false)
	, _bFlipY(false)
{
}

DrawTexture2D::~DrawTexture2D()
{
}

bool DrawTexture2D::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setEnabled(true);
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		updateTexture2DMeshData();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->updateTexture2DMeshData();
	});

	return true;
}

void DrawTexture2D::setTextureWithRect(const std::string& filepath)
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

void render::DrawTexture2D::setTextureWithRect(const Texture* texture)
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

void render::DrawTexture2D::onBlendChange()
{
	FragmentBlend* pBlend = this->getFragOperator()->getHandle<FragmentBlend>();
	if (pBlend)
	{
		pBlend->setBlendFactor(_blendParam.src, _blendParam.dest);

		pBlend->setBlendColor(_blendColor);
	}
}

void DrawTexture2D::updateTexture2DMeshData()
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

		if (getTexture() != nullptr)
		{
			pMesh->getMeshDetail()->setIndices(6, _rectVertex.indices);
		}
		else
		{
			pMesh->getMeshDetail()->setIndices(0, nullptr);
		}
	}
	this->updateMeshData();
}
