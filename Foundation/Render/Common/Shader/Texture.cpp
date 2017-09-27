#include "Texture.h"
#include <exception>
#include "ext-config.h"
#include "Resource/Component/Image.h"
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
	glDeleteTextures(1, &_textureID);
	_textureID = 0;
}

//////////////////////////////////////////////////////////////////////////
void Texture2D::load(const Image* image)
{
	if (image == nullptr || image->getPixels() == nullptr)
	{
		return;
	}

	GLuint tex_id = 0;

	/* Generate texture */
	glGenTextures(1, &tex_id);
	glBindTexture(GL_TEXTURE_2D, tex_id);

	/* Setup some parameters for texture filters and mipmapping */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	
	glTexImage2D(GL_TEXTURE_2D, 0, image->getInternalFormat(),
		image->getWidth(), image->getHeight(), 0, image->getFormat(),
		GL_UNSIGNED_BYTE, image->getPixels());
	
	_textureID = tex_id;
	_width = image->getWidth();
	_height = image->getHeight();
}
