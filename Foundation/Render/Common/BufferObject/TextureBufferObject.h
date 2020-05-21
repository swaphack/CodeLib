#pragma once

#include "BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Buffer;
	class Texture;

	/**
	*	纹理缓存对象
	*/
	class TextureBufferObject : public BufferObject
	{
	public:
		TextureBufferObject();
		virtual ~TextureBufferObject();
	public:
		/**
		*	纹理
		*/
		void setTexture(Texture* texture);
		/**
		*	纹理
		*/
		Texture* getTexture() const;
		
		void bindTexture();
	public:
		/**
		*	设置纹理数据格式
		*/
		void setFormat(TexSizedInternalFormat format);
		/**
		*	绑定
		*/
		void bindTextureUnit(int32_t index);
		/**
		*	绑定
		*/
		void bindBuffer();
	protected:
		/**
		*	生成tbo
		*/
		void initTBO();
		/**
		*	释放tbo
		*/
		void relaseTBO();
	private:
		/**
		*	纹理
		*/
		Texture* _texture = nullptr;

	};
}