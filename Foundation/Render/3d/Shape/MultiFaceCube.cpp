#include "MultiFaceCube.h"
#include "Common/Texture/Texture.h"
#include "Common/Tool/TextureTool.h"
#include "Common/DrawNode/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"

using namespace render;

MultiFaceCube::MultiFaceCube()
{
}

MultiFaceCube::~MultiFaceCube()
{
}

bool MultiFaceCube::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this](){
		onCubeChanged();

		this->updateBufferData();
	});
	_notify->addListen(NodeNotifyType::MODEL, [this]() {
		this->updateBufferData();
	});

	return true;
}

void render::MultiFaceCube::setFaceTextureName(CubeFace face, const std::string& name)
{
	setMaterialTexture((int)face, name);
}

void render::MultiFaceCube::initBufferObject()
{
	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pMat = CREATE_OBJECT(sys::MaterialDetail);
		_materiales->addMaterial(i, pMat);

		auto pMesh = CREATE_OBJECT(sys::MeshDetail);
		_meshes->addMesh(i, pMesh);

		pMesh->setMaterial(i);

		pMesh->setUVs(4, _faces[i].uvs, 2);
		pMesh->setIndices(6, _faces[i].indices);
		pMesh->setColors(4, _faces[i].colors, 4);
	}
}

void render::MultiFaceCube::onCubeChanged()
{
	TextureTool::setTexture3DVertexts(&_cubePosition, math::Vector3(), _volume, _anchor);

	for (int i = 0; i < CUBE_FACE_COUNT; i++)
	{
		auto pMesh = _meshes->getMesh(i);
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

		float* ptr = nullptr;
		if (pMesh->getMeshDetail()->getVertices().getSize() == 0)
		{
			ptr = (float*)pMesh->getMeshDetail()->createVertices(4, sizeof(float), 3);
		}
		else
		{
			ptr = (float*)pMesh->getMeshDetail()->getVertices().getPtr();
		}

		for (int j = 0; j < 4; j++)
		{
			memcpy(ptr + j * 3, _cubePosition.vertices + indices2[j] * 3, 3 * sizeof(float));
		}
	}
}

