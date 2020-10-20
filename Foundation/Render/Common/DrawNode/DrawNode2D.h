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
		bool isRectVisible() const;
		/**
		*	���þ��ο���ɫ
		*/
		void setRectColor(const sys::Color4B& color);
		/**
		*	���ο���ɫ
		*/
		const sys::Color4B& getRectColor() const;
	public:
		/**
		*	�Ƿ���ʾ����
		*/
		void setMeshVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ����
		*/
		bool isMeshVisible() const;
	public:
		/**
		*	��ȡ���ο�
		*/
		const RectPoints& getRectVertex() const;
		/**
		*	��ȡʵ�ʾ��ο�
		*/
		const RectPoints& getRealRectVertex() const;
		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		virtual bool containTouchPoint(float x, float y);
	protected:
		/**
		*	����ʵ�ʾ��ο�����
		*/
		void calRealRectPoints();
		/**
		*	��״�ı�
		*/
		void onDrawNode2DBodyChange();
		/**
		*	��ɫ�ı�
		*/
		void onDrawNode2DColorChange();
		/**
		*	���ƾ���
		*/
		void drawRect();
		/**
		*	����2d�ڵ���Ϣ
		*/
		void updateDrawNode2DMesh();
	protected:
		virtual void afterDraw();
	protected:
		// �Ƿ���ʾ���ο�
		bool _bRectVisible = false;
		// ���ο���ɫ
		sys::Color4B _rectColor;
		// �Ƿ���ʾ����
		bool _bMeshVisible = false;
		// ���ο�
		RectPoints _rectPoints;
		// ʵ�ʾ��ο�
		RectPoints _realRectPoints;
		// ��������
		RectVertex _rectVertex;
	};
}
