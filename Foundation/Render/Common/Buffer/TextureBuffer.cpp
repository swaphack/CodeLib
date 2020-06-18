#include "TextureBuffer.h"
#include "Common/Texture/Texture.h"
#include "Graphic/import.h"

render::TextureBuffer::TextureBuffer()
{
	this->setBufferTarget(BufferTarget::TEXTURE_BUFFER);
}

render::TextureBuffer::~TextureBuffer()
{

}