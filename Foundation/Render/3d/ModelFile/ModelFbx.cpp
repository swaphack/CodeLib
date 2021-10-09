#include "ModelFbx.h"
#include "ext-config.h"
using namespace render;

ModelFbx::ModelFbx()
{

}

ModelFbx::~ModelFbx()
{

}

bool ModelFbx::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return false;
	}
	sys::ModelDetailFbx* pFile = sys::ResourceLoader::loadModel<sys::ModelDetailFbx>(fullpath);
	if (!pFile)
	{
		return false;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);

	return true;
}

bool render::ModelFbx::loadAsyn(const std::string& filepath, const LoadedModelCallback& func)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return false;
	}
	this->setAsynLoadedCallback(func);
	this->startThread([fullpath, this]() {
		sys::ModelDetailFbx* pFile = sys::ResourceLoader::loadModel<sys::ModelDetailFbx>(fullpath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_RELEASE(pFile);
	});

	return true;
}

