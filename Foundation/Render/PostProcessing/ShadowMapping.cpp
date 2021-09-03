#include "ShadowMapping.h"

#include "Common/Shader/ShaderProgram.h"
#include "Common/Texture/Texture2D.h"
#include "Common/FrameRender/import.h"
#include "Common/View/Camera.h"
#include "Common/Tool/VertexTool.h"
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
}

bool render::ShadowMapping::init()
{
	if (!FrameBufferNode::init())
	{
		return false;
	}
	addNotifyListener(NodeNotifyType::BODY, [this]() {
		this->updateShadowMapping();
	});
	this->setTexture(_texture);
	return true;
}

void render::ShadowMapping::beginCastShadow(Node* light, Scene* root, const std::set<Node*>& castShadowNodes)
{
	auto pCamera = this->getCamera();
	if (pCamera == nullptr)
	{
		return;
	}
	GLState::setViewport(0, 0, getWidth(), getHeight());
	_frameBuffer->bindFrameBuffer();



	_frameBuffer->unbindFrameBuffer();
}

void render::ShadowMapping::beginRenderShadow()
{
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
				//pDrawNode->setShaderProgram(_receiveLightShaderProgram);
			}

			auto it = _setHideNode.find(pDrawNode);
			if (it != _setHideNode.end())
			{
				pDrawNode->setSkipDraw(false);
			}
		}
	}, true);

	_setHideNode.clear();
}

void render::ShadowMapping::updateShadowMapping()
{
	render::RectVertex rectVertex;
	render::VertexTool::setTexture2DVertices(&rectVertex, math::Vector3(), _volume, _anchor);

	int width = rectVertex.getRightTopPosition().getX() - rectVertex.getLeftBottomPosition().getX();
	int height = rectVertex.getRightTopPosition().getY() - rectVertex.getLeftBottomPosition().getY();
	if (width == 0 || height == 0)
	{
		return;
	}
	_bInitedFBN = true;

	_texture->setWidth(width);
	_texture->setHeight(height);

	GLState::enable((EnableMode)_texture->getTextureTarget());

	_texture->bindTexture();
	_texture->setTextureStorage(1, TextureInternalSizedFormat::DEPTH_COMPONENT32, width, height);
	_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
	_texture->setTexParameter(TextureParameter::TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	_texture->setTexParameter(TextureParameter::DEPTH_TEXTURE_MODE, GL_LUMINANCE);

	_texture->applyTextureSetting();
	_frameBuffer->bindFrameBuffer();
	_frameBuffer->setTexture2D(FrameBufferAttachment::DEPTH_ATTACHMENT, _texture->getTextureID(), 0);

	GLRender::setDrawBuffer(DrawBufferMode::NONE);
	GLRender::setReadBuffer(ReadBufferMode::NONE);

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

