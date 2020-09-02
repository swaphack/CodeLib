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
	if (!DrawNode2D::init())
	{
		return false;
	}

	_frameBuffer->bindFrameBuffer();
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_WIDTH, (int)Tool::getGLViewWidth());
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_HEIGHT, (int)Tool::getGLViewHeight());
	_frameBuffer->unbindFrameBuffer();

	return true;
}

void render::FrameBufferNode::drawNode()
{
	if (!isInitedFBN())
	{
		return;
	}

	GLDebug::showError();
	DrawNode2D::drawNode();
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

bool render::FrameBufferNode::isInitedFBN()
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

