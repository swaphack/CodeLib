#include "MultiMeshModel.h"
#include "Graphic/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Fragment/import.h"

render::MultiMeshModel::MultiMeshModel()
{

}

render::MultiMeshModel::~MultiMeshModel()
{

}

bool render::MultiMeshModel::init()
{
	if (!MultiDrawNode::init())
	{
		return false;
	}

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		onMultiDrawNodeBodyChange();
	});

	return true;
}

void render::MultiMeshModel::onMultiDrawNodeBodyChange()
{
	VertexTool::setTexture3DVertices(&_cubeVertex, math::Vector3(), _volume, _anchor);

	updateMultiDrawNode3DMesh();
}

void render::MultiMeshModel::updateMultiDrawNode3DMesh()
{
}

void render::MultiMeshModel::afterDrawNode()
{
	this->drawAllChildren();
}

