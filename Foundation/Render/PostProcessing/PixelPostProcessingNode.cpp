#include "PixelPostProcessingNode.h"
#include "Common/Texture/Texture2D.h"
#include "Graphic/import.h"
#include "Common/Tool/Tool.h"
#include "Common/Material/import.h"
#include "Common/Mesh/import.h"
#include "Common/Shader/import.h"

render::PixelPostProcessingNode::PixelPostProcessingNode()
{
	_texture = CREATE_OBJECT(Texture2D);
	SAFE_RETAIN(_texture);
}

render::PixelPostProcessingNode::~PixelPostProcessingNode()
{
	SAFE_RELEASE(_texture);

	SAFE_FREE(_textureData);
}

bool render::PixelPostProcessingNode::init()
{
	if (!DrawNode2D::init())
	{
		return false;
	}

	addNotifyListener(NodeNotifyType::BODY, [this]() {
		Tool::calRect(math::Vector3(), _volume, _anchor, _localRectPoints);
		this->updateTextureSize();
	});

	setTexture(_texture);

	return true;
}


void render::PixelPostProcessingNode::beforeDrawNode()
{
	GLDebug::showError();
	const auto& size = Tool::getGLViewSize();
	float width = size.getWidth();
	float height = size.getHeight();

	GLDebug::showError();
	if (_textureData == nullptr)
	{
		_textureData = (uint8_t*)malloc(width * height * 4);
	}

	GLRender::readPixels(0, 0, width, height, ReadPixelDataFormat::RGBA, ReadPixelDataType::UNSIGNED_BYTE, _textureData);

	GLDebug::showError();
	sys::ImageDetail detail;
	detail.setDataFormat(sys::ImageDataFormat::RGBA);
	detail.setPixels(_textureData, width, height, 4);
	GLDebug::showError();
	_texture->load(&detail);
	GLDebug::showError();
}

void render::PixelPostProcessingNode::afterDrawNode()
{
}

void render::PixelPostProcessingNode::updateTextureSize()
{
	float vertices[] = {
		_localRectPoints.leftDown.getX(),_localRectPoints.leftDown.getY(),
		_localRectPoints.rightDown.getX(),_localRectPoints.rightDown.getY(),
		_localRectPoints.rightUp.getX(),_localRectPoints.rightUp.getY(),
		_localRectPoints.leftUp.getX(),_localRectPoints.leftUp.getY(),
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
	}

	this->updateMeshData();
}

