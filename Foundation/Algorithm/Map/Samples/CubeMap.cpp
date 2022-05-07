#include "CubeMap.h"

alg::map::CubeMap::CubeMap()
{
	this->init3DMap(1, 1, 1);
}

alg::map::CubeMap::~CubeMap()
{

}

uint32_t alg::map::CubeMap::getWidth() const
{ 
	return _width;
}

uint32_t alg::map::CubeMap::getHeight() const 
{ 
	return _height; 
}

uint32_t alg::map::CubeMap::getDepth() const 
{ 
	return _depth;
}
const math::Vector3* alg::map::CubeMap::getPosition(uint32_t i, uint32_t j, uint32_t k) const
{
	assert(i < _width&& j < _height);

	uint32_t nIndex = k * _height * _width + i * _width + j;

	return getPoint(nIndex);
}

void alg::map::CubeMap::init3DMap(uint32_t width, uint32_t height, uint32_t depth)
{
	_width = width;
	_height = height;
	_depth = depth;

	for (int k = 0; k < _depth; k++)
	{
		for (int i = 0; i < _height; i++)
		{
			for (int j = 0; j < _width; j++)
			{
				auto pCell = this->createCell();
				pCell->setPosition(math::Vector3(i, j, k));

				uint32_t nIndex = pCell->getMapObjectID();
				int32_t left = nIndex - 1;
				int32_t right = nIndex + 1;
				int32_t top = nIndex + _depth * _width;
				int32_t bottom = nIndex - _depth * _width;
				int32_t front = nIndex + _height * _width;
				int32_t back = nIndex - _height * _width;

				std::vector<uint32_t> relation;

				if (j > 0) relation.push_back(left);
				if (j < _width - 1) relation.push_back(right);
				if (i > 0) relation.push_back(bottom);
				if (i < _height - 1) relation.push_back(top);
				if (k > 0) relation.push_back(back);
				if (k < _height - 1) relation.push_back(front);

				this->addRayRelation(nIndex, relation);
			}
		}
	}
}
