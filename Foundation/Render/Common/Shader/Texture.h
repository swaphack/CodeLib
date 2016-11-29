#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// ÎÆÀí»ù´¡
	class Texture : public sys::Object
	{
	public:
		Texture();
		virtual ~Texture();
	public:
		uint getTextureID() const
		{ 
			return _textureID; 
		}

		inline int getWidth() const
		{
			return _width;
		}
		inline void setWidth(uint val)
		{
			_width = val;
		}
		inline uint getHeight() const
		{
			return _height;
		}
		inline void setHeight(uint val)
		{
			_height = val;
		}
		inline uint getDeep() const
		{
			return _deep;
		}
		inline void setDeep(uint val)
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
		uint _textureID;
		uint _width;
		uint _height;
		uint _deep;
	};

	//////////////////////////////////////////////////////////////////////////

	// 2dÎÆÀí
	class Texture2D : public Texture
	{
	public:
		virtual void load(const Image* image);
	protected:
	private:
	};
}