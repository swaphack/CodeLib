#include "GLTexture.h"
using namespace render;

void GLTexture::activeTexture(ActiveTextureName texture)
{
	glActiveTexture((GLenum)texture);
}

void GLTexture::bindImageTexture(uint32_t unit, uint32_t texture, int level, bool layered, int layer, AccessType access, InternalImageFormat format)
{
	glBindImageTexture(unit, texture, level, layered ? GL_TRUE : GL_FALSE, layer, (GLenum)access, (GLenum)format);
}

void GLTexture::bindImageTextures(uint32_t first, int count, const uint32_t *textures)
{
	glBindImageTextures(first, count, textures);
}

void GLTexture::bindTexture(TextureTarget type, uint32_t texture)
{
	glBindTexture((GLenum)type, texture);
}

void GLTexture::bindTexture1D(uint32_t texture)
{
	bindTexture(TextureTarget::TEXTURE_1D, texture);
}

void GLTexture::bindTexture2D(uint32_t texture)
{
	bindTexture(TextureTarget::TEXTURE_2D, texture);
}

void GLTexture::bindTextureUnit(uint32_t unit, uint32_t texture)
{
	glBindTextureUnit(unit, texture);
}

uint32_t GLTexture::genTexture()
{
	uint32_t texture = 0;
	genTextures(1, &texture);
	return texture;
}

void GLTexture::genTextures(int count, uint32_t* textures)
{
	glGenTextures(count, textures);
}

void GLTexture::deleteTexture(uint32_t texture)
{
	deleteTextures(1, &texture);
}

void GLTexture::deleteTextures(int count, uint32_t* textures)
{
	glDeleteTextures(count, textures);
}

void GLTexture::setTexParameter(TextureTarget target, TextureParameterName paramType, int paramValue)
{
	glTexParameteri((GLenum)target, (GLenum)paramType, paramValue);
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

bool GLTexture::isTexture(uint32_t texture)
{
	return glIsTexture(texture) != 0;
}

void GLTexture::setPrioritizeTextures(int size, const uint32_t* textures, const float* priorities)
{
	glPrioritizeTextures(size, textures, priorities);
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

void GLTexture::setPixelTransfer(PixelTransfer name, float value)
{
	glPixelTransferf((GLenum)name, value);
}

void GLTexture::setPixelMap(PixelMap name, int size, const float* value)
{
	glPixelMapfv((GLenum)name, size, value);
}

void GLTexture::bindTextures(uint32_t first, int count, const uint32_t *textures)
{
	glBindTextures(first, count, textures);
}

void GLTexture::clearTexImage(uint32_t texture, int level, TexImageDataFormat format, TexImageDataType type, const void* data)
{
	glClearTexImage(texture, level, (GLenum)format, (GLenum)type, data);
}

void GLTexture::clearTexSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TexImageDataFormat format, TexImageDataType type, const void* data)
{
	glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, data);
}

void GLTexture::compressedTexImage1D(CompressedTexImageTarget1D target, int level, CompressedInternalFormat internalFormat, int width, int imageSize, const void* data)
{
	glCompressedTexImage1D((GLenum)target, level, (GLenum)internalFormat, width, 0, imageSize, data);
}

void GLTexture::compressedTexImage2D(CompressedTexImageTarget2D target, int level, CompressedInternalFormat internalFormat, int width, int height, int imageSize, const void* data)
{
	glCompressedTexImage2D((GLenum)target, level, (GLenum)internalFormat, width, height, 0, imageSize, data);
}

void GLTexture::compressedTexImage3D(CompressedTexImageTarget3D target, int level, CompressedInternalFormat internalFormat, int width, int height, int depth, int imageSize, const void* data)
{
	glCompressedTexImage3D((GLenum)target, level, (GLenum)internalFormat, width, height, depth, 0, imageSize, data);
}

void GLTexture::compressedTexSubImage1D(TextureSubImageTarget1D target, int level, int xoffset, int width, int imageSize, const void* data)
{
	glCompressedTexSubImage1D((GLenum)target, level, xoffset, width, 0, imageSize, data);
}

void GLTexture::compressedTextureSubImage1D(uint32_t texture, int level, int xoffset, int width, int imageSize, const void* data)
{
	glCompressedTextureSubImage1D(texture, level, xoffset, width, 0, imageSize, data);
}

void GLTexture::compressedTexSubImage2D(CompressedTexSubImageTarget2D target, int level, int xoffset, int yoffset, int width, int height, int imageSize, const void* data)
{
	glCompressedTexSubImage2D((GLenum)target, level, xoffset, yoffset, width, height, 0, imageSize, data);
}

void GLTexture::compressedTextureSubImage2D(uint32_t texture, int level, int xoffset, int yoffset, int width, int height, int imageSize, const void* data)
{
	glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, 0, imageSize, data);
}

