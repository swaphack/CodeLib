#pragma once

#include "system.h"

namespace render
{
	class Camera;
	class Node;

	/**
	*	摄像机管理类
	*/
	class Cameras : public sys::Object
	{
	public:
		Cameras();
		virtual ~Cameras();
	public:
		// 3d摄像机
		Camera* getCamera3D();
		// 3d摄像机
		void setCamera3D(Camera* camera);
		// 2d摄像机
		Camera* getCamera2D();
		// 2d摄像机
		void setCamera2D(Camera* camera);
		// 设置视窗参数
		void setViewPort(float left, float right, float bottom, float top);
	public:
		/**
		*	绘制场景
		*/
		void drawScene(Node* scene);
	private:
		// 2d
		Camera* _camera2D = nullptr;
		// 3d
		Camera* _camera3D = nullptr;
	};

#define G_CAMERAS sys::Instance<Cameras>::getInstance()
}