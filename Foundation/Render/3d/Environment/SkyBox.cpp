#include "SkyBox.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/TextureCubeMap.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Mesh/Mesh.h"
#include "Graphic/import.h"

render::SkyBox::SkyBox()
{

}

render::SkyBox::~SkyBox()
{
	SAFE_RELEASE(_texCubeMap);
}

bool render::SkyBox::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::TEXTURE, [this]() {

		_loadModel = true;
		this->onImageChanged();
	});

	_notify->addListen(NodeNotifyType::SPACE, [this]() {
		this->onSpaceChanged();
	});

	return true;
}

void render::SkyBox::setFaceImage(CubeFace face, const std::string& fullpath)
{
	_imagePaths[(int)face] = fullpath;

	this->notify(NodeNotifyType::TEXTURE);
}

void render::SkyBox::setAllFacesImage(const std::string& fullpath)
{
	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		this->setFaceImage((CubeFace)i, fullpath);
	}
}

void render::SkyBox::onImageChanged()
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

void render::SkyBox::onSpaceChanged()
{
	TextureTool::setTexture3DVertexts(&_cubePosition, math::Vector3(), _volume, _anchor);

	auto pMesh = getMesh();
	pMesh->getMeshDetail()->setVertices(24, _cubePosition.vertices, 3);
	pMesh->getMeshDetail()->setIndices(36, _cubePosition.indices, 1);
}