void GLTexture::compressedTexSubImage3D(CompressedTexSubImageTarget3D target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int imageSize, const void* data)
{
	glCompressedTexSubImage3D((GLenum)target, level, xoffset, yoffset, zoffset, width, height, depth, 0, imageSize, data);
}

void GLTexture::compressedTextureSubImage3D(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int imageSize, const void* data)
{
	glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, 0, imageSize, data);
}

void GLTexture::copyImageSubData(uint32_t srcName, GLenum srcTarget, int srcLevel, int srcX, int srcY, int srcZ, uint32_t destName, GLenum destTarget, int destLevel, int destX, int destY, int destZ, int srcWidth, int srcHeight, int srcDepth)
{
	glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, destName, destTarget, destLevel, destX, destY, destZ, srcWidth, srcHeight, srcDepth);
}

void GLTexture::copyTexImage1D(CopyTexImageTarget1D target, int level, CopyInternalFormat internalFormat, int x, int y, int width, int border)
{
	glCopyTexImage1D((GLenum)target, level, (GLenum)internalFormat, x, y, width, border);
}

void GLTexture::copyTexImage2D(CopyTexImageTarget2D target, int level, CopyInternalFormat internalFormat, int x, int y, int width, int height, int border)
{
	glCopyTexImage2D((GLenum)target, level, (GLenum)internalFormat, x, y, width, height, border);
}

void GLTexture::copyTexSubImage1D(CopyTexImageTarget1D target, int level, int xoffset, int x, int y, int width)
{
	glCopyTexSubImage1D((GLenum)target, level, xoffset, x, y, width);
}

void GLTexture::copyTextureSubImage1D(uint32_t texture, int level, int xoffset, int x, int y, int width)
{
	glCopyTextureSubImage1D(texture, level, xoffset, x, y, width);
}

void GLTexture::copyTexSubImage2D(CopyTexImageTarget2D target, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	glCopyTexSubImage2D((GLenum)target, level, xoffset, yoffset, x, y, width, height);
}

void GLTexture::copyTextureSubImage2D(uint32_t texture, int level, int xoffset, int yoffset, int x, int y, int width, int height)
{
	glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height);
}

void GLTexture::copyTexSubImage3D(CopyTexImageTarget3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
{
	glCopyTexSubImage3D((GLenum)target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLTexture::copyTextureSubImage3D(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height)
{
	glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height);
}

void GLTexture::createTexures(TextureTarget target, int n, uint32_t* textures)
{
	glCreateTextures((GLenum)target, n, textures);
}

void GLTexture::getCompressedTexImage(GetCompressedTexImageTarget target, int level, void* pixels)
{
	glGetCompressedTexImage((GLenum)target, level, pixels);
}

void GLTexture::getCompressedTexImage(GetCompressedTexImageTarget target, int level, int bufSize, void* pixels)
{
	glGetnCompressedTexImage((GLenum)target, level, bufSize, pixels);
}

void GLTexture::getCompressedTextureImage(uint32_t texture, int level, int bufSize, void* pixels)
{
	glGetCompressedTextureImage(texture, level, bufSize, pixels);
}

void GLTexture::getCompressedTextureSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int bufSize, void* pixels)
{
	glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels);
}

void GLTexture::getTexImage(TextureTarget target, int level, TexImageDataFormat format, TexImageDataType type, void* pixels)
{
	glGetTexImage((GLenum)target, level, (GLenum)format, (GLenum)type, pixels);
}

void GLTexture::getTextureImage(uint32_t texture, int level, TexImageDataFormat format, TexImageDataType type, int bufSize, void* pixels)
{
	glGetTextureImage(texture, level, (GLenum)format, (GLenum)type, bufSize, pixels);
}

void GLTexture::getTexLevelParameter(GetTexLevelTarget target, int level, GetTexLevelParameterName name, float* params)
{
	glGetTexLevelParameterfv((GLenum)target, level, (GLenum)level, params);
}

void GLTexture::getTexureLevelParameter(uint32_t texture, int level, GetTexLevelParameterName name, float* params)
{
	glGetTextureLevelParameterfv(texture, level, (GLenum)level, params);
}

void GLTexture::getTexParameter(TextureTarget target, GetTexParameterName name, float* params)
{
	glGetTexParameterfv((GLenum)target, (GLenum)name, params);
}

void GLTexture::getTexureParameter(uint32_t texture, GetTexParameterName name, float* params)
{
	glGetTextureParameterfv(texture, (GLenum)name, params);
}

void GLTexture::getTextureSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureSubImageFormat format, TexImageDataType type, int bufSize, void* pixels)
{
	glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, (GLenum)format, (GLenum)type, bufSize, pixels);
}

void GLTexture::invalidateTexImage(uint32_t texture, int level)
{
	glInvalidateTexImage(texture, level);
}

void GLTexture::getTexImage(TextureTarget target, int level, TexImageDataFormat format, TexImageDataType type, int bufSize, void* pixels)
{

}

void GLTexture::invalidateTexSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth)
{
	glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
}

