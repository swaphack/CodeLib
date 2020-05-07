#include "CtrlFrame.h"

#include "Common/Texture/Texture.h"
#include "Common/Texture/TexFrame.h"
#include "Common/Tool/TextureTool.h"
#include "Common/Tool/Tool.h"
#include "Common/Shader/ShaderProgram.h"

#include "Common/Buffer/import.h"

#include "Graphic/import.h"

#define USE_BUFFER_OBJECT 1

using namespace render;

CtrlFrame::CtrlFrame()
:_bFlipX(false)
, _bFlipY(false)
{
	_texFrame = CREATE_OBJECT(TexFrame);
	SAFE_RETAIN(_texFrame);
}

CtrlFrame::~CtrlFrame()
{
	SAFE_RELEASE(_texFrame);
#if USE_BUFFER_OBJECT
	SAFE_RELEASE(_vertexArrayObject);
	SAFE_RELEASE(_indiceObject);
	SAFE_RELEASE(_vertexObject);
#endif
}

bool CtrlFrame::init()
{
	if (!CtrlWidget::init())
	{
		return false;
	}

	_notify->addListen(ENP_SPACE, [this](){
		onTextureChange();
#if USE_BUFFER_OBJECT
		this->updateBufferData();
#endif
		
	});

	_notify->addListen(ENP_TEXTURE_FRAME, [this](){
		onTextureChange();
	});
#if USE_BUFFER_OBJECT
	this->initBufferObject();
#endif


	return true;
}

void CtrlFrame::drawSample()
{
#if USE_BUFFER_OBJECT
	this->drawSampleWithBufferObject();
#else
	this->drawSampleWithClientArray();
#endif
}

