#include "ModelFbx.h"
#include "ext-config.h"
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
	sys::ModelDetailFbx* pFile = sys::Loader::loadModel<sys::ModelDetailFbx>(fullpath);
	if (!pFile)
	{
		return;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);
}

void render::ModelFbx::loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
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
}

