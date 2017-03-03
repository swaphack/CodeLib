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
		const sys::Vector2& getPosition();
		// 设置视窗大小
		void setFrameSize(float width, float height);
		// 获取视窗大小
		const sys::Size& getFrameSize();
		// 设置摄像机
		void setCamera(Camera* camera);
		// 获取摄像机
		Camera* getCamera();
		// 设置缩放比
		void setScale(float x, float y, float z);
		// 获取缩放比
		sys::Vector3 getScale();
		// 重置视图
		void initView();
		// 更新视图
		virtual void updateView();
	protected:
		// 视窗位置
		sys::Vector2 _position;
		// 视窗大小
		sys::Size _size;
		// 视图配置
		ViewConfig _viewConfig;
		// 摄像机
		Camera* _camera;
		// 设置缩放比
		sys::Vector3 _scale;
	};
}