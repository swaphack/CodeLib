#pragma once

#include "../Node/ColorNode.h"
#include "ext-config.h"

namespace render
{
	// opengl基础绘图节点
	class DrawNode : public ColorNode
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
		// 设置宽度
		void setWidth(float width);
		float getWidth();
		// 模式
		void setDrawMode(BeginMode mode);
		int getDrawMode();
		// 设置点坐标
		void setPoints(const std::vector<sys::Vector3>& points);
		// 添加一个点坐标
		void appendPoint(const sys::Vector3& point);
		// 添加一个点坐标
		void appendPoint(const sys::Vector2& point);
		// 移除一个点坐标
		void removePoint(const sys::Vector3& point);
		// 移除一个点坐标
		void removePoint(const sys::Vector2& point);
		// 移除所有点坐标
		void removeAllPoints();
	protected:
		// 重新计算参数
		virtual void initSelf();
	private:
		// 宽度
		float _width;
		// 模式
		BeginMode _drawMode;
		// 点坐标
		std::vector<sys::Vector3> _points;
	};
}