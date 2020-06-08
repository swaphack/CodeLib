#include "PostProcessingNode.h"
#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/FrameBuffer.h"
#include "Common/FrameRender/RenderBuffer.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"

render::PostProcessingNode::PostProcessingNode()
{
	_texture = CREATE_OBJECT(Texture2D);
	_frameBuffer = CREATE_OBJECT(FrameBuffer);
	_renderBuffer = CREATE_OBJECT(RenderBuffer);

	//_frameBuffer->setFrameBufferTarget(FrameBufferTarget::DRAW_FRAMEBUFFER);
	//_renderBuffer->setRenderBufferTarget(RenderBufferTarget::RENDERBUFFER);

	SAFE_RETAIN(_texture);
	SAFE_RETAIN(_frameBuffer);
	SAFE_RETAIN(_renderBuffer);
}

render::PostProcessingNode::~PostProcessingNode()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_frameBuffer);
	SAFE_RELEASE(_renderBuffer);
}

bool render::PostProcessingNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this]() {
		Tool::calRect(math::Vector3(), _volume, _anchor, _rectVertex);
		this->updateTextureSize();
	});

	getMaterials()->addTexture(MAT_TEXTURE_NAME, _texture);
	getMaterial()->getMaterialDetail()->setAmbientTextureMap(MAT_TEXTURE_NAME);

	return true;
}

void render::PostProcessingNode::drawNode()
{
	if (!_bInitedFrameBufferData)
	{
		return;
	}

	DrawNode::drawNode();
}

void render::PostProcessingNode::beforeDrawNode()
{
	DrawNode::beforeDrawNode();
	GLState::disable(EnableMode::DEPTH_TEST);

	uint32_t bitfield = (uint32_t)ClearBufferBitType::COLOR_BUFFER_BIT;

	GLRender::clearColor(0, 0, 0, 1);
	GLRender::clear(bitfield);
}

void render::PostProcessingNode::afterDrawNode()
{
	//GLState::enable(EnableMode::DEPTH_TEST);
}

void render::PostProcessingNode::bindFrameBuffer()
{
	if (!_bInitedFrameBufferData)
	{
		return;
	}

	_frameBuffer->bindFrameBuffer();
}

void render::PostProcessingNode::unbindFrameBuffer()
{
	if (!_bInitedFrameBufferData)
	{
		return;
	}

	_frameBuffer->unbindFrameBuffer();
}

void render::PostProcessingNode::updateTextureSize()
{
	_bInitedFrameBufferData = true;

	

	float width = _rectVertex.getWidth();
	float height = _rectVertex.getHeight();

	_texture->setWidth(width);
	_texture->setHeight(height);

	GLState::enable((EnableMode)_texture->getTextureTarget());
	_texture->bindTexture();
	_texture->setTextureImage(0, TextureInternalSizedFormat::RGBA8, width, height, 0, TextureExternalFormat::RGBA, TextureExternalDataType::UNSIGNED_BYTE, nullptr);
	_texture->applyTextureSetting();
	_texture->unbindTexture();
	GLState::disable((EnableMode)_texture->getTextureTarget());
	GLDebug::showError();

	GLDebug::showError();
	GLDebug::showError();
	_renderBuffer->bindRenderBuffer();
	_renderBuffer->setStorage(RenderBufferInternalFormat::DEPTH_STENCIL, width, height);
	_renderBuffer->unbindRenderBuffer();
	GLDebug::showError();

	GLDebug::showError();
	_frameBuffer->bindFrameBuffer();
	_frameBuffer->setTexture2D(FrameBufferAttachment::COLOR_ATTACHMENT0, _texture->getTextureID(), 0);
	_frameBuffer->setRenderBuffer(FrameBufferAttachment::DEPTH_STENCIL_ATTACHMENT, _renderBuffer);
	
	GLDebug::showError();

	FrameBufferStatus status = _frameBuffer->checkStatus();
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
	auto pMesh = getMesh(DRAW_MESH_INDEX);
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(4, vertices, 2);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, indices, 1);
	}

	this->updateBufferData();
}

