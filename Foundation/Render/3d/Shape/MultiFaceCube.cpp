#include "MultiFaceCube.h"
#include "Common/Texture/Texture.h"
#include "Common/Tool/VertexTool.h"
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
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		auto pMat = CREATE_OBJECT(sys::MaterialDetail);
		_materiales->addMaterial(i, pMat);

		auto pMesh = CREATE_OBJECT(sys::MeshDetail);
		_meshes->addMesh(i, pMesh);

		pMesh->setMaterial(i);

		CubeFace face = (CubeFace)i;

		pMesh->setUVs(4, _cubePosition.getFaceVertex((CubeFace)i)->uvs, 2);
		pMesh->setIndices(6, _cubePosition.getFaceVertex((CubeFace)i)->indices, 1);
		pMesh->setColors(4, _cubePosition.getFaceVertex((CubeFace)i)->colors, 4);
	}
}

void render::MultiFaceCube::onCubeChanged()
{
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		auto pMesh = _meshes->getMesh(i);
		if (!pMesh)
		{
			return;
		}
		CubeFace face = (CubeFace)i;
		pMesh->getMeshDetail()->setVertices(4, _cubePosition.getFaceVertex(face)->vertices, 3);
	}
}

