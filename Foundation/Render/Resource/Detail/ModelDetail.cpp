#include "ModelDetail.h"
#include "Resource/Paser/File3DS.h"

using namespace render;


ModelDetail::ModelDetail()
{

}

ModelDetail::~ModelDetail()
{

}

ModelResourceFormat ModelDetail::getModelFormat()
{
	return _format;
}

void ModelDetail::load(const char* filename)
{

}

void ModelDetail::setModelFormat(ModelResourceFormat format)
{
	_format = format;
}

//////////////////////////////////////////////////////////////////////////

Model3DSDetail::Model3DSDetail()
{
	this->setModelFormat(EMRF_3DS);
}

Model3DSDetail::~Model3DSDetail()
{
	SAFE_DELETE(_data);
}

void Model3DSDetail::load(const char* filename)
{

}

const File3DS* Model3DSDetail::getData()
{
	return _data;
}
