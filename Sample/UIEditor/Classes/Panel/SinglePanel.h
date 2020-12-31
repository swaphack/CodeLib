#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	�������
	*/
	class SinglePanel : public Panel
	{
	public:
		SinglePanel();
		virtual ~SinglePanel();

	public:
		virtual bool init();
	public:
		/**
		*	�������·��
		*/
		virtual const char* getPanelPath();
		/**
		*	����λ��
		*/
		void updatePosition(const ui::CtrlWidget* item, sys::CSSDirection eDir);
	public:
		/**
		*	��ʾ
		*/
		void show();
		/**
		*	��ʾ
		*/
		void showWithTarget(const ui::CtrlWidget* item, sys::CSSDirection eDir);
		/**
		*	�ر�
		*/
		void close();
	protected:
		/**
		*	��������λ��
		*/
		void setPositionLeftTop(const math::Vector2& pos);
		/**
		*	��������λ��
		*/
		void setPositionRightTop(const math::Vector2& pos);
		/**
		*	��������λ��
		*/
		void setPositionLeftBottom(const math::Vector2& pos);
		/**
		*	��������λ��
		*/
		void setPositionRightBottom(const math::Vector2& pos);
	protected:
		// ����
		ui::CtrlWidget* _body = nullptr;
	};
}