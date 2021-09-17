#pragma once

#include "Common/Node/Node.h"

namespace render
{
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
		*	2d��Ⱦ�ڵ�
		*/
		render::PrimitiveNode* getRenderNode2d();
		/**
		*	3d��Ⱦ�ڵ�
		*/
		render::PrimitiveNode* getRenderNode3d();
	protected:
		void onBoxChanged();
	private:
		// ���ƽڵ�
		PrimitiveNode* _drawNode2d = nullptr;
		// ���ƽڵ�
		PrimitiveNode* _drawNode3d = nullptr;
		// ����
		std::set<BoxDrawProtocol*> _boxes;
	};

#define G_BOXDRAW render::BoxDraw::getInstance()
}