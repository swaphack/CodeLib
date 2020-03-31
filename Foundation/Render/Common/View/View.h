#pragma once

#include "system.h"
#include "Common/struct/import.h"
#include "ViewConfig.h"

namespace render
{
	// opengl 视图
	class View : public DirtyProtocol
	{
	public:
		View();
		virtual ~View();
	public:
		const ViewConfig* getConfig();
		// 设置视窗位置
		void setPosition(float x, float y);
		// 获取视窗位置
		const math::Vector2& getPosition();
		// 设置视窗大小
		void setFrameSize(float width, float height);
		// 获取视窗大小
		const math::Size& getFrameSize();
		// 重置视图
		void initView();
		// 更新视图
		virtual void updateView();
	protected:
		// 应用设置
		void applyConfig();
	protected:
		// 视窗位置
		math::Vector2 _position;
		// 视窗大小
		math::Size _size;
		// 视图配置
		ViewConfig _viewConfig;
	};
}