#pragma once

#include "Common/Node/Node.h"
#include "Common/View/ViewParameter.h"

namespace render
{
	class BoxDrawProtocol;
	class PrimitiveNode;
	/**
	*	调试绘制
	*/
	class DebugDraw : public Node
	{
	public:
		DebugDraw();
		virtual ~DebugDraw();
	public:
		virtual bool init();
	public:
		/**
		*	清空
		*/
		void cleanup();
		/**
		*	画一条世界直线
		*/
		void drawW2LLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	画一条本地直线
		*/
		void drawL2WLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	画一条直线
		*/
		void drawLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	正交
		*/
		void drawOrtho(const ViewParameter& paramter, const phy::Color4F& color = phy::Color4F());
		/**
		*	锥体
		*/
		void drawFrustum(const ViewParameter& paramter, const phy::Color4F& color = phy::Color4F());
	public:
		/**
		*	2d渲染节点
		*/
		render::PrimitiveNode* getRenderNode();
	private:
		// 绘制节点
		PrimitiveNode* _drawNode = nullptr;
	};
}