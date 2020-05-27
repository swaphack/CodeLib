#include "ModelFile.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"

render::ModelFile::ModelFile()
{

}

render::ModelFile::~ModelFile()
{

}

bool render::ModelFile::init()
{
	if (!Model::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::MODEL, [this]() {
		_bloadedModel = true;
		this->updateBufferData();
	});

	return true;
}

void render::ModelFile::setModelData(sys::ModelDetail* detail)
{
	if (detail == nullptr)
	{
		return;
	}
	_materiales->setModelDetail(detail);
	_meshes->setModelDetail(detail);
	this->notify(NodeNotifyType::MODEL);
}

void render::ModelFile::onDraw()
{
	if (!_bloadedModel)
	{
		return;
	}

	Model::onDraw();
}

