#pragma once

#include "SinglePanel.h"

namespace ue
{
	/**
	*  ���ļ����
	*/
	class OpenFilePanel : public SinglePanel
	{
	public:
		OpenFilePanel ();
		virtual ~OpenFilePanel ();
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
