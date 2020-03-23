#include "Face.h"
#include "system.h"
#include "Material.h"

using namespace render;

Face::Face()
{

}

Face::~Face()
{
}

void Face::setIndices(int size, uint16_t* indices)
{
	_indices.init(size, indices);
}

void Face::setMaterial(int mat)
{
	_material = mat;
}

const T_Indice& Face::getIndices()
{
	return _indices;
}

int Face::getMaterial()
{
	return _material;
}
