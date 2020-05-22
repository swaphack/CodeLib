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
		public ColorProtocol,
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
	protected:
		virtual void beforeDrawNode();
		virtual void afterDrawNode();
	public:
		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		const RectVectices& getRectVertex();
		/**
		*	�����Ƿ��ڵ�ǰ������
		*/
		virtual bool containTouchPoint(float x, float y);
	protected:
		void calRectData();
	protected:
		virtual void onColorChange();
		virtual void onBlendChange();
	protected:
		// ���ο�
		RectVectices _rectVertex;
		// ʵ�ʾ��ο�
		RectVectices _realRectVertex;
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