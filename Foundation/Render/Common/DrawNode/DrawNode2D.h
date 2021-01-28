#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"
#include "DrawBoxProtocol.h"
namespace render
{
	/**
	*	2d绘制
	*/
	class DrawNode2D : 
		public DrawNode, 
		public DrawBoxProtocol

	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	public:
		/**
		*	是否显示网格
		*/
		void setMeshVisible(bool bVisible);
		/**
		*	是否显示网格
		*/
		bool isMeshVisible() const;
	public:
		/**
		*	获取本地矩形框
		*/
		const RectPoints& getLocalRectVertex() const;
		/**
		*	获取世界矩形框
		*/
		const RectPoints& getWorldRectVertex() const;
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containPoint(const math::Vector2& touchPoint);
	protected:
		/**
		*	计算实际矩形框坐标
		*/
		void calRealRectPoints();
		/**
		*	形状改变
		*/
		void onDrawNode2DBodyChange();
		/**
		*	颜色改变
		*/
		void onDrawNode2DColorChange();
		/**
		*	纹理改变
		*/
		void onDrawNode2DTextureChange();
		/**
		*	绘制矩形
		*/
		void drawRect();
		/**
		*	更新2d节点信息
		*/
		void updateDrawNode2DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// 是否显示网格
		bool _bMeshVisible = false;
		// 本地矩形框
		RectPoints _localRectPoints;
		// 世界矩形框
		RectPoints _worldRectPoints;
		// 矩形坐标
		RectVertex _rectVertex;
	};
}
