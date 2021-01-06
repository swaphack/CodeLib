#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"
#include "DrawBoxProtocol.h"
namespace render
{
	/**
	*	3d绘制
	*/
	class DrawNode3D : public DrawNode, public DrawBoxProtocol
	{
	public:
		DrawNode3D();
		virtual ~DrawNode3D();
	public:
		// 务必调用，包含属性修改时通知
		virtual bool init();
	public:
		virtual bool containPoint(const math::Vector2& touchPoint);
	protected:
		void calBoxData();
		/**
		*	绘制模型框
		*/
		void drawBox();
	private:
		// 模型框
		CubePoints _boxVertex;
		// 实际模型框
		CubePoints _realBoxVertex;
	};
}