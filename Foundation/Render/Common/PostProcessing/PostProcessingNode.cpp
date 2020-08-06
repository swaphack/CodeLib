#include "PostProcessingNode.h"
#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/FrameBuffer.h"
#include "Common/FrameRender/RenderBuffer.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/Shader/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

render::PostProcessingNode::PostProcessingNode()
{
	_texture = CREATE_OBJECT(Texture2D);
	SAFE_RETAIN(_texture);
}

render::PostProcessingNode::~PostProcessingNode()
{
	SAFE_RELEASE(_texture);
}

bool render::PostProcessingNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->updateTextureSize();
	});

	setTexture(_texture);

	return true;
}

void render::PostProcessingNode::updateTextureSize()
{
	_bInitedFBN = true;

	int width = _rectVertex.getWidth();
	int height = _rectVertex.getHeight();

	_texture->setWidth(width);
	_texture->setHeight(height);

	_frameBuffer->bindFrameBuffer();

	GLState::enable((EnableMode)_texture->getTextureTarget());
	_texture->bindTexture();
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
}

