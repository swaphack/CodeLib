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

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->onCubeBodyChanged();
	});

	return true;
}

void render::Cube::onCubeBodyChanged()
{
	VertexTool::setTexture3DVertices(&_cubePosition, math::Vector3(), _volume, _anchor);

	float vertices[24 * 3] = { 0 };
	float uvs[24 * 2] = { 0 };
	float colors[24 * 4] = { 1 };
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
		memcpy(colors + i * 4 * 4, pRectVertex->colors, sizeof(pRectVertex->colors));

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
		pMesh->getMeshDetail()->setUVs(24, uvs, 2);
		pMesh->getMeshDetail()->setColors(24, colors, 3);
		pMesh->getMeshDetail()->setIndices(36, indices, 1);
	}

	this->updateMeshData();
}

