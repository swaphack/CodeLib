#include "ModelObj.h"
#include "Resource/Paser/FileObj.h"
#include "Resource/Loader/Loader.h"

using namespace render;

ModelObj::ModelObj()
{

}

ModelObj::~ModelObj()
{

}

void ModelObj::load(const std::string& filepath)
{
	this->startThread([this, filepath](){
		FileObj* pFile = Loader::load<FileObj>(filepath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
}

