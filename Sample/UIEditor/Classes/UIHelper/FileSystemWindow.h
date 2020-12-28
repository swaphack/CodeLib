#pragma once

#include "Panel/SinglePanel.h"

namespace ue
{
	/**
	*  ���ļ����
	*/
	class FileSystemWindow : public SinglePanel
	{
	public:
		FileSystemWindow ();
		virtual ~FileSystemWindow ();
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
