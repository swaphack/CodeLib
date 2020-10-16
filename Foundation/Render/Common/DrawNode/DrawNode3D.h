#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	3d绘制
	*/
	class DrawNode3D : public DrawNode
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
	public:
		/**
		*	是否显示矩形框
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	是否显示矩形框
		*/
		bool isBoxVisible() const;
	public:
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calBoxData();
		/**
		*	绘制模型框
		*/
		void drawBox();
	private:
		/**
		*	是否显示矩形框
		*/
		bool _bBoxVisible = false;
		// 模型框
		CubePoints _boxVertex;
		// 实际模型框
		CubePoints _realBoxVertex;
	};
}