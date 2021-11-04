#include "MultiMeshModel.h"
#include "Graphic/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Tool/VertexTool.h"
#include "Common/Fragment/import.h"
#include "Common/Scene/Cameras.h"
#include "Box/BoxSpace.h"

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

	Box3DProtocol::initBox3D(this);

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	this->setCamera(G_CAMERAS->getCamera3D());
	return true;
}

void render::MultiMeshModel::afterDrawNode()
{
	this->drawAllChildren();
}

bool render::MultiMeshModel::containPoint(const math::Vector2& touchPoint)
{
	return G_BOXSPACE->containsTouchPoint3D(this, touchPoint);
}

