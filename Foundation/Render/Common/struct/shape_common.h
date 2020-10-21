#pragma once

#include "system.h"
#include "mathlib.h"

// 形状
namespace render
{
	// 矩形框顶点集
	struct RectPoints
	{
	public:
		// 左下角
		math::Vector3 leftDown;
		// 右下角
		math::Vector3 rightDown;
		// 右上角
		math::Vector3 rightUp;
		// 左上角
		math::Vector3 leftUp;
	public:
		RectPoints();

		// 面积法判断
		bool containPointByArea(float x, float y);
		// 多边形法判断
		bool containPointByPolygon(float x, float y);
		//  获取点坐在的锚点位置
		math::Vector3 getAnchorByPoint(float x, float y);

	public: 
		float getX();
		float getY();

		float getWidth();
		float getHeight();
	protected:
		float getArea(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3);
	};

	// 立方体顶点集
	struct CubePoints
	{
	public:
		// 前面
		RectPoints front;
		// 背面
		RectPoints back;
		// 左面
		RectPoints left;
		// 右面
		RectPoints right;
		// 顶部
		RectPoints top;
		// 底部
		RectPoints bottom;
	public:
		CubePoints()
		{ }

	public:
		void setFrontLeftDownPosition(const math::Vector3& point);
		void setFrontRightDownPosition(const math::Vector3& point);
		void setFrontRightUpPosition(const math::Vector3& point);
		void setFrontLeftUpPosition(const math::Vector3& point);

		void setBackLeftDownPosition(const math::Vector3& point);
		void setBackRightDownPosition(const math::Vector3& point);
		void setBackRightUpPosition(const math::Vector3& point);
		void setBackLeftUpPosition(const math::Vector3& point);
	public:
		// 多边形法判断
		bool containPointByPolygon(float x, float y);
	};
}