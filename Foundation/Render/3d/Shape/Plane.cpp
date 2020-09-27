#include "Plane.h"
#include "Common/Tool/import.h"
#include "Common/Mesh/import.h"

render::Plane::Plane()
{

}

render::Plane::~Plane()
{

}

bool render::Plane::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->onPlaneBodyChanged();
		});

	return true;
}

void render::Plane::onPlaneBodyChanged()
{
	math::Size size = math::Size(this->getWidth(), this->getHeight());
	math::Rect rect(math::Vector2(), size);
	VertexTool::setTexture2DCoords(&_rectVertex, size, rect);
	VertexTool::setTexture2DVertices(&_rectVertex, math::Vector3(), _volume, _anchor);

	auto pMesh = getMesh();
	if (pMesh)
	{
		float uvs[8] = { 0 };
		memcpy(uvs, _rectVertex.uvs, sizeof(uvs));

		pMesh->getMeshDetail()->setVertices(4, _rectVertex.vertices, 3);
		pMesh->getMeshDetail()->setColors(4, _rectVertex.colors, 4);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, _rectVertex.indices);
	}

	this->updateMeshData();
}

