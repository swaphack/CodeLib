#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class DrawNode;
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
		*	更新节点
		*/ 
		virtual void updateNode(); 
		/**
		*	渲染节点
		*/
		render::DrawNode* getRenderNode();
	private:
		// 绘制节点
		PrimitiveNode* _drawNode = nullptr;
		// 盒子
		std::set<BoxDrawProtocol*> _boxes;
	};
}