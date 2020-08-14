#pragma once

#include "DrawNode.h"
#include "Common/struct/shape_common.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	2d����
	*/
	class DrawNode2D : public DrawNode
	{
	public:
		DrawNode2D();
		virtual ~DrawNode2D();
	public:
		virtual bool init();
	public:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setRectVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isRectVisible();
	public:
		/**
		*	�Ƿ���ʾ����
		*/
		void setMeshVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ����
		*/
		bool isMeshVisible();
	public:
		/**
		*	��ȡ���ο�
		*/
		const RectVectices& getRectVertex();
		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		virtual bool containTouchPoint(float x, float y);
	protected:
		void onDrawNode2DBodyChange();
		/**
		*	���ƾ���
		*/
		void drawRect();
	protected:
		// �Ƿ���ʾ���ο�
		bool _bRectVisible = false;
		// �Ƿ���ʾ����
		bool _bMeshVisible = false;
		// ���ο�
		RectVectices _rectVertex;
		// ʵ�ʾ��ο�
		RectVectices _realRectVertex;
		// ��������
		RectVertex _rectPosition;
	};
}
