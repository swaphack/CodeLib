#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"

namespace render
{
	class Materials;

	/**
	*	UI�ؼ�����
	*/
	class CtrlWidget : public DrawNode2D,
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
	protected:
		virtual void beforeDrawNode();
		/**
		*	����
		*/
		virtual void afterDrawNode();
	protected:
		/**
		*	��ϸı�
		*/
		virtual void onBlendChange();
		/**
		*	��״�ı�
		*/
		void onCtrlWidgetBodyChange();
	protected:
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