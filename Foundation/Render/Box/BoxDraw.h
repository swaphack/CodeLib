#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class BoxDrawProtocol;
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
		static BoxDraw* getInstance();
	public:
		virtual bool init();
	public:
		/**
		*	添加盒子
		*/
		void addBox(BoxDrawProtocol* box);
		/**
		*	移除盒子
		*/
		void removeBox(BoxDrawProtocol* box);
	public:
		/**
		*	2d渲染节点
		*/
		render::PrimitiveNode* getRenderNode2d();
		/**
		*	3d渲染节点
		*/
		render::PrimitiveNode* getRenderNode3d();
	protected:
		void onBoxChanged();
	private:
		// 绘制节点
		PrimitiveNode* _drawNode2d = nullptr;
		// 绘制节点
		PrimitiveNode* _drawNode3d = nullptr;
		// 盒子
		std::set<BoxDrawProtocol*> _boxes;
	};

#define G_BOXDRAW render::BoxDraw::getInstance()
}