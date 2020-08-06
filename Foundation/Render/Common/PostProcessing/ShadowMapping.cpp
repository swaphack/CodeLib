#include "ShadowMapping.h"

#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/import.h"
#include "Graphic/import.h"

render::ShadowMapping::ShadowMapping()
{
	_texture = CREATE_OBJECT(Texture2D);
	SAFE_RETAIN(_texture);
}

render::ShadowMapping::~ShadowMapping()
{
	SAFE_RELEASE(_texture);
}

bool render::ShadowMapping::init()
{
	if (!FrameBufferNode::init())
	{
		return false;
	}
	this->setTexture(_texture);
	return true;
}

void render::ShadowMapping::beginRecord()
{
	FrameBufferNode::beginRecord();
}

void render::ShadowMapping::endRecord()
{
	FrameBufferNode::endRecord();
}

void render::ShadowMapping::afterDrawNode()
{
	this->drawAllChildren();
}

void render::ShadowMapping::updateShadowMapping()
{
	_bInitedFBN = true;

	int width = _rectVertex.getWidth();
	int height = _rectVertex.getHeight();

	_texture->setWidth(width);
	_texture->setHeight(height);

	_frameBuffer->bindFrameBuffer();

	GLState::enable((EnableMode)_texture->getTextureTarget());

	_texture->bindTexture();
	_texture->setTextureStorage(1, TextureInternalSizedFormat::DEPTH_COMPONENT32, width, height);
	_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
	_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	_texture->applyTextureSetting();
	_frameBuffer->setTexture(FrameBufferAttachment::DEPTH_ATTACHMENT, _texture->getTextureID(), 0);

	GLDebug::showError();

	FrameBufferStatus status = _frameBuffer->checkStatus();
	GLDebug::showError();
	if (status != FrameBufferStatus::FRAMEBUFFER_COMPLETE)
	{
		PRINT("Frame Buffer is not Complete!\n");
		return;
	}

	GLRender::setDrawBuffer(DrawBufferMode::NONE);
	GLRender::setReadBuffer(ReadBufferMode::NONE);

	_frameBuffer->unbindFrameBuffer();
	GLDebug::showError();

	//
}

