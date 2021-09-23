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

void render::SkyBox::beforeDrawNode()
{
	Model::beforeDrawNode();

	GLState::enable(EnableMode::TEXTURE_CUBE_MAP_SEAMLESS);
	GLState::setDepthFunc(DepthFunction::LEQUAL);
	GLState::disable(EnableMode::CULL_FACE);
}

void render::SkyBox::afterDrawNode()
{
	GLState::setDepthFunc(DepthFunction::LESS);
	GLState::enable(EnableMode::CULL_FACE);
	GLState::disable(EnableMode::TEXTURE_CUBE_MAP_SEAMLESS);

	Model::afterDrawNode();
}

void render::SkyBox::updateDrawNode3DMesh()
{
	float vertices[24 * 3] = { 0 };
	uint32_t indices[36] = { 0 };

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		const auto* pRectVertex = _cubeVertex.getCubMapFaceVertex((CubeFace)i);
		if (!pRectVertex)
		{
			continue;
		}

		memcpy(vertices + i * 4 * 3, pRectVertex->vertices, sizeof(pRectVertex->vertices));

		indices[6 * i + 0] = i * 4 + 0;
		indices[6 * i + 1] = i * 4 + 1;
		indices[6 * i + 2] = i * 4 + 2;

		indices[6 * i + 3] = i * 4 + 0;
		indices[6 * i + 4] = i * 4 + 2;
		indices[6 * i + 5] = i * 4 + 3;
	}

	auto pMesh = getMesh();
	if (pMesh)
	{
		pMesh->setVertices(24, vertices, 3);
		pMesh->setIndices(36, indices, 1);
	}

	this->updateMeshData();
}