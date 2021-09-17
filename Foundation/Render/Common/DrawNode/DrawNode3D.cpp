#include "DrawNode3D.h"

#include "Common/Fragment/import.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/DrawNode/import.h"
#include "Common/Tool/VertexTool.h"
#include "Graphic/import.h"
#include "Common/Scene/Cameras.h"
#include "Common/Texture/Texture2D.h"

render::DrawNode3D::DrawNode3D()
{

}

render::DrawNode3D::~DrawNode3D()
{
}



bool render::DrawNode3D::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	FragmentDepthTest* pDepthTest = this->getFragOperator()->getHandle<FragmentDepthTest>();
	if (pDepthTest)
	{
		pDepthTest->setEnabled(true);
	}

	// 添加属性改变监听
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->onDrawNode3DBodyChange();
	});

	addNotifyListener(NodeNotifyType::TEXTURE, [this]() {
		this->onDrawNode3DTextureChange();
	});

	addNotifyListener(NodeNotifyType::COLOR, [this]() {
		this->onDrawNode3DColorChange();
	});

	this->setCamera(G_CAMERAS->getCamera3D());

	return true;
}

void render::DrawNode3D::onDrawNode3DBodyChange()
{
	VertexTool::setTexture3DVertices(&_cubeVertex, math::Vector3(), _volume, _anchor);

	updateDrawNode3DMesh();
}

void render::DrawNode3D::onDrawNode3DColorChange()
{
	_cubeVertex.front.setColor(_color);
	_cubeVertex.back.setColor(_color);
	_cubeVertex.left.setColor(_color);
	_cubeVertex.right.setColor(_color);
	_cubeVertex.top.setColor(_color);
	_cubeVertex.bottom.setColor(_color);

	updateDrawNode3DMesh();
}

void render::DrawNode3D::onDrawNode3DTextureChange()
{
}

void render::DrawNode3D::updateDrawNode3DMesh()
{
	
}

void render::DrawNode3D::afterDraw()
{
	DrawNode::afterDraw();
}
