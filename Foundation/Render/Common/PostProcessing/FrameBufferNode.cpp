#include "FrameBufferNode.h"
#include "Common/Tool/Tool.h"
#include "Common/FrameRender/FrameBuffer.h"
#include "Graphic/import.h"
#include "Common/Mesh/import.h"

render::FrameBufferNode::FrameBufferNode()
{
	_frameBuffer = CREATE_OBJECT(FrameBuffer);
	SAFE_RETAIN(_frameBuffer);
}

render::FrameBufferNode::~FrameBufferNode()
{

	SAFE_RELEASE(_frameBuffer);
}

bool render::FrameBufferNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->updateFrameSize();
	});

	_frameBuffer->bindFrameBuffer();
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_WIDTH, (int)Tool::getGLViewWidth());
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_HEIGHT, (int)Tool::getGLViewHeight());
	_frameBuffer->unbindFrameBuffer();

	return true;
}

void render::FrameBufferNode::drawNode()
{
	if (!isInitedNode())
	{
		return;
	}

	GLDebug::showError();
	DrawNode::drawNode();
	GLDebug::showError();
}

void render::FrameBufferNode::beforeDrawNode()
{
	this->beginRecord();

	this->drawAllChildren();

	this->endRecord();
}

void render::FrameBufferNode::afterDrawNode()
{

}

bool render::FrameBufferNode::isInitedNode()
{
	return _bInitedFBN;
}

void render::FrameBufferNode::beginRecord()
{
	_frameBuffer->bindFrameBuffer();
}

void render::FrameBufferNode::endRecord()
{
	_frameBuffer->unbindFrameBuffer();
}

void render::FrameBufferNode::updateFrameSize()
{
	Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);

	float vertices[] = {
		_rectVertex.leftDown.getX(),_rectVertex.leftDown.getY(),
		_rectVertex.rightDown.getX(),_rectVertex.rightDown.getY(),
		_rectVertex.rightUp.getX(),_rectVertex.rightUp.getY(),
		_rectVertex.leftUp.getX(),_rectVertex.leftUp.getY(),
	};

	float uvs[] = {
		0,0,
		1,0,
		1,1,
		0,1
	};

	uint32_t indices[] = { 0,1,2,0,2,3 };
	auto pMesh = getMesh();
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(4, vertices, 2);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, indices, 1);

		pMesh->initDetailNormalData();
	}

	this->updateBufferData();
}

