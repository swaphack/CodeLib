#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	2d绘制
	*/
	class DrawNode2D : public DrawNode
	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	public:
		/**
		*	是否显示矩形框
		*/
		void setRectVisible(bool bVisible);
		/**
		*	是否显示矩形框
		*/
		bool isRectVisible();
	public:
		/**
		*	是否显示网格
		*/
		void setMeshVisible(bool bVisible);
		/**
		*	是否显示网格
		*/
		bool isMeshVisible();
	public:
		/**
		*	获取矩形框
		*/
		const RectPoints& getRectVertex();
		/**
		*	坐标是否在当前对象内
		*/
		virtual bool containTouchPoint(float x, float y);
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
		*	绘制矩形
		*/
		void drawRect();
		/**
		*	更新2d节点信息
		*/
		void updateDrawNode2DMesh();
	protected:
		// 是否显示矩形框
		bool _bRectVisible = false;
		// 是否显示网格
		bool _bMeshVisible = false;
		// 矩形框
		RectPoints _rectPoints;
		// 实际矩形框
		RectPoints _realRectPoints;
		// 矩形坐标
		RectVertex _rectVertex;
	};
}
