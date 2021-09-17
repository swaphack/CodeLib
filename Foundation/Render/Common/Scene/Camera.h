#pragma once

#include "Common/Node/Node.h"
#include "DimensionsType.h"
#include "Common/View/ViewParameter.h"
#include "mathlib.h"

namespace render
{
	class Scene;
	class DebugDraw;

	/**
	*	摄像机
	*	投影矩阵[-1, 1]
	*/
	class Camera : public Node
	{
	public:
		Camera();
		virtual ~Camera();
	public:
		virtual bool init();
	public:
		// 设置维度
		void setDimensions(DimensionsType d);
		// 获取维度
		DimensionsType getDimensions() const;
		// 绘制节点
		void updateCameraView();
	public:
		// 设置视窗参数
		void setViewPort(float left, float right, float bottom, float top);
		// 设置视野距离
		void setViewDistance(float zNear, float zFar);
		// 获取视窗参数
		const ViewParameter& getViewParameter() const;
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
		// 调试绘制
		DebugDraw* getDebugDraw() const;
		// 视图绘制是否显示
		void setViewDrawVisible(bool bVisible);
		// 获取坐标
		math::Vector3 convertScreenPointToCameraPosition(const math::Vector2& screenPoint) const;
		// 获取所在世界坐标
		math::Vector3 convertScreenPointToWorldPosition(const math::Vector2& screenPoint) const;
		// 获取射线
		math::Ray convertScreenPointToCameraRay(const math::Vector2& screenPoint) const;
		// 获取所在世界射线
		math::Ray convertScreenPointToWorldRay(const math::Vector2& screenPoint) const;
		// 将本地射线转为世界射线
		math::Ray convertLocalRayToWorldRay(const math::Ray localRay) const;
	public:
		// 绘制场景
		void drawScene(Node* scene);
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
		// 维度
		DimensionsType _dimensions = DimensionsType::TWO;
		// 投影矩阵
		math::Matrix4x4 _projectMatrix;
		// 视图矩阵
		math::Matrix4x4 _viewMatrix;
		// 2d视野参数
		ViewParameter _viewParameter;
		// 调试绘制
		DebugDraw* _debugDraw = nullptr;
		// 视图性转绘制
		DebugDraw* _viewShapeDraw = nullptr;
	};
}