#include "ModelObj.h"
#include "ext-config.h"
using namespace render;

ModelObj::ModelObj()
{

}

ModelObj::~ModelObj()
{

}

void ModelObj::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
	}

	this->startThread([this, fullpath](){
		sys::ModelDetailObj* pFile = sys::Loader::loadModel<sys::ModelDetailObj>(fullpath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
}

