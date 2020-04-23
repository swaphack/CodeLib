#include "GLTexture.h"
#include "macros.h"
using namespace render;

uint32_t GLTexture::genTexture()
{
	uint32_t textureID = 0;
	genTextures(1, &textureID);
	return textureID;
}

void GLTexture::genTextures(int count, uint32_t* textureIDs)
{
	glGenTextures(count, textureIDs);
}

void GLTexture::deleteTexture(uint32_t textureID)
{
	deleteTextures(1, &textureID);
}

void GLTexture::deleteTextures(int count, uint32_t* textureIDs)
{
	glDeleteTextures(count, textureIDs);
}

void GLTexture::bindTexture(TextureTarget type, uint32_t textureID)
{
	glBindTexture((GLenum)type, textureID);
}

void GLTexture::bindTexture1D(uint32_t textureID)
{
	bindTexture(TextureTarget::TEXTURE_1D, textureID);
}

void GLTexture::bindTexture2D(uint32_t textureID)
{
	bindTexture(TextureTarget::TEXTURE_2D, textureID);
}

void GLTexture::setTexParameter(TextureTarget type, TextureParameterName paramType, int paramValue)
{
	glTexParameteri((GLenum)type, (GLenum)paramType, paramValue);
}

void GLTexture::setTexParameterMinFilter2D(TextureMinFilter paramValue)
{
	setTexParameter(TextureTarget::TEXTURE_2D, TextureParameterName::TEXTURE_MIN_FILTER, (int)paramValue);
}

void GLTexture::setTexParameterMagFilter2D(TextureMagFilter paramValue)
{
	setTexParameter(TextureTarget::TEXTURE_2D, TextureParameterName::TEXTURE_MAG_FILTER, (int)paramValue);
}

void GLTexture::setTexParameterWrapS2D(TextureWrapMode paramValue)
{
	setTexParameter(TextureTarget::TEXTURE_2D, TextureParameterName::TEXTURE_WRAP_S, (int)paramValue);
}

void GLTexture::setTexParameterWrapT2D(TextureWrapMode paramValue)
{
	setTexParameter(TextureTarget::TEXTURE_2D, TextureParameterName::TEXTURE_WRAP_T, (int)paramValue);
}

void GLTexture::setTexParameterBorderColor2D(const sys::Color4F& color)
{
	float c[4] = { 0 };
	c[0] = color.red;
	c[1] = color.green;
	c[2] = color.blue;
	c[3] = color.alpha;

	glTexParameterfv((GLenum)TextureTarget::TEXTURE_2D, (GLenum)TextureParameterName::TEXTURE_BORDER_COLOR, c);
}

void GLTexture::setTexParameterPriority2D(float priority)
{
	glTexParameterf((GLenum)TextureTarget::TEXTURE_2D, (GLenum)TextureParameterName::TEXTURE_PRIORITY, priority);
}

void GLTexture::setTexGenMode(TextureCoordName name, TextureGenParameter paramType)
{
	glTexGeni((GLenum)name, (GLenum)TextureGenParameter::TEXTURE_GEN_MODE, (int)paramType);
}

void GLTexture::setTexGenObjectPlane(TextureCoordName name, const float* value)
{
	glTexGenfv((GLenum)name, (GLenum)TextureGenParameter::OBJECT_PLANE, value);
}

void GLTexture::setTexGenEyePlane(TextureCoordName name, const float* value)
{
	glTexGenfv((GLenum)name, (GLenum)TextureGenParameter::EYE_PLANE, value);
}

void GLTexture::setTexImage1D(int nLevel, TextureParameter internalFormat, int width, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data)
{
	glTexImage1D((GLenum)TextureTarget::TEXTURE_1D, nLevel, (GLint)internalFormat, width, border, (GLint)pixelFormat, (GLint)pixelType, data);
}

void GLTexture::setTexImage2D(int nLevel, TextureParameter internalFormat, int width, int heigth, int border, PixelFormat pixelFormat, PixelType pixelType, const void* data)
{
	glTexImage2D((GLenum)TextureTarget::TEXTURE_2D, nLevel, (GLint)internalFormat, width, heigth, border, (GLint)pixelFormat, (GLint)pixelType, data);
}

void GLTexture::setTexEnvModel(TextureEnvMode value)
{
	glTexGeni((GLenum)TextureEnvTarget::TEXTURE_ENV, (GLenum)TextureEnvParameter::TEXTURE_ENV_MODE, (int)value);
}

void GLTexture::setTexEnvColor(const sys::Color4F& value)
{
	float c[4] = { 0 };
	c[0] = value.red;
	c[1] = value.green;
	c[2] = value.blue;
	c[3] = value.alpha;
	glTexGenfv((GLenum)TextureEnvTarget::TEXTURE_ENV, (GLenum)TextureEnvParameter::TEXTURE_ENV_MODE, c);
}

bool GLTexture::isTexture(uint32_t textureID)
{
	return glIsTexture(textureID) != 0;
}

void GLTexture::setPrioritizeTextures(int size, const uint32_t* textureIDs, const float* priorities)
{
	glPrioritizeTextures(size, textureIDs, priorities);
}

void GLTexture::setTexSubImage1D(int nLevel, int xOffset, int width, PixelFormat pixelFormat, PixelType pixelType, const void* data)
{
	glTexSubImage1D((GLenum)TextureTarget::TEXTURE_1D, nLevel, xOffset, width, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLTexture::setTexSubImage2D(int nLevel, int xOffset, int yOffset, int width, int height, PixelFormat pixelFormat, PixelType pixelType, const void* data)
{
	glTexSubImage2D((GLenum)TextureTarget::TEXTURE_2D, nLevel, xOffset, yOffset, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

bool GLTexture::isTexturesResident(int n, const uint32_t* textures, bool* residences)
{
	uint8_t* data = (uint8_t*)malloc(n);
	memset(data, 0, n);
	int ret = glAreTexturesResident(n, textures, data);
	for (int i = 0; i < n; i++)
	{
		residences[i] = data[i] == 1;
	}

	free(data);

	return ret == 1;
}

bool GLTexture::isTextureResident(uint32_t texture)
{
	uint8_t data = 0;

	int ret = glAreTexturesResident(1, &texture, &data);
	return ret == 1;
}

void GLTexture::activeClientTexture(ActiveTextureName texture)
{
	glClientActiveTexture((GLenum)texture);
}

void GLTexture::activeTexture(ActiveTextureName texture)
{
	glActiveTexture((GLenum)texture);
}

void GLTexture::setPixelTransfer(PixelTransfer name, float value)
{
	glPixelTransferf((GLenum)name, value);
}

void GLTexture::setPixelMap(PixelMap name, int size, const float* value)
{
	glPixelMapfv((GLenum)name, size, value);
}