#include "FaceDetail.h"
#include "system.h"
#include "MaterialDetail.h"

using namespace render;

FaceDetail::FaceDetail()
{

}

FaceDetail::~FaceDetail()
{
}

void FaceDetail::setIndices(int size, uint16_t* indices)
{
	_indices.init(size, indices);
}

void FaceDetail::setMaterial(int mat)
{
	_material = mat;
}

const T_Indice& FaceDetail::getIndices()
{
	return _indices;
}

int FaceDetail::getMaterial()
{
	return _material;
}
