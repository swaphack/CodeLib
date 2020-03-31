#include "Texture.h"
#include <exception>
#include "Graphic/GLAPI/GLTexture.h"
#include "Resource/Detail/ImageDetail.h"
using namespace render;


Texture::Texture()
:_textureID(0)
,_width(0)
,_height(0)
,_deep(0)
{
}

Texture::~Texture()
{
	GLTexture::deleteTexture(_textureID);
	_textureID = 0;
}

//////////////////////////////////////////////////////////////////////////
void Texture2D::load(const ImageDetail* image)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}

	GLuint tex_id = GLTexture::genTexture();

	/* Generate texture */
	GLTexture::bindTexture2D(tex_id);

	/* Setup some parameters for texture filters and mipmapping */
	GLTexture::setTexParameterMinFilter2D(TextureMinFilter::LINEAR);
	GLTexture::setTexParameterMagFilter2D(TextureMagFilter::LINEAR);
	GLTexture::setTexParameterWrapS2D(TextureWrapMode::CLAMP);
	GLTexture::setTexParameterWrapT2D(TextureWrapMode::CLAMP);

	GLTexture::setTexImage2D(0, image->getInternalFormat(),
		image->getWidth(), image->getHeight(), 0, image->getFormat(),
		PixelType::UNSIGNED_BYTE, image->getPixels());
	
	_textureID = tex_id;
	_width = image->getWidth();
	_height = image->getHeight();
}
