#include "ModelObj.h"
#include "ext-config.h"
using namespace render;

ModelObj::ModelObj()
{

}

ModelObj::~ModelObj()
{

}

bool ModelObj::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return false;
	}

	sys::ModelDetailObj* pFile = sys::ResourceLoader::loadModel<sys::ModelDetailObj>(fullpath);
	if (!pFile)
	{
		return false;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);

	return true;
}

bool render::ModelObj::loadAsyn(const std::string& filepath, const LoadedModelCallback& func)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return false;
	}
	this->setAsynLoadedCallback(func);
	this->startThread([this, fullpath]() {
		sys::ModelDetailObj* pFile = sys::ResourceLoader::loadModel<sys::ModelDetailObj>(fullpath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_RELEASE(pFile);
	});

	return true;
}

