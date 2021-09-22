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
	*	世界坐标(World)：位置和旋转信息都是基于世界坐标系的,屏幕中心坐标为（0，0）,x,y,z范围[-1,1]
	*	观察坐标(Eye)：视图中观察的画面始终是由摄像机提供的，基于摄像机的一个坐标系也就是"Eye Space"（简单来讲就是把摄像机看作原点位置）
	*	视口坐标(ViewPort)：视口是针对游戏显示的画面进行描述的，View Port用于描述整个游戏画面的坐标，左下角为(0,0),右上角为（1,1)
	*	屏幕坐标(Screen)：屏幕坐标开始和像素扯上关系了，也就是说屏幕坐标和分辨率有关，屏幕的左下角为(0,0),但右上角为(screen.width,screen.height)
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
		// 投影
		math::Vector3 project(const math::Vector2& worldPoint) const;
		// 逆投影
		math::Vector3 unproject(const math::Vector2& viewPoint) const;

		// 屏幕射线转为视图射线
		math::Ray convertScreenPointToLocalRay(const math::Vector2& screenPoint) const;
		// 屏幕射线转为视图射线
		math::Ray convertScreenPointToWorldRay(const math::Vector2& screenPoint) const;
		// 屏幕坐标转为视图坐标
		math::Vector3 convertScreenToViewPort(const math::Vector2& screenPoint) const;
		// 屏幕坐标转为世界坐标
		math::Vector3 convertScreenToWorldPoint(const math::Vector2& screenPoint) const;

		// 视图坐标转为射线
		math::Ray convertViewPortPointToRay(const math::Vector3& viewPortPoint) const;
		// 视图坐标转为世界坐标
		math::Vector3 convertViewPortToWorldPoint(const math::Vector3& viewPortPoint) const;
		// 视图坐标转为屏幕坐标
		math::Vector3 convertViewPortToScreenPoint(const math::Vector2& viewPortPoint) const;

		// 世界坐标转为视图坐标
		math::Vector3 convertWorldToViewPort(const math::Vector3& worldPoint) const;
		// 世界坐标转为屏幕坐标
		math::Vector3 convertWorldToScreenPoint(const math::Vector2& worldPoint) const;
	public:
		// 绘制场景
		void drawScene(Node* scene);
		// 更新空间位置
		virtual void visit();
	protected:
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