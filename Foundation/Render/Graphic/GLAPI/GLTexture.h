#pragma once

#include <cstdint>

#include "macros.h"

namespace render
{
	/**
	*	Œ∆¿Ì
	*/
	class GLTexture
	{
	public:
		static void activeTexture(ActiveTextureName texture);
		static void bindImageTexture(uint32_t unit, uint32_t texture, int level, bool layered, int layer, AccessType access, InternalImageFormat format);
		static void bindImageTextures(uint32_t first, int count, const uint32_t *textures);
	public:
		static void bindTexture(TextureTarget type, uint32_t texture);
		static void bindTexture1D(uint32_t texture);
		static void bindTexture2D(uint32_t texture);

		static void bindTextureUnit(uint32_t unit, uint32_t texture);
		static void bindTextures(uint32_t first, int count, const uint32_t *textures);
	public:
		static void clearTexImage(uint32_t texture, int level, TexImageDataFormat format, TexImageDataType type, const void* data);
		static void clearTexSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TexImageDataFormat format, TexImageDataType type, const void* data);
	public:
		static void compressedTexImage1D(CompressedTexImageTarget1D target, int level, CompressedInternalFormat internalFormat, int width, int imageSize, const void* data);
		static void compressedTexImage2D(CompressedTexImageTarget2D target, int level, CompressedInternalFormat internalFormat, int width, int height, int imageSize, const void* data);
		static void compressedTexImage3D(CompressedTexImageTarget3D target, int level, CompressedInternalFormat internalFormat, int width, int height, int depth, int imageSize, const void* data);

		static void compressedTexSubImage1D(TextureSubImageTarget1D target, int level, int xoffset, int width, int imageSize, const void* data);
		static void compressedTextureSubImage1D(uint32_t texture, int level, int xoffset, int width, int imageSize, const void* data);
		static void compressedTexSubImage2D(CompressedTexSubImageTarget2D target, int level, int xoffset, int yoffset, int width, int height, int imageSize, const void* data);
		static void compressedTextureSubImage2D(uint32_t texture, int level, int xoffset, int yoffset, int width, int height, int imageSize, const void* data);
		static void compressedTexSubImage3D(CompressedTexSubImageTarget3D target, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int imageSize, const void* data);
		static void compressedTextureSubImage3D(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int imageSize, const void* data);
	public:
		static void copyImageSubData(uint32_t srcName, GLenum srcTarget, int srcLevel, int srcX, int srcY, int srcZ,
			uint32_t destName, GLenum destTarget, int destLevel, int destX, int destY, int destZ,
			int srcWidth, int srcHeight, int srcDepth);

		static void copyTexImage1D(CopyTexImageTarget1D target, int level, CopyInternalFormat internalFormat, int x, int y, int width, int border);
		static void copyTexImage2D(CopyTexImageTarget2D target, int level, CopyInternalFormat internalFormat, int x, int y, int width, int height, int border);

		static void copyTexSubImage1D(CopyTexImageTarget1D target, int level, int xoffset, int x, int y, int width);
		static void copyTextureSubImage1D(uint32_t texture, int level, int xoffset, int x, int y, int width);

		static void copyTexSubImage2D(CopyTexImageTarget2D target, int level, int xoffset, int yoffset, int x, int y, int width, int height);
		static void copyTextureSubImage2D(uint32_t texture, int level, int xoffset, int yoffset, int x, int y, int width, int height);

