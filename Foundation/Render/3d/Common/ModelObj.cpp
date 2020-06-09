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

	sys::ModelDetailObj* pFile = sys::Loader::loadModel<sys::ModelDetailObj>(fullpath);
	if (!pFile)
	{
		return;
	}
	this->setModelData(pFile);
	SAFE_DELETE(pFile);
}

void render::ModelObj::loadAsyn(const std::string& filepath, const std::function<void(Node*)>& callback)
{
	std::string fullpath = G_FILEPATH->getFilePath(filepath);
	if (fullpath.empty())
	{
		return;
	}

	this->startThread([this, fullpath, callback]() {
		sys::ModelDetailObj* pFile = sys::Loader::loadModel<sys::ModelDetailObj>(fullpath);
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

