#include "Grid.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Mesh/Mesh.h"
#include "Common/Scene/Cameras.h"

render::Grid::Grid()
{

}

render::Grid::~Grid()
{

}

bool render::Grid::init()
{
	if (!DrawNode3D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::GEOMETRY, [this]() {
		this->onGridChange();
	});

	this->getMesh()->setDrawMode(DrawMode::LINES);

	return true;
}

void render::Grid::onGridChange()
{
	//GLState::setLineWidth(20);
	int widthCount = getWidth() / getGridWidth();
	int heightCount = getDepth() / getGridWidth();

	if (widthCount % 2 == 0) widthCount++;
	if (heightCount % 2 == 0) heightCount++;

	int halfWidth = widthCount / 2;
	int halfHeight = heightCount / 2;

	float* pVertice = (float*)this->getMesh()->getMeshDetail()->createVertices(2 * (widthCount + heightCount), 3);
	uint32_t* pIndice = (uint32_t*)this->getMesh()->getMeshDetail()->createIndices(2 * (widthCount + heightCount), 1);

	for (int i = 0; i < widthCount; i++)
	{
		float posX = (i - halfWidth) * getGridWidth();
		pVertice[i * 6 + 0] = posX;
		pVertice[i * 6 + 1] = 0;
		pVertice[i * 6 + 2] = -getDepth() * getAnchorPointZ();
					 
		pVertice[i * 6 + 3] = posX;
		pVertice[i * 6 + 4] = 0;
		pVertice[i * 6 + 5] = getDepth() * (1 - getAnchorPointZ());

		pIndice[i * 2] = i * 2;
		pIndice[i * 2 + 1] = i * 2 + 1;
	}

	for (int i = 0; i < heightCount; i++)
	{
		float posZ = (i - halfHeight) * getGridWidth();

		pVertice[6 * widthCount + i * 6 + 0] = - getWidth() * getAnchorPointX();
		pVertice[6 * widthCount + i * 6 + 1] = 0;
		pVertice[6 * widthCount + i * 6 + 2] = posZ;

		pVertice[6 * widthCount + i * 6 + 3] = getWidth() * (1 - getAnchorPointX());
		pVertice[6 * widthCount + i * 6 + 4] = 0;
		pVertice[6 * widthCount + i * 6 + 5] = posZ;

		pIndice[2 * widthCount + i * 2] = 2 * widthCount + i * 2;
		pIndice[2 * widthCount + i * 2 + 1] = 2 * widthCount + i * 2 + 1;
	}
	this->updateMeshData();
}

void render::Grid::setGridWidth(int width)
{
	_gridWidth = width;

	this->notify(NodeNotifyType::GEOMETRY);
}

int render::Grid::getGridWidth() const
{
	return _gridWidth;
}

