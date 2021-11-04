#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class BoxProtocol;
	class PrimitiveNode;
	/**
	*	盒子绘制
	*/
	class BoxDraw : public Node
	{
	public:
		BoxDraw();
		virtual ~BoxDraw();
	public:
		virtual bool init();
	public:
		/**
		*	显示所有盒子
		*/
		void setAllBoxesVisibled(bool status);
		/**
		*	显示所有盒子
		*/
		bool isAllBoxesVisibled() const;
	public:
		/**
		*	2d渲染节点
		*/
		render::PrimitiveNode* getRenderNode2d();
		/**
		*	3d渲染节点
		*/
		render::PrimitiveNode* getRenderNode3d();
	public:
		void refreshBoxes();
	private:
		// 绘制节点
		PrimitiveNode* _drawNode2d = nullptr;
		// 绘制节点
		PrimitiveNode* _drawNode3d = nullptr;
		// 显示所有盒子
		bool _showAllBoxes = false;
	};
}