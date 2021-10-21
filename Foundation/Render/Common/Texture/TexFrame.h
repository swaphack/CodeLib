#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class Texture;
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
		// 设置名称
		void setName(const std::string& name);
		// 获取名称
		const std::string& getName() const;
		// 设置纹理显示区域
		void setRect(const math::Rect& rect);
		// 获取纹理显示区域
		const math::Rect& getRect() const;
		// 是否旋转
		void setRotate(bool bRotated);
		// 是否旋转
		bool isRotated() const;
	public:
		// 是否纹理大小
		math::Size getFrameSize() const;
		// 获取纹理位置
		math::Vector2 getFramePosition() const;
	public:
		// 设置纹理和显示区域
		void loadTexture(const Texture* texture, const math::Rect& rect);
		// 设置纹理和显示区域,默认显示区域为全部
		void loadTexture(const Texture* texture);
	public:
		TexFrame& operator=(const TexFrame& value);
	private:
		// 纹理对象
		Texture* _texture = nullptr;
		// 名称
		std::string _name;
		// 显示区域
		math::Rect _rect;
		// 是否旋转
		bool _rotate = false;
	};
}