#pragma once

#include "system.h"

namespace sys
{
	class ImageDetail;
}

namespace render
{
	// �������
	class Texture : public sys::Object
	{
	public:
		Texture();
		virtual ~Texture();
	public:
		uint32_t getTextureID() const;

		int getWidth() const;
		void setWidth(uint32_t val);

		uint32_t getHeight() const;
		void setHeight(uint32_t val);

		uint32_t getDepth() const;
		void setDepth(uint32_t val);

		bool isEnable();
	protected:
		uint32_t _textureID;
		uint32_t _width;
		uint32_t _height;
		uint32_t _depth;
	};

	//////////////////////////////////////////////////////////////////////////

	// 2d����
	class Texture2D : public Texture
	{
	public:
		virtual void load(const sys::ImageDetail* image);
	protected:
	private:
	};
}