#pragma once

#include "system.h"

namespace render
{
	// opengl 视图
	class View : public sys::DirtyProtocol
	{
	public:
		View();
		virtual ~View();
	public:
		// 设置视窗位置
		void setPosition(float x, float y);
		// 获取视窗位置
		const math::Vector2& getPosition();
		// 设置视窗大小
		void setFrameSize(float width, float height);
		// 获取视窗大小
		const math::Size& getFrameSize();
	public:
		// 重置视图
		void initViewPort();
		// 应用设置
		void applyConfig();
		// 更新视图
		virtual void updateView();
	protected:
		// 视窗位置
		math::Vector2 _position;
		// 视窗大小
		math::Size _size;
	};
}