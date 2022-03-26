#include "RectMap.h"

alg::map::RectMap::RectMap(int width, int height)
{
	this->init2DMap(width, height);
}

alg::map::RectMap::~RectMap()
{

}

const math::Vector3* alg::map::RectMap::getPosition(uint32_t i, uint32_t j) const
{
	assert(i < _width&& j < _height);

	uint32_t nIndex = i * _width + j;

	return getPoint(nIndex);
}

void alg::map::RectMap::init2DMap(int width, int height)
{
	this->removeAllCells();
	this->removeAllRelations();

	_width = width;
	_height = height;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			auto pCell = this->createCell();
			pCell->setPosition(math::Vector2(static_cast<float>(i), static_cast<float>(j)));

			uint32_t nIndex = pCell->getMapObjectID();
			int32_t left = nIndex - 1;
			int32_t right = nIndex + 1;
			int32_t top = nIndex + width;
			int32_t bottom = nIndex - width;

			std::vector<uint32_t> relation;

			if (j > 0) relation.push_back(left);
			if (j < width - 1) relation.push_back(right);
			if (i > 0) relation.push_back(bottom);
			if (i < height - 1) relation.push_back(top);

			this->addRayRelation(nIndex, relation);
		}
	}
}
