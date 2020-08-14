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
	//GLState::setCullFace(FaceType::FRONT);
}

void render::SkyBox::afterDrawNode()
{
	GLState::setDepthFunc(DepthFunction::LESS);
	//GLState::setCullFace(FaceType::BACK);

	GLState::disable(EnableMode::TEXTURE_CUBE_MAP_SEAMLESS);

	Model::afterDrawNode();
}

void render::SkyBox::onCubeMapBodyChanged()
{
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	float vertices[24 * 3] = { 0 };
	uint32_t indices[36] = { 0 };

	for (int i = 0; i < (int)CubeFace::MAX; i++)
	{
		const auto* pRectVertex = _cubePosition.getCubMapFaceVertex((CubeFace)i);
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
		pMesh->getMeshDetail()->setVertices(24, vertices, 3);
		pMesh->getMeshDetail()->setIndices(36, indices, 1);
	}

	this->updateMeshData();
}