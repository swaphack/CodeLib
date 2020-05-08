#include "CubeModel.h"
#include "Resource/Detail/ModelDetail.h"
#include "Common/Texture/Texture.h"
#include "Resource/Detail/MaterialDetail.h"
#include "Resource/Detail/MeshDetail.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Node/import.h"

using namespace render;

CubeModel::CubeModel()
{
}

CubeModel::~CubeModel()
{
}

bool CubeModel::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		this->onCubeChange();
	});

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pMat = CREATE_OBJECT(MaterialDetail);
		_material->addMaterial(i, pMat);

		auto pMesh = CREATE_OBJECT(MeshDetail);
		_mesh->addMesh(i, pMesh);

		pMesh->setMaterial(i);

		pMesh->setUVs(8, _faces[i].uvs, 2);
		pMesh->setIndices(6, _faces[i].indices);
		pMesh->setColors(16, _faces[i].colors);
	}
	this->notify(ENP_MODEL_FRAME);
	return true;
}

void CubeModel::onCubeChange()
{
	TextureTool::setTexture3DVertexts(&_cubePosition, math::Vector3(), _volume, _anchor);
	
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pMesh = _mesh->getMesh(i);
		if (!pMesh)
		{
			return;
		}

		uint32_t indices1[6] = { 0 };
		memcpy(indices1, _cubePosition.indices + i * CUBE_FACE_COUNT, 6 * sizeof(uint32_t));

		uint32_t indices2[4] = { 0 };
		indices2[0] = indices1[0];
		indices2[1] = indices1[1];
		indices2[2] = indices1[2];
		indices2[3] = indices1[5];

		float vertices[12] = { 0 };
		for (int j = 0; j < 4; j++)
		{
			memcpy(vertices + j * 3, _cubePosition.vertices + indices2[j] * 3, 3 * sizeof(float));
		}

		pMesh->setVertices(12, vertices);
	}

	this->notify(ENP_MODEL_FRAME);
}

void render::CubeModel::addTexture(const std::string& name, Texture2D* texture)
{
	_material->addTexture(name, texture);
}

void render::CubeModel::setAllFacesTexture(const std::string& name)
{
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pMat = _material->getMaterial(i);
		if (pMat)
		{
			pMat->setAmbientTextureMap(name);
		}
	}
}

void render::CubeModel::setFaceTexture(ModelFace face, const std::string& name)
{
	auto pMat = _material->getMaterial((int)face);
	if (pMat)
	{
		pMat->setAmbientTextureMap(name);
	}
}

