#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	��ȡ�ĵ����
	*/
	class DocumentPanel : public Panel
	{
	public:
		DocumentPanel();
		virtual ~DocumentPanel();
	public:
		virtual bool init();
	public:


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
