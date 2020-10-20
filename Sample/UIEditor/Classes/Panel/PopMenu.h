#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	�����˵�
	*/
	class PopMenu : public Panel
	{
	public:
		PopMenu();
		virtual ~PopMenu();
	public:
		/**
		*	����λ��
		*/
		void updatePosition(const ui::LayoutItem* item, sys::CSSDirection eDir);
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
		/**
		*	��ʼ��
		*/
		virtual void initUI();
		/**
		*	�¼���
		*/
		virtual void initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual void initText();
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
	public:
		/**
		*	��ʾ
		*/
		static void show(const ui::LayoutItem* item, sys::CSSDirection eDir);
		/**
		*	��ʾ
		*/
		static void show(const math::Vector2& pos = math::Vector2());
		/**
		*	����
		*/
		static void hide();
		/**
		*	�Ƿ���ʾ
		*/
		static bool isShow();
		/**
		*	ʵ��
		*/
		static PopMenu* getInstance();
	private:
		// ����
		static PopMenu* sPopMenu;
		// ����
		ui::Layout* _body = nullptr;
	};
}
