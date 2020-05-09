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
	auto task = std::thread([this, filepath](){
		FileObj* pFile = Loader::load<FileObj>(filepath);
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});

	task.detach();
}

