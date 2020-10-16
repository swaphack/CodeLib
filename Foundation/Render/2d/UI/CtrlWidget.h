#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Common/struct/shape_common.h"
#include "Common/Input/TouchDelegate.h"

namespace render
{
	class Materials;

	/**
	*	UI�ؼ�����
	*/
	class CtrlWidget : 
		public DrawNode2D,
		public BlendProtocol,
		public TouchProtocol
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
		virtual void addWidget(CtrlWidget* widget);
		/**
		*	��ӿؼ�
		*/
		virtual void addWidget(CtrlWidget* widget, int zOrder);
		/**
		*	�Ƴ��ؼ�
		*/
		virtual void removeWidget(CtrlWidget* widget);
		/**
		*	�Ƴ����пؼ�
		*/
		virtual void removeAllWidgets();
	public:
		/**
		*	�Ƿ�ɵ��
		*/
		bool isTouchEnable();
		/**
		*	�����Ƿ�ɵ��
		*/
		void setTouchEnable(bool bEnabled);
	protected:
		/**
		*	�����Ļ
		*/
		void onBeginTouch(Node* node, float x, float y, bool include);
		/**
		*	��ס������
		*/
		void onMoveTouch(Node* node, float x, float y, bool include);
		/**
		*	�ſ�
		*/
		void onEndTouch(Node* node, float x, float y, bool include);
	protected:
		/**
		*	�����Ļ
		*/
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	����Ļ�ϻ���
		*/
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	�뿪��Ļ
		*/
		virtual bool onTouchEnded(float x, float y, bool include);
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