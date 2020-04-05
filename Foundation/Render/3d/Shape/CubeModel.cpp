#include "CubeModel.h"
#include "Resource/Detail/ModelDetail.h"
#include "Common/Texture/Texture.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Resource/Detail/FaceDetail.h"

#include "Common/Tool/TextureTool.h"

using namespace render;

CubeModel::CubeModel()
{

}

CubeModel::~CubeModel()
{
	SAFE_RELEASE(_texture);
}

bool CubeModel::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		onCubeChange();
	});

	_notify->addListen(ENP_MODEL_FRAME, [this](){
		onCubeChange();
	});

	_modelDetail = new ModelDetail();

	auto pMesh = CREATE_OBJECT(MeshDetail);
	auto pMat = CREATE_OBJECT(MaterialDetail);
	_modelDetail->addMesh(0, pMesh);
	_modelDetail->addMaterial(0, pMat);

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pFace = CREATE_OBJECT(FaceDetail);
		pFace->setMaterial(0);
		pMesh->addFace(i, pFace);
	}
	return true;
}

void CubeModel::onCubeChange()
{
	auto pMesh = _modelDetail->getMesh(0);
	if (!pMesh)
	{
		return;
	}

	TextureTool::setTexture3DVertexts(&_texCube, _position, _volume, _anchor);
	
	pMesh->setVertices(24, _texCube.vertices);
	pMesh->setUVs(16, _texCube.uvs, 2);
	pMesh->setNormals(24, _texCube.normals);
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pFace = pMesh->getFace(i);
		if (pFace)
		{
			pFace->setIndices(6, _texCube.indices + i * CUBE_FACE_COUNT);
		}
	}
}

void CubeModel::setTexture(const std::string& name, Texture* texture)
{
	SAFE_RELEASE(_texture);
	SAFE_RETAIN(texture);
	_texture = texture;

	_modelDetail->addTexture(name, texture->getTextureID());

	auto pMat = _modelDetail->getMaterial(0);
	if (pMat)
	{
		pMat->setTexture1(name);
	}
}