void CtrlFrame::setTexture(const Texture* texture)
{
	if (texture == nullptr)
	{
		return;
	}

	_texFrame->setTexture(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTextureWithRect(const Texture* texture)
{
	_texFrame->setTextureWithRect(texture);
	this->notify(ENP_TEXTURE_FRAME);
}

void CtrlFrame::setTexRect(const math::Rect& rect)
{
	_texFrame->setRect(rect);
	this->notify(ENP_TEXTURE_FRAME);
} 

void CtrlFrame::setTexFrame(const TexFrame* texFrame)
{
	if (texFrame == nullptr)
	{
		return;
	}

	*_texFrame = *texFrame;
	this->notify(ENP_TEXTURE_FRAME);
}

const TexFrame* CtrlFrame::getTexFrame()
{
	return _texFrame;
}

void CtrlFrame::setFlipX(bool status)
{
	_bFlipX = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipX()
{
	return _bFlipX;
}

void CtrlFrame::setFlipY(bool status)
{
	_bFlipY = status;
	this->notify(ENP_TEXTURE_FRAME);
}

bool CtrlFrame::isFlipY()
{
	return _bFlipY;
}

void CtrlFrame::onTextureChange()
{
	const Texture* texture = _texFrame->getTexture();
	if (texture == nullptr)
	{
		return;
	}

	math::Size size = math::Size(static_cast<float>(texture->getWidth()), static_cast<float>(texture->getHeight()));

	TextureTool::setTexture2DCoords(&_texRect, size, _texFrame->getRect());

	TextureTool::setTexture2DVertexts(&_texRect, math::Vector3(), _volume, _anchor);
	TextureTool::setTexture2DFlip(&_texRect, _bFlipX, _bFlipY);
}

void render::CtrlFrame::initBufferObject()
{
	{
		_vertexArrayObject = CREATE_OBJECT(VertexArrayObject);
		SAFE_RETAIN(_vertexArrayObject);
		GLDebug::showError();
	}

	{
		_vertexObject = CREATE_OBJECT(NoNamedBufferObject);
		SAFE_RETAIN(_vertexObject);

		_vertexObject->setBufferTarget(BufferTarget::ARRAY_BUFFER);
		_vertexObject->bindBuffer();

		uint32_t nVerticeSize = sizeof(_texRect.vertices);
		uint32_t nColorSize = sizeof(_texRect.colors);
		uint32_t nUVSize = sizeof(_texRect.uvs);
		uint32_t nTotalSize = nVerticeSize + nColorSize + nUVSize;

		_vertexObject->setBufferData(nTotalSize, nullptr, BufferDataUsage::STATIC_DRAW);
		_vertexArrayObject->setBufferObject(_vertexObject);
		GLDebug::showError();
	}

	{
		_indiceObject = CREATE_OBJECT(NoNamedBufferObject);
		SAFE_RETAIN(_indiceObject);

		_indiceObject->setBufferTarget(BufferTarget::ELEMENT_ARRAY_BUFFER);
		_indiceObject->bindBuffer();

		uint32_t nIndiceSize = sizeof(_texRect.indices);
		_indiceObject->setBufferData(nIndiceSize, _texRect.indices, BufferDataUsage::STATIC_DRAW);
		GLDebug::showError();
	}
}

void render::CtrlFrame::updateBufferData()
{
	uint32_t nVerticeSize = sizeof(_texRect.vertices);
	uint32_t nColorSize = sizeof(_texRect.colors);
	uint32_t nUVSize = sizeof(_texRect.uvs);

	_vertexObject->bindBuffer();

	GLDebug::showError();
	if (nVerticeSize > 0)
	{
		_vertexObject->setBufferSubData(0, nVerticeSize, _texRect.vertices);
	}
	GLDebug::showError();
	if (nColorSize > 0)
	{
		_vertexObject->setBufferSubData(nVerticeSize, nColorSize, _texRect.colors);
	}
	GLDebug::showError();
	if (nUVSize > 0)
	{
		_vertexObject->setBufferSubData(nVerticeSize + nColorSize, nUVSize, _texRect.uvs);
	}

	GLDebug::showError();
}

void render::CtrlFrame::drawSampleWithClientArray()
{
	if (_texFrame->getTexture() == nullptr)
	{
		return;
	}

	int textID = _texFrame->getTexture()->getTextureID();
	if (textID == 0)
	{
		return;
	}

	GLState::enable(EnableModel::TEXTURE_2D);
	GLTexture::bindTexture2D(textID);

	GLClientArrays::enableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::setVertexPointer(3, DataType::FLOAT, 0, _texRect.vertices);

	GLClientArrays::enableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::setTexCoordPointer(2, DataType::FLOAT, 0, _texRect.uvs);

	GLClientArrays::enableClientState(ClientArrayType::COLOR_ARRAY);
	GLClientArrays::setColorPointer(4, DataType::FLOAT, 0, _texRect.colors);

	GLClientArrays::drawElements(DrawMode::TRIANGLES, 6, IndexDataType::UNSIGNED_INT, _texRect.indices);

	GLClientArrays::disableClientState(ClientArrayType::VERTEX_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::TEXTURE_COORD_ARRAY);
	GLClientArrays::disableClientState(ClientArrayType::COLOR_ARRAY);

	GLState::disable(EnableModel::TEXTURE_2D);
}

void render::CtrlFrame::drawSampleWithBufferObject()
{
	if (_texFrame->getTexture() == nullptr)
	{
		return;
	}

	int textID = _texFrame->getTexture()->getTextureID();
	if (textID == 0)
	{
		return;
	}

	GLState::enable(EnableModel::TEXTURE_2D);
	GLTexture::bindTexture2D(textID);
	GLDebug::showError();

	_vertexArrayObject->bindVertexArray();
	_vertexArrayObject->bindBuffer();
	GLDebug::showError();
	
	VertexAttribPointer* pointer0 = _vertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::POSITION);
	VertexAttribPointer* pointer1 = _vertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::COLOR);
	VertexAttribPointer* pointer2 = _vertexArrayObject->getVertexAttrib<VertexAttribPointer>((uint32_t)VertexAttribType::UV);

	pointer0->enableVertexArrayAttrib();
	pointer1->enableVertexArrayAttrib();
	pointer2->enableVertexArrayAttrib();

	uint32_t nVerticeSize = sizeof(_texRect.vertices);
	uint32_t nColorSize = sizeof(_texRect.colors);
	uint32_t nUVSize = sizeof(_texRect.uvs);
	
	pointer0->setVertexAttribPointer(3, VertexAttribPointerType::FLOAT, 0);
	GLDebug::showError();
	
	pointer1->setVertexAttribPointer(4, VertexAttribPointerType::FLOAT, nVerticeSize);
	GLDebug::showError();
	
	pointer2->setVertexAttribPointer(2, VertexAttribPointerType::FLOAT, nVerticeSize + nColorSize);
	GLDebug::showError();
	

	if (getProgram())
	{
		getProgram()->use();
	}
	else
	{
		ShaderProgram::useNone();
	}

	GLDebug::showError();
	uint32_t nIndiceSize = sizeof(_texRect.indices);
	uint32_t nIndiceLength = nIndiceSize / sizeof(float);

	_indiceObject->bindBuffer();
	GLBufferObjects::drawElements(DrawMode::TRIANGLES, nIndiceLength, IndexDataType::UNSIGNED_INT, (void*)0);

	GLDebug::showError();
	pointer0->disableVertexArrayAttrib();
	pointer1->disableVertexArrayAttrib();
	pointer2->disableVertexArrayAttrib();

	GLState::disable(EnableModel::TEXTURE_2D);

	GLDebug::showError();
}