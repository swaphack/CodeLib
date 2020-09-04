#pragma once

#include "Common/Node/Node.h"
#include "DimensionsType.h"
#include "ViewParameter.h"

namespace render
{
	// 摄像机
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		// 主摄像机
		static Camera* getMainCamera();
		// 主摄像机
		static void setMainCamera(Camera* camera);
	public:
		virtual bool init();
	public:
		// 设置维度
		void setDimensions(DimensionsType d);
		// 获取维度
		DimensionsType getDimensions() const;
		// 绘制节点
		virtual void drawNode();
	public:
		// 设置视窗参数
		void setViewPort(float left, float right, float bottom, float top);
		// 设置视野距离
		void setViewDistance(float zNear, float zFar);
		// 获取视窗参数
		const ViewParameter& getViewParameter() const;
		// 获取视窗参数
		const ViewParameter& get2DViewParameter() const;
		// 获取视窗参数
		const ViewParameter& get3DViewParameter() const;
	public:
		// 投影矩阵
		const math::Matrix4x4& getProjectMatrix() const;
		// 视图矩阵
		const math::Matrix4x4& getViewMatrix() const;
	public:
		// 投影矩阵
		math::Matrix4x4 getProjectMatrix(float znear, float zfar);
		// 相机对准指定位置
		math::Matrix4x4 lookAt(const math::Vector3& position);
		// 相机对准中心位置
		math::Matrix4x4 lookAtCenter();
		// 中心点位置
		math::Vector3 getCenterPosition();
	public:
		// 更新空间位置
		virtual void visit();
	protected:
		virtual void updateView();
		// 更新空间矩阵
		virtual void startUpdateTranform();
		// 翻转空间矩阵
		virtual void endUpdateTranform();
		//视窗大小发生改变
		virtual void updateViewPort();

		void onCameraSpaceChange();
	protected:
		// 主摄像头
		static Camera* _mainCamera;
		// 维度
		DimensionsType _dimensions = DimensionsType::TWO;
		// 投影矩阵
		math::Matrix4x4 _projectMatrix;
		// 视图矩阵
		math::Matrix4x4 _viewMatrix;
		// 2d视野参数
		ViewParameter _viewParameter2D;
		// 3D视野参数
		ViewParameter _viewParameter3D;
	};
}