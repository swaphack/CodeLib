#include "Model.h"
#include "Graphic/import.h"
#include "Common/Shader/import.h"
#include "Common/View/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Fragment/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"

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
		this->updateBufferData();
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
	_materiales->setModelDetail(detail);
	_meshes->setModelDetail(detail);
	this->notify(NodeNotifyType::MODEL);
}


