#pragma once

#include "Panel/SinglePanel.h"

namespace ue
{
	/**
	*	�����˵�
	*/
	class UIDesignPopMenu : public SinglePanel
	{
	public:
		UIDesignPopMenu();
		virtual ~UIDesignPopMenu();
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
