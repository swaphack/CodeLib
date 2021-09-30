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
		enum class CameraType
		{
			TWO,
			THREE,
			DESIGN,
		};
	public:
		Cameras();
		virtual ~Cameras();
	public:
		// 3d摄像机
		Camera* getCamera3D() const;
		// 3d摄像机
		void setCamera3D(Camera* camera);
		// 2d摄像机
		Camera* getCamera2D() const;
		// 2d摄像机
		void setCamera2D(Camera* camera);
		// 设计时摄像头
		void setDesignCamera(Camera* camera);
		// 设计时摄像头
		Camera* getDesignCamera() const;
		// 运行时摄像头
		Camera* getRunningCamera3D() const;
		// 设置视窗参数
		void setViewPort(float left, float right, float bottom, float top);
	public:
		/**
		*	绘制场景
		*/
		void drawScene(Node* scene);
	protected:
		void updateViewSize();
		// 设置摄像机
		void setCamera(CameraType eType, Camera* camera);
		// 获取摄像机
		Camera* getCamera(CameraType eType) const;
	private:
		// 摄像机
		std::map<CameraType, Camera*> _cameras;
	private:
		math::Vector4 _viewPort;
	};

#define G_CAMERAS sys::Instance<render::Cameras>::getInstance()
}