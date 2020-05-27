#include "Cube.h"
#include "Common/Texture/import.h"
#include "Common/Tool/import.h"
#include "Common/Mesh/Mesh.h"

render::Cube::Cube()
{

}

render::Cube::~Cube()
{

}

bool render::Cube::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::TEXTURE, [this]() {
		this->onImageChanged();
	});

	_notify->addListen(NodeNotifyType::SPACE, [this]() {
		this->onSpaceChanged();
	});

	return true;
}

void render::Cube::setFaceImage(CubeFace face, const std::string& filepath)
{
	_imagePaths[(int)face] = filepath;

	this->notify(NodeNotifyType::TEXTURE);
}

void render::Cube::setAllFacesImage(const std::string& filepath)
{
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		this->setFaceImage((CubeFace)i, filepath);
	}
}

void render::Cube::onImageChanged()
{
	_texCubeMap = G_TEXTURE_CACHE->createTextureCubeMap(6, _imagePaths);
	if (_texCubeMap == nullptr)
	{
		return;
	}

	SAFE_RETAIN(_texCubeMap);

	this->addMaterialTexture(MAT_TEXTURE_NAME, _texCubeMap);

	this->updateBufferData();
}

void render::Cube::onSpaceChanged()
{
	TextureTool::setTexture3DVertexts(&_cubePosition, math::Vector3(), _volume, _anchor);

	auto pMesh = getMesh();
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(24, _cubePosition.vertices, 3);
		pMesh->getMeshDetail()->setIndices(36, _cubePosition.indices, 1);
		pMesh->getMeshDetail()->setNormals(24, _cubePosition.normals, 3);
	}
}

