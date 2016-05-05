#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// 摄像机
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		void setPosition(float px, float py, float pz);
		const sys::Vector& getPosition();

		void setRotation(float rx, float ry, float rz);
		const sys::Vector& getRotation();

		void setScale(float sx, float sy, float sz);
		const sys::Vector& getScale();

		virtual void updateCamera();
	protected:
		// 摄像机位置
		sys::Vector _position;
		// 摄像机旋转角度
		sys::Vector _rotation;
		// 摄像机焦距
		sys::Vector _scale;
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