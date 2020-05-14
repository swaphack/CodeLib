#include "ModelFbx.h"

using namespace render;

ModelFbx::ModelFbx()
{

}

ModelFbx::~ModelFbx()
{

}

void ModelFbx::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
	}
	this->startThread([this, fullpath](){
		sys::ModelDetailFbx* pFile = sys::Loader::loadModel<sys::ModelDetailFbx>(fullpath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
}

