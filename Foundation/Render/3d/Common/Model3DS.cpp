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
	auto task = std::thread([this, filepath](){
		File3DS* pFile = Loader::load<File3DS>(filepath);
		this->setModelData(pFile);
		SAFE_DELETE(pFile);
	});
	task.detach();
}
/*
void Model3DS::draw()
{
	
}
*/