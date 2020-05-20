#include "Model.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/View/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Fragment/import.h"

using namespace render;


Model::Model()
{
}

Model::~Model()
{
}

bool render::Model::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::MODEL, [this](){
		_loadModel = true;
		if (_material)
		{
			_material->updateMatTexture();
		}
		if (_mesh)
		{
			_mesh->initBufferData();
		}
	});

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	return true;
}

void Model::onDraw()
{
	if (!_loadModel)
	{
		return;
	}
	
	DrawNode::onDraw();
}

void render::Model::setModelData(sys::ModelDetail* detail)
{
	if (detail== nullptr)
	{
		return;
	}
	_material->setModelDetail(detail);
	_mesh->setModelDetail(detail);
	this->notify(NodeNotifyType::MODEL);
}


