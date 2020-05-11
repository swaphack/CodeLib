#include "Model3DS.h"
#include "Resource/Paser/File3DS.h"
#include "Resource/Loader/Loader.h"

using namespace render;

Model3DS::Model3DS()
{
}

Model3DS::~Model3DS()
{
}

void Model3DS::load(const std::string& filepath)
{
	this->startThread([this, filepath](){
		File3DS* pFile = Loader::load<File3DS>(filepath);
		if (!pFile)
		{
			return;
		}
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
}
/*
void Model3DS::draw()
{
	
}
*/