#pragma once

#include "DrawNode.h"
#include "Common/struct/vertex_common.h"
namespace render
{
	/**
	*	2d����
	*/
	class DrawNode2D : 
		public DrawNode
	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	protected:
		/**
		*	��״�ı�
		*/
		void onDrawNode2DBodyChange();
		/**
		*	��ɫ�ı�
		*/
		void onDrawNode2DColorChange();
		/**
		*	����ı�
		*/
		void onDrawNode2DTextureChange();
		/**
		*	����2d�ڵ���Ϣ
		*/
		virtual void updateDrawNode2DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// ������Ϣ
		RectVertex _rectVertex;
	};
}
