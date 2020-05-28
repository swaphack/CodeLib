#include "SkyBox.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/TextureCubeMap.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Mesh/Mesh.h"
#include "Graphic/import.h"
#include "Common/Texture/import.h"

render::SkyBox::SkyBox()
{

}

render::SkyBox::~SkyBox()
{
}

bool render::SkyBox::init()
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
		this->updateBufferData();
	});

	return true;
}

void render::SkyBox::setFaceImage(CubeFace face, const std::string& filepath)
{
	_imagePaths[(int)face] = filepath;

	this->notify(NodeNotifyType::TEXTURE);
}

void render::SkyBox::beforeDrawNode()
{
	GLState::setDepthFunc(DepthFunction::LEQUAL);
	GLState::setCullFace(FaceType::FRONT);
	Model::beforeDrawNode();
}

void render::SkyBox::afterDrawNode()
{
	Model::afterDrawNode();

	GLState::setDepthFunc(DepthFunction::LESS);
	GLState::setCullFace(FaceType::BACK);
}

void render::SkyBox::onImageChanged()
{
	_texCubeMap = G_TEXTURE_CACHE->createTextureCubeMap(6, _imagePaths);
	if (_texCubeMap == nullptr)
	{
		return;
	}

	this->addMaterialTexture(MAT_TEXTURE_NAME, _texCubeMap);
	this->setAllMaterialsTexture(MAT_TEXTURE_NAME);
}

void render::SkyBox::onSpaceChanged()
{
	/*
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	float vertices[24 * 3] = { 0 };
	float uvs[24 * 2] = { 0 };
	uint32_t indices[36] = { 0 };

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		const auto* pRectVertex = _cubePosition.getFaceVertex((CubeFace)i);
		if (!pRectVertex)
		{
			continue;
		}

		memcpy(vertices + i * 4 * 3, pRectVertex->vertices, sizeof(pRectVertex->vertices));
		memcpy(uvs + i * 4 * 2, pRectVertex->uvs, sizeof(pRectVertex->uvs));

		indices[6 * i + 0] = i * 4 + 0;
		indices[6 * i + 1] = i * 4 + 1;
		indices[6 * i + 2] = i * 4 + 2;

		indices[6 * i + 3] = i * 4 + 0;
		indices[6 * i + 4] = i * 4 + 2;
		indices[6 * i + 5] = i * 4 + 3;
	}
	*/

	float vertices[] = {
		// positions          
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f,
		 1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f
	};

	uint32_t indices[36] = { 0 };
	for (int i = 0; i < 36; i++)
	{
		indices[i] = i;
	}

	auto pMesh = getMesh();
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(36, vertices, 3);
		pMesh->getMeshDetail()->setIndices(36, indices, 1);
	}
}

