#pragma once

#include "system.h"
#include "ViewConfig.h"
#include "Camera.h"
#include "../GL/import.h"

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
		const sys::Point& getPosition();
		// 设置视窗大小
		void setFrameSize(float width, float height);
		// 获取视窗大小
		const sys::Size& getFrameSize();
		// 设置摄像机
		void setCamera(Camera* camera);
		// 获取摄像机
		Camera* getCamera();
		// 重置视图
		void initView();
		// 更新视图
		virtual void updateView();
	protected:
		// 视窗位置
		sys::Point _position;
		// 视窗大小
		sys::Size _size;
		// 视图配置
		ViewConfig _viewConfig;
		// 摄像机
		Camera* _camera;
	};
}