		static void copyTexSubImage3D(CopyTexImageTarget3D target, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
		static void copyTextureSubImage3D(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int x, int y, int width, int height);
	public:
		static void createTexures(TextureTarget target, int n, uint32_t* textures);
	public:
		static uint32_t genTexture();
		static void genTextures(int count, uint32_t* textures);
		static void deleteTexture(uint32_t texture);
		static void deleteTextures(int count, uint32_t* textures);
	public:
		static void getCompressedTexImage(GetCompressedTexImageTarget target, int level, void* pixels);
		static void getCompressedTexImage(GetCompressedTexImageTarget target, int level, int bufSize, void* pixels);
		static void getCompressedTextureImage(uint32_t texture, int level, int bufSize, void* pixels);
		static void getCompressedTextureSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, int bufSize, void* pixels);
	public:
		static void getTexImage(TextureTarget target, int level, TexImageDataFormat format, TexImageDataType type, void* pixels);
		static void getTexImage(TextureTarget target, int level, TexImageDataFormat format, TexImageDataType type, int bufSize, void* pixels);
		static void getTextureImage(uint32_t texture, int level, TexImageDataFormat format, TexImageDataType type, int bufSize, void* pixels);
	public:
		static void getTexLevelParameter(GetTexLevelTarget target, int level, GetTexLevelParameterName name, float* params);
		static void getTexureLevelParameter(uint32_t texture, int level, GetTexLevelParameterName name, float* params);
	public:
		static void getTexParameter(TextureTarget target, GetTexParameterName name, float* params);
		static void getTexureParameter(uint32_t texture, GetTexParameterName name, float* params);
	public:
		static void getTextureSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth, TextureSubImageFormat format, TexImageDataType type, int bufSize, void* pixels);
	public:
		static void invalidateTexImage(uint32_t texture, int level);
		static void invalidateTexSubImage(uint32_t texture, int level, int xoffset, int yoffset, int zoffset, int width, int height, int depth);
	public:
		static bool isTexture(uint32_t texture);
	public:
		static void setTexBuffer(SizedInternalFormat format, uint32_t buff);
		static void setTextureBuffer(uint32_t texture, SizedInternalFormat format, uint32_t buff);

		static void setTexBufferRange(SizedInternalFormat format, uint32_t buff, GLintptr offset, GLsizeiptr size);
		static void setTextureBufferRange(uint32_t texture, SizedInternalFormat format, uint32_t buff, GLintptr offset, GLsizeiptr size);
	public:
		static void setTexImage1D(TexImageTarget1D target, int level, TexImageInternalFormat internalFormat, int width, int border, TexImageDataFormat format, TexImageDataType type, const void* data);
		static void setTexImage2D(TexImageTarget2D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int border, TexImageDataFormat format, TexImageDataType type, const void* data);
		static void setTexImage3D(TexImageTarget3D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int depth, int border, TexImageDataFormat format, TexImageDataType type, const void* data);

		static void setTexImage2DMultisample(TexImage2DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, bool fixedsamplelocations);
		static void setTexImage3DMultisample(TexImage3DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, int depth, bool fixedsamplelocations);
	public:
		static void setTexParameter(TextureTarget target, TextureParameterName paramType, int paramValue);
		static void setTexParameter(TextureTarget target, TextureParameterName paramType, const float* paramValue);

		static void setTexParameterMinFilter2D(TextureMinFilter paramValue);
		static void setTexParameterMagFilter2D(TextureMagFilter paramValue);
		static void setTexParameterWrapS2D(TextureWrapMode paramValue);
		static void setTexParameterWrapT2D(TextureWrapMode paramValue);
	public:
		static void setTexStorage1D(TexImageTarget1D target, int level, TexImageInternalFormat internalFormat, int width);
		static void setTexStorage2D(TexImageTarget2D target, int level, TexImageInternalFormat internalFormat, int width, int heigth);
		static void setTexStorage3D(TexImageTarget3D target, int level, TexImageInternalFormat internalFormat, int width, int heigth, int depth);

		static void setTexStorage2DMultisample(TexImage2DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, bool fixedsamplelocations);
		static void setTexStorage3DMultisample(TexImage3DMultisampleTarget target, int samples, GLenum internalformat, int width, int heigth, int depth, bool fixedsamplelocations);
	public:
		static void setTexGenMode(TextureCoordName name, TextureGenParameter paramType);
		static void setTexGenObjectPlane(TextureCoordName name, const float* value);
		static void setTexGenEyePlane(TextureCoordName name, const float* value);
	public:
		static void setTexEnvModel(TextureEnvMode value);
		static void setTexEnvColor(const sys::Color4F& value);
	
		static void setPrioritizeTextures(int size, const uint32_t* textures, const float* priorities);
	public:
		static void setTexSubImage1D(TexSubImageTarget1D target, int level, int xOffset, int width, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data);
		static void setTexSubImage2D(TexSubImageTarget2D target, int level, int xOffset, int yOffset, int width, int height, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data);
		static void setTexSubImage3D(TexSubImageTarget3D target, int level, int xOffset, int yOffset, int zOffset, int width, int height, int depth, TextureSubImageFormat pixelFormat, TexImageDataType pixelType, const void* data);
	public:
		static void setTextureView(uint32_t texture, TextureViewCompatibleNewTarget target, uint32_t origtexture, TextureViewFormat internalFormat,
			uint32_t minlevel, uint32_t numlevels, uint32_t minlayer, uint32_t numlayers);
	public: 
		static bool isTexturesResident(int n, const uint32_t* textures, bool* residences);
		static bool isTextureResident(uint32_t texture);
	public: 
		static void activeClientTexture(ActiveTextureName texture);
		
		static void setPixelTransfer(PixelTransfer name, float value);
		static void setPixelMap(PixelMap name, int size, const float* value);
	};
}