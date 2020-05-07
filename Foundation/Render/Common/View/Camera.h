#pragma once

#include "Common/Node/Node.h"

namespace render
{
	// 维度模式
	enum CameraDimensions
	{
		ED_NONE,
		ED_2D,
		ED_3D
	};

	// 视窗参数
	struct CameraParams
	{
		float xLeft = 0;
		float xRight = 0;
		float yBottom = 0;
		float yTop = 0;
		float zNear = 0;
		float zFar = 0;
	};

	// 摄像机
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		static Camera* getMainCamera();
		static void setMainCamera(CameraDimensions d);
	public:
		virtual bool init();
	public:
		// 获取维度
		CameraDimensions getDimensions();
	public:
		// 设置视窗参数
		void setViewPortParams(float left, float right, float bottom, float top, float zNear, float zFar);
		// 获取视窗参数
		const CameraParams& getViewPortParams();
	public:
		// 更新空间位置
		virtual void visit();
	protected:
		virtual void updateView();
		// 更新空间矩阵
		virtual void updateTranform();
		// 翻转空间矩阵
		virtual void inverseTranform();
		//视窗大小发生改变
		virtual void updateViewPort();
	protected:
		// 设置维度
		void setDimensions(CameraDimensions d);
	protected:
		// 主摄像头
		static Camera* _mainCamera;
		// 维度
		CameraDimensions _dimensions;
		// 参数
		CameraParams _cameraParams;
	};

	// 2d 摄像头
	class Camera2D : public Camera
	{
	public:
		Camera2D();
		virtual ~Camera2D();
	public:
		virtual void updateView();
	protected:
		//视窗大小发生改变
		virtual void updateViewPort();
	};
	// 3d 摄像头
	class Camera3D : public Camera
	{
	public:
		Camera3D();
		virtual ~Camera3D();
	public:
		virtual void updateView();
	public:
		// 相机对准指定位置
		virtual void lookAt(const math::Vector3& position);
	protected:
		//视窗大小发生改变
		virtual void updateViewPort();
	};
}