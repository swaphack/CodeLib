#pragma once

#include "Common/Node/Node.h"

namespace render
{
	class BoxProtocol;
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
		virtual bool init();
	public:
		/**
		*	��ʾ���к���
		*/
		void setAllBoxesVisibled(bool status);
		/**
		*	��ʾ���к���
		*/
		bool isAllBoxesVisibled() const;
	public:
		/**
		*	2d��Ⱦ�ڵ�
		*/
		render::PrimitiveNode* getRenderNode2d();
		/**
		*	3d��Ⱦ�ڵ�
		*/
		render::PrimitiveNode* getRenderNode3d();
	public:
		void refreshBoxes();
	private:
		// ���ƽڵ�
		PrimitiveNode* _drawNode2d = nullptr;
		// ���ƽڵ�
		PrimitiveNode* _drawNode3d = nullptr;
		// ��ʾ���к���
		bool _showAllBoxes = false;
	};
}