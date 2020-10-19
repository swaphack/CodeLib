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
	public:
		/**
		*	��ʾ
		*/
		static void show();
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
	};
}