void GLTexture::setTexBuffer(SizedInternalFormat format, uint32_t buff)
{
	glTexBuffer(GL_TEXTURE_BUFFER, (GLenum)format, buff);
}

void GLTexture::setTextureBuffer(uint32_t texture, SizedInternalFormat format, uint32_t buff)
{
	glTextureBuffer(texture, (GLenum)format, buff);
}

void GLTexture::setTexBufferRange(SizedInternalFormat format, uint32_t buff, GLintptr offset, GLsizeiptr size)
{
	glTexBufferRange(GL_TEXTURE_BUFFER, (GLenum)format, buff, offset, size);
}

void GLTexture::setTextureBufferRange(uint32_t texture, SizedInternalFormat format, uint32_t buff, GLintptr offset, GLsizeiptr size)
{
	glTextureBufferRange(texture, (GLenum)format, buff, offset, size);
}

void GLTexture::setTexImage1D(TexImageTarget1D target, int level, TexImageInternalFormat internalFormat, int width, int border, TexImageDataFormat format, TexImageDataType type, const void* data)
{
	glTexImage1D((GLenum)target, level, (GLenum)internalFormat, width, border, (GLenum)format, (GLenum)type, data);
}

void GLTexture::setTexImage2D(TexImageTarget2D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int border, TexImageDataFormat format, TexImageDataType type, const void* data)
{
	glTexImage2D((GLenum)target, level, (GLenum)internalFormat, width, heigth, border, (GLenum)format, (GLenum)type, data);
}

void GLTexture::setTexImage3D(TexImageTarget3D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int depth, int border, TexImageDataFormat format, TexImageDataType type, const void* data)
{
	glTexImage3D((GLenum)target, level, (GLenum)internalFormat, width, heigth, depth, border, (GLenum)format, (GLenum)type, data);
}

void GLTexture::setTexImage2DMultisample(TexImage2DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, bool fixedsamplelocations)
{
	glTexImage2DMultisample((GLenum)target, samples, (GLenum)internalformat, width, heigth, fixedsamplelocations ? GL_TRUE : GL_FALSE);
}

void GLTexture::setTexImage3DMultisample(TexImage3DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, int depth, bool fixedsamplelocations)
{
	glTexImage3DMultisample((GLenum)target, samples, (GLenum)internalformat, width, heigth, depth, fixedsamplelocations ? GL_TRUE : GL_FALSE);
}

void GLTexture::setTexStorage1D(TexImageTarget1D target, int level, TexImageInternalFormat internalFormat, int width)
{
	glTexStorage1D((GLenum)target, level, (GLenum)internalFormat, width);
}

void GLTexture::setTexStorage2D(TexImageTarget2D target, int level, TexImageInternalFormat internalFormat, int width, int heigth)
{
	glTexStorage2D((GLenum)target, level, (GLenum)internalFormat, width, heigth);
}

void GLTexture::setTexStorage3D(TexImageTarget3D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int depth)
{
	glTexStorage3D((GLenum)target, level, (GLenum)internalFormat, width, heigth, depth);
}

void GLTexture::setTexStorage2DMultisample(TexImage2DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, bool fixedsamplelocations)
{
	glTexStorage2DMultisample((GLenum)target, samples, (GLenum)internalformat, width, heigth, fixedsamplelocations ? GL_TRUE : GL_FALSE);
}

void GLTexture::setTexStorage3DMultisample(TexImage3DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, int depth, bool fixedsamplelocations)
{
	glTexStorage3DMultisample((GLenum)target, samples, (GLenum)internalformat, width, heigth, depth, fixedsamplelocations ? GL_TRUE : GL_FALSE);
}

void GLTexture::setTexSubImage1D(TexSubImageTarget1D target, int level, int xOffset, int width, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data)
{
	glTexSubImage1D((GLenum)target, level, xOffset, width, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLTexture::setTexSubImage2D(TexSubImageTarget2D target, int level, int xOffset, int yOffset, int width, int height, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data)
{
	glTexSubImage2D((GLenum)target, level, xOffset, yOffset, width, height, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLTexture::setTexSubImage3D(TexSubImageTarget3D target, int level, int xOffset, int yOffset, int zOffset, int width, int height, int depth, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data)
{
	glTexSubImage3D((GLenum)target, level, xOffset, yOffset, zOffset, width, height, depth, (GLenum)pixelFormat, (GLenum)pixelType, data);
}

void GLTexture::setTextureView(uint32_t texture, TextureViewCompatibleNewTarget target, uint32_t origtexture, TextureViewFormat internalFormat, uint32_t minlevel, uint32_t numlevels, uint32_t minlayer, uint32_t numlayers)
{
	glTextureView(texture, (GLenum)target, origtexture, (GLenum)internalFormat, minlevel, numlevels, minlayer, numlayers);
}

void GLTexture::setTexParameter(TextureTarget target, TextureParameterName paramType, const float* paramValue)
{
	glTexParameterfv((GLenum)target, (GLenum)paramType, paramValue);
}

