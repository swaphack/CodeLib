#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class DrawNode;
	class BoxDrawProtocol;
	class PrimitiveNode;
	/**
	*	���ӻ���
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
		*	��Ӻ���
		*/
		void addBox(BoxDrawProtocol* box);
		/**
		*	�Ƴ�����
		*/
		void removeBox(BoxDrawProtocol* box);
	public:
		/**
		*	���½ڵ�
		*/ 
		virtual void updateNode(); 
		/**
		*	��Ⱦ�ڵ�
		*/
		render::DrawNode* getRenderNode();
	private:
		// ���ƽڵ�
		PrimitiveNode* _drawNode = nullptr;
		// ����
		std::set<BoxDrawProtocol*> _boxes;
	};
}