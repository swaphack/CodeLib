#pragma once

#include "Common/DrawNode/import.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Materials;

	/**
	*	UI�ؼ�����
	*/
	class CtrlWidget : public DrawNode,
		public BlendProtocol
	{
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
	public:
		/**
		*	��ӿؼ�
		*/
		void addWidget(CtrlWidget* widget);
		/**
		*	��ӿؼ�
		*/
		void addWidget(CtrlWidget* widget, int zOrder);
		/**
		*	�Ƴ��ؼ�
		*/
		void removeWidget(CtrlWidget* widget);
		/**
		*	�Ƴ����пؼ�
		*/
		void removeAllWidgets();
	public:
		/**
		*	�Ƿ�ü�
		*/
		void setClip(bool bClip);
		/**
		*	�Ƿ�ü�
		*/
		bool isClip();
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setRectVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isRectVisible();
	protected:
		virtual void beforeDrawNode();
		/**
		*	����
		*/
		virtual void afterDrawNode();
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
		void calRectData();
	protected:
		/**
		*	��ϸı�
		*/
		virtual void onBlendChange();
		/**
		*	���ƾ���
		*/
		void drawRect();
	protected:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool _bRectVisible = false;
		// ���ο�
		RectVectices _rectVertex;
		// ʵ�ʾ��ο�
		RectVectices _realRectVertex;
		// ʵ�ʶ����
		math::Polygon<4> _realPolygon;
		// �ؼ�
		std::vector<CtrlWidget*> _widgets;
		/**
		*	�Ƿ�ü�
		*/
		bool _bClip = false;
		/**
		*	�ü�����
		*/
		math::Rect _clipRect;
	};
}