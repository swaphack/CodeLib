#include "TextureBufferObject.h"
#include "Graphic/import.h"
#include "Common/Buffer/BufferObject.h"

using namespace render;

render::TextureBufferObject::TextureBufferObject()
{
	this->initTBO();
}

render::TextureBufferObject::~TextureBufferObject()
{
	this->relaseTBO();

	SAFE_RELEASE(_bufferObject);
}

uint32_t render::TextureBufferObject::getTBOID() const
{
	return _tboID;
}

void render::TextureBufferObject::setBufferObject(BufferObject* buffer)
{
	SAFE_RELEASE(_bufferObject);
	SAFE_RETAIN(buffer);
	_bufferObject = buffer;
}

render::BufferObject* render::TextureBufferObject::getBufferObject()
{
	return _bufferObject;
}

void render::TextureBufferObject::bindTextureUnit(int32_t index)
{
	GLTexture::bindTextureUnit(index, _tboID);
}

void render::TextureBufferObject::setFormat(TexSizedInternalFormat format)
{
	if (_bufferObject == nullptr)
	{
		return;
	}
	GLTexture::setTexBuffer(format, _bufferObject->getBufferID());
}

void render::TextureBufferObject::initTBO()
{
	_tboID = GLTexture::genTexture();
}

void render::TextureBufferObject::relaseTBO()
{
	GLTexture::deleteTexture(_tboID);
}

