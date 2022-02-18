#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"
#include "physicslib.h"

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
			phy::Color4F color;

			PrimitiveVertex(const math::Vector3& point, const phy::Color4F& color)
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
		/**
		*	设置模式
		*/ 
		void setDrawMode(DrawMode mode);
		/**
		*	模式
		*/
		DrawMode getDrawMode();
	public:
		/**
		*	添加一个点坐标
		*/
		void appendPoint(const math::Vector3& point);
		/**
		*	添加一个点坐标
		*/
		void appendPoint(const math::Vector3& point, const phy::Color4F& color);
		/**
		*	添加一些坐标
		*/
		void appendPoint(const PrimitiveVertex& vertex);
		/**
		*	设置坐标点
		*/
		void appendPoints(const std::vector<math::Vector3>& points, const phy::Color4F& color);
		/**
		*	设置坐标点
		*/
		void appendPoints(int count, const math::Vector3* points, const phy::Color4F& color);
		/**
		*	移除所有点坐标
		*/
		void removeAllPoints();
	public:
		/**
		*	点大小
		*/
		void setPointSize(float size);
		/**
		*	点大小
		*/
		float getPointSize() const;
	protected:
		void onPrimitiveChange();
		/**
		*	颜色改变
		*/
		virtual void onDrawNode2DColorChange();
		/**
		*	纹理改变
		*/
		virtual void onDrawNode2DTextureChange();
	private:
		// 顶点信息
		std::vector<PrimitiveVertex> _vertexes;
		/**
		*	点大小
		*/
		float _pointSize = 1;
	};
}