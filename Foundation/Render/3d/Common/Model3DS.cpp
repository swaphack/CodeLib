#include "Model3DS.h"
#include "ext-config.h"
using namespace render;

Model3DS::Model3DS()
{
}

Model3DS::~Model3DS()
{
}

void Model3DS::load(const std::string& filepath)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
	}
	sys::ModelDetail3DS* pFile = sys::Loader::loadModel<sys::ModelDetail3DS>(fullpath);
	if (!pFile)
	{
		return;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);
}

void render::Model3DS::loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
	}
	this->startThread([this, fullpath, callback]() {
		sys::ModelDetail3DS* pFile = sys::Loader::loadModel<sys::ModelDetail3DS>(fullpath);
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
