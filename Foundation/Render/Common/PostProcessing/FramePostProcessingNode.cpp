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
	_renderBuffer = CREATE_OBJECT(RenderBuffer);

	//_frameBuffer->setFrameBufferTarget(FrameBufferTarget::DRAW_FRAMEBUFFER);
	//_renderBuffer->setRenderBufferTarget(RenderBufferTarget::RENDERBUFFER);

	SAFE_RETAIN(_texture);
	SAFE_RETAIN(_frameBuffer);
	SAFE_RETAIN(_renderBuffer);
}

render::FramePostProcessingNode::~FramePostProcessingNode()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_frameBuffer);
	SAFE_RELEASE(_renderBuffer);
}

bool render::FramePostProcessingNode::init()
{
	if (!DrawNode::init())
	{
		return false;
	}

	_notify->addListen(NodeNotifyType::SPACE, [this]() {
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
	_frameBuffer->bindFrameBuffer();

	this->drawAllChildren();

	_frameBuffer->unbindFrameBuffer();
	GLDebug::showError();
	/*
	const auto& size = Tool::getGLViewSize();
	GLState::setViewport(0, 0, 
		size.getWidth(), size.getHeight());

	GLDebug::showError();
	GLState::enable(EnableMode::DEPTH_TEST);
	

	GLDebug::showError();

	uint32_t bitfield =
		(uint32_t)ClearBufferBitType::COLOR_BUFFER_BIT
		| (uint32_t)ClearBufferBitType::DEPTH_BUFFER_BIT
		//|(uint32_t)ClearBufferBitType::STENCIL_BUFFER_BIT
		;
	//GLRender::clearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//GLRender::clear(bitfield);

	GLDebug::showError();
	*/
}
/*
void render::FramePostProcessingNode::onDraw()
{
	GLDebug::showError();
}
*/
void render::FramePostProcessingNode::afterDrawNode()
{
	/*
	GLDebug::showError();

	GLState::disable(EnableMode::DEPTH_TEST);
	uint32_t bitfield =
		(uint32_t)ClearBufferBitType::COLOR_BUFFER_BIT
		| (uint32_t)ClearBufferBitType::DEPTH_BUFFER_BIT
		| (uint32_t)ClearBufferBitType::STENCIL_BUFFER_BIT
		;

	//GLRender::clearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//GLRender::clear(bitfield);
	GLDebug::showError();

	DrawNode::onDraw();
	GLDebug::showError();
	//GLFixedFunction::popAttrib();


	//this->drawAllChildren();
	*/
}

bool render::FramePostProcessingNode::isFrameInited()
{
	return _bInitedFrameBufferData;
}

void render::FramePostProcessingNode::updateTextureSize()
{
	_bInitedFrameBufferData = true;	

	int width = _rectVertex.getWidth();
	int height = _rectVertex.getHeight();

	_texture->setWidth(width);
	_texture->setHeight(height);

	_frameBuffer->bindFrameBuffer();

	GLState::enable((EnableMode)_texture->getTextureTarget());
	_texture->bindTexture();
	_texture->setTextureImage(0, TextureInternalSizedFormat::RGBA8, width, height, 0, TextureExternalFormat::RGBA, TextureExternalDataType::UNSIGNED_BYTE, 0);
	_texture->applyTextureSetting();
	_frameBuffer->setTexture(FrameBufferAttachment::COLOR_ATTACHMENT0, _texture->getTextureID(), 0);

	//_texture->unbindTexture();
	//GLState::disable((EnableMode)_texture->getTextureTarget());
	GLDebug::showError();

	GLDebug::showError();
	GLDebug::showError();
	_renderBuffer->bindRenderBuffer();
	_renderBuffer->setStorage(RenderBufferInternalFormat::DEPTH24_STENCIL8, width, height);
	_frameBuffer->setRenderBuffer(FrameBufferAttachment::DEPTH_STENCIL_ATTACHMENT, _renderBuffer);

	//_renderBuffer->unbindRenderBuffer();
	GLDebug::showError();
	GLDebug::showError();

	GLDebug::showError();

	//GLFrameRender::setDrawBuffer(DrawBufferType::COLOR_ATTACHMENT0);
	
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
	auto pMesh = getMesh(DRAW_MESH_INDEX);
	if (pMesh)
	{
		pMesh->getMeshDetail()->setVertices(4, vertices, 2);
		pMesh->getMeshDetail()->setUVs(4, uvs, 2);
		pMesh->getMeshDetail()->setIndices(6, indices, 1);
	}

	this->updateBufferData();
}

