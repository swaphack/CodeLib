#include "FramePostProcessingNode.h"
#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/FrameBuffer.h"
#include "Common/FrameRender/RenderBuffer.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

render::FramePostProcessingNode::FramePostProcessingNode()
{
	_texture = CREATE_OBJECT(Texture2D);
	_frameBuffer = CREATE_OBJECT(FrameBuffer);

	//_frameBuffer->setFrameBufferTarget(FrameBufferTarget::DRAW_FRAMEBUFFER);
	//_renderBuffer->setRenderBufferTarget(RenderBufferTarget::RENDERBUFFER);

	SAFE_RETAIN(_texture);
	SAFE_RETAIN(_frameBuffer);
}

render::FramePostProcessingNode::~FramePostProcessingNode()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_frameBuffer);
}

bool render::FramePostProcessingNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);
		this->updateTextureSize();
	});

	setTexture(_texture);

	return true;
}

void render::FramePostProcessingNode::drawNode()
{
	if (!_bInitedFrameBufferData)
	{
		return;
	}

	GLDebug::showError();
	DrawNode::drawNode();
	GLDebug::showError();
}

void render::FramePostProcessingNode::beforeDrawNode()
{
	this->beginRecord();

	this->drawAllChildren();

	//_texture->generateTextureMipMap();

	this->endRecord();
}

void render::FramePostProcessingNode::afterDrawNode()
{
}

bool render::FramePostProcessingNode::isFrameInited()
{
	return _bInitedFrameBufferData;
}

void render::FramePostProcessingNode::beginRecord()
{
	_frameBuffer->bindFrameBuffer();
}

void render::FramePostProcessingNode::endRecord()
{
	_frameBuffer->unbindFrameBuffer();
}

void render::FramePostProcessingNode::updateTextureSize()
{
	_bInitedFrameBufferData = true;	

	int width = _rectVertex.getWidth();
	int height = _rectVertex.getHeight();

	_texture->setWidth(width);
	_texture->setHeight(height);

	_frameBuffer->bindFrameBuffer();
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_WIDTH, (int)Tool::getGLViewWidth());
	_frameBuffer->setParameter(FrameBufferParameter::FRAMEBUFFER_DEFAULT_HEIGHT, (int)Tool::getGLViewHeight());

	GLState::enable((EnableMode)_texture->getTextureTarget());
	_texture->bindTexture();
	//_texture->setTextureImage(0, TextureInternalSizedFormat::RGBA8, width, height, 0, TextureExternalFormat::RGBA, TextureExternalDataType::UNSIGNED_BYTE, 0);
	_texture->setTextureStorage(1, TextureInternalSizedFormat::RGBA8, width, height);
	_texture->applyTextureSetting();
	_frameBuffer->setTexture(FrameBufferAttachment::COLOR_ATTACHMENT0, _texture->getTextureID(), 0);

	GLDebug::showError();

	FrameBufferStatus status = _frameBuffer->checkStatus();
	GLDebug::showError();
	if (status != FrameBufferStatus::FRAMEBUFFER_COMPLETE)
	{
		PRINT("Frame Buffer is not Complete!\n");
		return;
	}

	_frameBuffer->unbindFrameBuffer();
	GLDebug::showError();

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

