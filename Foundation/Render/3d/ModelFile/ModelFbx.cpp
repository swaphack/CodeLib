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
	sys::ModelDetailFbx* pFile = sys::Loader::loadModel<sys::ModelDetailFbx>(fullpath);
	if (!pFile)
	{
		return false;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);

	return true;
}

bool render::ModelFbx::loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return false;
	}
	this->startThread([this, fullpath, callback]() {
		sys::ModelDetailFbx* pFile = sys::Loader::loadModel<sys::ModelDetailFbx>(fullpath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
		if (callback)
		{
			callback(this);
		}
	});

	return true;
}

