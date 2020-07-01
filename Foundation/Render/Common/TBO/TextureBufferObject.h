#pragma once

#include "Common/Buffer/BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Texture;
	class NoNamedBuffer;

	/**
	*	纹理缓存对象
	*/
	class TextureBufferObject : public sys::Object
	{
	public:
		TextureBufferObject();
		virtual ~TextureBufferObject();
	public:
		/**
		*	设置纹理
		*/
		void setTexture(Texture* texture);
		/**
		*	获取纹理
		*/
		Texture* getTexture() const;
		/**
		*	设置纹理缓存
		*/
		void setTextureBuffer(NoNamedBuffer* buffer);
		/**
		*	获取纹理缓存
		*/
		NoNamedBuffer* getTextureBuffer() const;
		/**
		*	设置纹理缓存格式
		*/
		void setTexBufferFromat(TexSizedInternalFormat internalFormat);
	public:
		/**
		*	绑定纹理
		*/
		void bindTexture();
		/**
		*	解除纹理绑定
		*/
		void unbindTexture();
		/**
		*	绑定纹理缓存
		*/
		void bindTextureBuffer();
		/**
		*	解除纹理缓存绑定
		*/
		void unbindTextureBuffer();
	protected:
		void initTBO();
		void releaseTBO();
	private:
		/**
		*	纹理
		*/
		Texture* _texture = nullptr;
		/**
		*	纹理缓存
		*/
		NoNamedBuffer* _textureBuffer = nullptr;
	};
}
