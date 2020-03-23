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
	FileFbx* pFile = Loader::load<FileFbx>(filepath.c_str());
	this->setModelData(pFile);
}

