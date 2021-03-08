#pragma once

#include "Panel/SinglePanel.h"

namespace ue
{
	/**
	*	�����˵�
	*/
	class Menu : public SinglePanel
	{
	public:
		Menu();
		virtual ~Menu();
	public:
		/**
		*	�ļ�·��
		*/
		virtual const char* getPanelPath();
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
	};
}
