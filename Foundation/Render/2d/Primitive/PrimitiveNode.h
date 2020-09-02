#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl基础绘图节点
	class PrimitiveNode : public DrawNode2D
	{
	private:
		struct PrimitiveVertex
		{
			// 顶点坐标
			math::Vector3 point;
			// 顶点颜色
			sys::Color4B color;

			PrimitiveVertex(const math::Vector3& point, const sys::Color4B& color)
				:point(point), color(color)
			{

			}
		};
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
		// 添加一个点坐标
		void appendPoint(const math::Vector3& point);

		void appendPoint(const math::Vector3& point, const sys::Color4B& color);

		void appendPoint(const PrimitiveVertex& vertex);
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
		// 顶点信息
		std::vector<PrimitiveVertex> _vertexes;
		/**
		*	大小
		*/
		float _pointSize = 1;
	};
}