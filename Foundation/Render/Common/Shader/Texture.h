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
		uint32_t getTextureID() const
		{ 
			return _textureID; 
		}

		inline int getWidth() const
		{
			return _width;
		}
		inline void setWidth(uint32_t val)
		{
			_width = val;
		}
		inline uint32_t getHeight() const
		{
			return _height;
		}
		inline void setHeight(uint32_t val)
		{
			_height = val;
		}
		inline uint32_t getDeep() const
		{
			return _deep;
		}
		inline void setDeep(uint32_t val)
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
		uint32_t _textureID;
		uint32_t _width;
		uint32_t _height;
		uint32_t _deep;
	};

	//////////////////////////////////////////////////////////////////////////

	class ImageDetail;

	// 2dÎÆÀí
	class Texture2D : public Texture
	{
	public:
		virtual void load(const ImageDetail* image);
	protected:
	private:
	};
}