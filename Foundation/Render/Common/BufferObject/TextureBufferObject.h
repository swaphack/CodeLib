#pragma once

#include "BufferObject.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class Buffer;

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
		*	纹理编号
		*/
		uint32_t getTextureID() const;
		/**
		*	绑定
		*/
		void bindBuffer();
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
		*	绑定纹理
		*/
		void bindTexture(TextureTarget target);
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
		*	纹理编号
		*/
		uint32_t _textureID = 0;
	};
}