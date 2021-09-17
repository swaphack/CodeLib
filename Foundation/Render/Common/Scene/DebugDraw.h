#pragma once

#include "Common/Node/Node.h"
#include "Common/View/ViewParameter.h"

namespace render
{
	class BoxDrawProtocol;
	class PrimitiveNode;
	/**
	*	���Ի���
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
		*	���
		*/
		void cleanup();
		/**
		*	��һ������ֱ��
		*/
		void drawW2LLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	��һ������ֱ��
		*/
		void drawL2WLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	��һ��ֱ��
		*/
		void drawLine(const math::Vector3& src, const math::Vector3& dest, const phy::Color4F& color = phy::Color4F());
		/**
		*	����
		*/
		void drawOrtho(const ViewParameter& paramter, const phy::Color4F& color = phy::Color4F());
		/**
		*	׶��
		*/
		void drawFrustum(const ViewParameter& paramter, const phy::Color4F& color = phy::Color4F());
	public:
		/**
		*	2d��Ⱦ�ڵ�
		*/
		render::PrimitiveNode* getRenderNode();
	private:
		// ���ƽڵ�
		PrimitiveNode* _drawNode = nullptr;
	};
}