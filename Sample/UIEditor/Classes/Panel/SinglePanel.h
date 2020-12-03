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
		/**
		*	�������·��
		*/
		virtual const char* getPanelPath();
		/**
		*	����λ��
		*/
		void updatePosition(const ui::LayoutItem* item, sys::CSSDirection eDir);
	public:
		/**
		*	��ʾ
		*/
		void show();
		/**
		*	��ʾ
		*/
		void showWithTarget(const ui::LayoutItem* item, sys::CSSDirection eDir);
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
	protected: // ���
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
	protected:
		// ����
		ui::Layout* _body = nullptr;
	};
}