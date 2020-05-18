#pragma once

#include "DrawNode.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl基础绘图节点
	class PrimitiveNode : public DrawNode
	{
	public:
		PrimitiveNode();
		virtual ~PrimitiveNode();
	public:
		virtual bool init();
	protected:
		virtual void onDraw();
	public:
		// 设置宽度
		void setWidth(float width);
		float getWidth();
		// 模式
		void setDrawMode(ShapeMode mode);
		ShapeMode getDrawMode();
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

		void setColor(const sys::Color4F& color);
		const sys::Color4F& getColor() const;
	private:
		// 宽度
		float _width = 1;
		// 模式
		ShapeMode _drawMode = ShapeMode::POINTS;
		// 点坐标
		std::vector<math::Vector3> _points;

		sys::Color4F _color;
	};
}