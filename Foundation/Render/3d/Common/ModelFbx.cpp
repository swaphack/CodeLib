#include "ModelFbx.h"

#include "Resource/Paser/FileFbx.h"
#include "Resource/Loader/Loader.h"

using namespace render;

ModelFbx::ModelFbx()
{

}

ModelFbx::~ModelFbx()
{

}

void ModelFbx::load(const std::string& filepath)
{
	this->startThread([this, filepath](){
		FileFbx* pFile = Loader::load<FileFbx>(filepath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
}

