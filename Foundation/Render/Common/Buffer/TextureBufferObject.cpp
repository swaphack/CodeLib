#include "TextureBufferObject.h"
#include "Graphic/import.h"
#include "BufferObject.h"

using namespace render;

render::TextureBufferObject::TextureBufferObject()
{
	this->initTBO();
}

render::TextureBufferObject::~TextureBufferObject()
{
	this->relaseTBO();

	SAFE_RELEASE(_bufferObj);
}

uint32_t render::TextureBufferObject::getTBOID() const
{
	return _tboID;
}

void render::TextureBufferObject::setBufferObject(BufferObject* buffer)
{
	SAFE_RELEASE(_bufferObj);
	SAFE_RETAIN(buffer);
	_bufferObj = buffer;
}

render::BufferObject* render::TextureBufferObject::getBufferObject()
{
	return _bufferObj;
}

void render::TextureBufferObject::bindTBO(int32_t index)
{
	GLTexture::bindTextureUnit(index, _tboID);
}

void render::TextureBufferObject::bindTextureBufferFormat(TexSizedInternalFormat format)
{
	if (_bufferObj == nullptr)
	{
		return;
	}
	GLTexture::setTexBuffer(format, _bufferObj->getBufferID());
}

void render::TextureBufferObject::initTBO()
{
	_tboID = GLTexture::genTexture();
}

void render::TextureBufferObject::relaseTBO()
{
	GLTexture::deleteTexture(_tboID);
}

