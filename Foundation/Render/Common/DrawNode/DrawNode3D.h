#pragma once

#include "DrawNode.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	3d绘制
	*/
	class DrawNode3D : 
		public DrawNode
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
	protected:
		/**
		*	形状改变
		*/
		void onDrawNode3DBodyChange();
		/**
		*	颜色改变
		*/
		void onDrawNode3DColorChange();
		/**
		*	纹理改变
		*/
		virtual void onDrawNode3DTextureChange();
		/**
		*	更新节点信息
		*/
		virtual void updateDrawNode3DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// 顶点信息
		CubeVertex _cubeVertex;
	};
}