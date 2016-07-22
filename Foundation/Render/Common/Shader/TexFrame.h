#pragma once

#include "system.h"
#include "Texture.h"

namespace render
{
	// 帧纹理，显示区域从左下角开始
	class TexFrame : public sys::Object
	{
	public:
		TexFrame();
		virtual ~TexFrame();
	public:
		// 设置纹理
		void setTexture(const Texture* texture);
		// 获取纹理对象
		const Texture* getTexture() const;
		// 设置纹理显示区域
		void setRect(const sys::Rect& rect);
		// 获取纹理显示区域
		const sys::Rect& getRect() const;
		// 设置纹理和显示区域
		void setTextureWithRect(const Texture* texture, const sys::Rect& rect);
		// 设置纹理和显示区域,默认显示区域为全部
		void setTextureWithRect(const Texture* texture);

		TexFrame& operator=(const TexFrame& value);
	private:
		// 纹理对象
		Texture* _texture;
		// 显示区域
		sys::Rect _rect;
	};
}