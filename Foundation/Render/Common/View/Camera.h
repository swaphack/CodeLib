#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// 摄像机
	class Camera : public sys::Object,
		public DirtyProtocol,
		public SpaceProtocol,
		public BodyProtocol
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		virtual void updateCamera();
		// 相机对准指定位置
		virtual void lookAt(const sys::Vector3& position);
	protected:
		virtual void onSpaceChange();
	protected:
		// 摄像机位置
		//sys::Vector _position;
		// 摄像机旋转角度
		//sys::Vector _rotation;
		// 摄像机焦距
		//sys::Vector _scale;
		// opengl 位置
		sys::Vector3 _obPosition;
	};
	// 2d 摄像头
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	public:
		// 绘制视图
		virtual void updateCamera();
	};
	// 3d 摄像头
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
		// 绘制视图
		virtual void updateCamera();
	};
}