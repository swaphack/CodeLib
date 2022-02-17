#pragma once

#include "DrawNode.h"
#include "Common/struct/vertex_common.h"
namespace render
{
	/**
	*	2d绘制
	*/
	class DrawNode2D : 
		public DrawNode
	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	protected:
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
		*	更新2d节点信息
		*/
		virtual void updateDrawNode2DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// 顶点信息
		RectVertex _rectVertex;
	};
}
