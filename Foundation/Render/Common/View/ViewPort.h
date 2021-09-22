#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	// opengl 视窗
	class ViewPort : public sys::DirtyProtocol
	{
	public:
		ViewPort();
		virtual ~ViewPort();
	public:
		// 设置视窗大小
		void setViewRect(float x, float y, float width, float height);
	public:
		// 设置子视窗
		void setSubViewRect(uint32_t index, float x, float y, float width, float height);
		// 获取子视窗
		math::Rect getSubViewRect(uint32_t index) const;
	public:
		// 重置视图
		void initViewPort();
		// 应用设置
		void applyConfig();
		// 更新视图
		virtual void updateView();
	protected:
		// 视图矩形框
		math::Rect _viewRect;
		// 子视图
		std::map<int, math::Rect> _subViewRect;
	};
}