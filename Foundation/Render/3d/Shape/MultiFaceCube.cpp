#include "MultiFaceCube.h"
#include "Common/Texture/Texture.h"
#include "Common/Tool/VertexTool.h"
#include "Common/DrawNode/import.h"
#include "Common/Mesh/import.h"
#include "Common/Material/import.h"
#include "Common/DrawNode/DrawTextureCache.h"

using namespace render;

MultiFaceCube::MultiFaceCube()
{
}

MultiFaceCube::~MultiFaceCube()
{
}

bool MultiFaceCube::init()
{
	if (!MultiMeshModel::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this](){
		onMultiFaceCubeBodyChanged();

		this->updateBufferData();
	});

	return true;
}

void render::MultiFaceCube::setFaceTexture(CubeFace face, const std::string& filepath)
{
	int i = (int)face;
	std::string name = CubeFaceString[i];

	_textureCache->addTexture(name, filepath);
}

void render::MultiFaceCube::setLeftTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::LEFT, filepath);
}

void render::MultiFaceCube::setRightTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::RIGHT, filepath);
}

void render::MultiFaceCube::setBottomTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::BOTTOM, filepath);
}

void render::MultiFaceCube::setTopTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::TOP, filepath);
}

void render::MultiFaceCube::setFrontTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::FRONT, filepath);
}

void render::MultiFaceCube::setBackTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::BACK, filepath);
}

void render::MultiFaceCube::setAllFacesTexture(const std::string& filepath)
{
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		setFaceTexture((CubeFace)i, filepath);
	}
}

void render::MultiFaceCube::initBufferObject()
{
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		std::string name = CubeFaceString[i];

		auto pMat = CREATE_OBJECT(sys::MaterialDetail);
		_materiales->addMaterial(name, pMat);

		auto pMesh = CREATE_OBJECT(sys::MeshDetail);
		_meshes->addMesh(name, pMesh);

		pMesh->setMaterial(name);

		CubeFace face = (CubeFace)i;

		pMesh->setUVs(4, _cubePosition.getFaceVertex((CubeFace)i)->uvs, 2);
		pMesh->setIndices(6, _cubePosition.getFaceVertex((CubeFace)i)->indices, 1);
		pMesh->setColors(4, _cubePosition.getFaceVertex((CubeFace)i)->colors, 4);
	}
}

void render::MultiFaceCube::onMultiFaceCubeBodyChanged()
{
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		std::string name = CubeFaceString[i];
		auto pMesh = _meshes->getMesh(name);
		if (!pMesh)
		{
			return;
		}
		CubeFace face = (CubeFace)i;
		pMesh->getMeshDetail()->setVertices(4, _cubePosition.getFaceVertex(face)->vertices, 3);

		pMesh->initDetailNormalData();
	}
}

