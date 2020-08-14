#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl基础绘图节点
	class PrimitiveNode : public DrawNode2D
	{
	public:
		PrimitiveNode();
		virtual ~PrimitiveNode();
	public:
		virtual bool init();
	public:
		// 模式
		void setDrawMode(DrawMode mode);

		DrawMode getDrawMode();
	public:
		// 设置点坐标
		void setPoints(const std::vector<math::Vector3>& points);
		// 添加一个点坐标
		void appendPoint(const math::Vector3& point);
		// 添加一个点坐标
		void appendPoint(const math::Vector2& point);
		// 移除一个点坐标
		void removePoint(const math::Vector3& point);
		// 移除一个点坐标
		void removePoint(const math::Vector2& point);
		// 移除所有点坐标
		void removeAllPoints();
	public:
		/**
		*	大小
		*/
		void setPointSize(float size);
		/**
		*	大小
		*/
		float getPointSize() const;
	protected:
		void onPrimitiveChange();
	private:
		// 点坐标
		std::vector<math::Vector3> _points;
		/**
		*	大小
		*/
		float _pointSize = 1;
	};
}