#pragma once

#include "system.h"

namespace render
{
	// ÎÆÀí»ù´¡
	class Texture : public sys::Object
	{
	public:
		Texture();
		virtual ~Texture();
	public:
		uint32 getTextureID() const
		{ 
			return _textureID; 
		}

		inline int getWidth() const
		{
			return _width;
		}
		inline void setWidth(uint32 val)
		{
			_width = val;
		}
		inline uint32 getHeight() const
		{
			return _height;
		}
		inline void setHeight(uint32 val)
		{
			_height = val;
		}
		inline uint32 getDeep() const
		{
			return _deep;
		}
		inline void setDeep(uint32 val)
		{
			_deep = val;
		}

		bool isEnable()
		{
			if (_textureID == 0)
				return false;
			if (_width == 0 || _height == 0) 
				return false;
			return true;
		}
	protected:
		uint32 _textureID;
		uint32 _width;
		uint32 _height;
		uint32 _deep;
	};

	//////////////////////////////////////////////////////////////////////////

	class Image;

	// 2dÎÆÀí
	class Texture2D : public Texture
	{
	public:
		virtual void load(const Image* image);
	protected:
	private:
	};
}