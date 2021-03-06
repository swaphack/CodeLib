#include "CubeMap.h"
#include "Common/Texture/TextureCache.h"
#include "Common/Texture/TextureCubeMap.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Mesh/Mesh.h"
#include "Graphic/import.h"
#include "Common/Texture/import.h"

render::CubeMap::CubeMap()
{

}

render::CubeMap::~CubeMap()
{

}

bool render::CubeMap::init()
{
	if (!Model::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->onImageChanged();
	});

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->onCubeMapBodyChanged();
	});

	return true;
}

void render::CubeMap::setFaceTexture(CubeFace face, const std::string& filepath)
{
	_imagePaths[(int)face] = filepath;

	this->notify(NodeNotifyType::TEXTURE);
}

void render::CubeMap::setLeftTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::LEFT, filepath);
}

void render::CubeMap::setRightTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::RIGHT, filepath);
}

void render::CubeMap::setBottomTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::BOTTOM, filepath);
}

void render::CubeMap::setTopTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::TOP, filepath);
}

void render::CubeMap::setFrontTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::FRONT, filepath);
}

void render::CubeMap::setBackTexture(const std::string& filepath)
{
	this->setFaceTexture(CubeFace::BACK, filepath);
}

void render::CubeMap::onImageChanged()
{
	_texCubeMap = G_TEXTURE_CACHE->createTextureCubeMap(6, _imagePaths);
	if (_texCubeMap == nullptr)
	{
		return;
	}

	this->setTexture(_texCubeMap);
}

void render::CubeMap::onCubeMapBodyChanged()
{
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	float vertices[36 * 3] = { 0 };
	float normals[36 * 3] = { 0 };
	uint32_t indices[36] = { 0 };
	

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		CubeFace face = (CubeFace)i;
		const auto* pRectVertex = _cubePosition.getCubMapFaceVertex(face);
		if (!pRectVertex)
		{
			continue;
		}

		memcpy(vertices + 3 * (i * 6 + 0), pRectVertex->vertices, 3 * sizeof(float));
		memcpy(vertices + 3 * (i * 6 + 1), pRectVertex->vertices + 1 * 3, 3 * sizeof(float));
		memcpy(vertices + 3 * (i * 6 + 2), pRectVertex->vertices + 2 * 3, 3 * sizeof(float));
		memcpy(vertices + 3 * (i * 6 + 3), pRectVertex->vertices, 3 * sizeof(float));
		memcpy(vertices + 3 * (i * 6 + 4), pRectVertex->vertices + 2 * 3, 3 * sizeof(float));
		memcpy(vertices + 3 * (i * 6 + 5), pRectVertex->vertices + 3 * 3, 3 * sizeof(float));


		for (int j = 0; j < 6; j++)
		{
			float normal[3] = { 0 };
			if (face == CubeFace::LEFT) normal[0] = -1;
			else if (face == CubeFace::RIGHT) normal[0] = 1;
			else if (face == CubeFace::TOP) normal[1] = 1;
			else if (face == CubeFace::BOTTOM) normal[1] = 1;
			else if (face == CubeFace::FRONT) normal[2] = 1;
			else if (face == CubeFace::BACK) normal[2] = -1;

			memcpy(normals + 3 * (i * 6 + j), normal, sizeof(normal));

			indices[6 * i + j] = i * 6 + j;
		}
	}
	
	auto pMesh = getMesh();
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(36, vertices, 3);
		pMesh->getMeshDetail()->setNormals(36, normals, 3);
		pMesh->getMeshDetail()->setIndices(36, indices, 1);
	}


	this->updateMeshData();
}

