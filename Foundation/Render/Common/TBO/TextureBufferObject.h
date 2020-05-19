#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class BufferObject;

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
		*	顶点数组编号
		*/
		uint32_t getTBOID() const;
	public:
		/**
		*	绑定buffer
		*/
		void setBufferObject(BufferObject* buffer);
		/**
		*	绑定buffer
		*/
		BufferObject* getBufferObject();
	public:
		/**
		*	绑定
		*/
		void setFormat(TexSizedInternalFormat format);
		/**
		*	绑定
		*/
		void bindTextureUnit(int32_t index);
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
		*	编号
		*/
		uint32_t _tboID = 0;
		/**
		*	绑定buffer
		*/
		BufferObject* _bufferObject = nullptr;
	};
}