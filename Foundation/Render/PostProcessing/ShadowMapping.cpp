#include "ShadowMapping.h"

#include "Common/Shader/ShaderProgram.h"
#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/import.h"
#include "Graphic/import.h"
#include "3d/Common/Model.h"

render::ShadowMapping::ShadowMapping()
{
	_texture = CREATE_OBJECT(Texture2D);
	SAFE_RETAIN(_texture);
}

render::ShadowMapping::~ShadowMapping()
{
	SAFE_RELEASE(_texture);
	SAFE_RELEASE(_recordShaderProgram);
	SAFE_RELEASE(_renderShaderProgram);
}

bool render::ShadowMapping::init()
{
	if (!FrameBufferNode::init())
	{
		return false;
	}
	_notify->addListen(NodeNotifyType::BODY, [this]() {
		this->updateShadowMapping();
	});
	this->setTexture(_texture);
	return true;
}

void render::ShadowMapping::setRecordShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_recordShaderProgram);
	SAFE_RETAIN(program);
	_recordShaderProgram = program;
}

void render::ShadowMapping::setRenderShaderProgram(ShaderProgram* program)
{
	SAFE_RELEASE(_renderShaderProgram);
	SAFE_RETAIN(program);
	_renderShaderProgram = program;
}

void render::ShadowMapping::beforeDrawNode()
{
	this->broadcastFunc([this](Node* node) {
		if (node == nullptr || node == this)
		{
			return;
		}
		if (node->is<Model>())
		{
			auto pDrawNode = node->as<Model>();
			if (!pDrawNode->isCastShadow())
			{
				if (pDrawNode->isVisible())
				{
					pDrawNode->setSkipDraw(true);
					_setHideNode.insert(pDrawNode);
				}
			}
			else
			{
				pDrawNode->setShaderProgram(_recordShaderProgram);
			}
			pDrawNode->setShadowTexture(nullptr);
		}
	}, true);
	FrameBufferNode::beforeDrawNode();
}

void render::ShadowMapping::draw()
{
	int a = 1;
	this->broadcastFunc([this](Node* node) {
		if (node == nullptr || node == this)
		{
			return;
		}
		if (node->is<Model>())
		{
			auto pDrawNode = node->as<Model>();
			if (pDrawNode->isRecieveShadow())
			{
				pDrawNode->setShadowTexture(_texture);
			}

			pDrawNode->setShaderProgram(_renderShaderProgram);


			auto it = _setHideNode.find(pDrawNode);
			if (it != _setHideNode.end())
			{
				pDrawNode->setSkipDraw(false);
			}
		}
	}, true);

	_setHideNode.clear();

	DrawNode2D::onDraw();
}

void render::ShadowMapping::afterDrawNode()
{
	this->drawAllChildren();
}

void render::ShadowMapping::updateShadowMapping()
{
	int width = _rectVertex.getWidth();
	int height = _rectVertex.getHeight();
	if (width == 0 || height == 0)
	{
		return;
	}
	_bInitedFBN = true;

	_texture->setWidth(width);
	_texture->setHeight(height);

	_frameBuffer->bindFrameBuffer();

	GLState::enable((EnableMode)_texture->getTextureTarget());

	_texture->bindTexture();
	_texture->setTextureStorage(1, TextureInternalSizedFormat::DEPTH_COMPONENT32, width, height);
	//_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
	//_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_FUNC, GL_LEQUAL);
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
}

