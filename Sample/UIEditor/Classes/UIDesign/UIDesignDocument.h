#pragma once

#include "Panel/Panel.h"

namespace ue
{
	/**
	*	��ȡ�ĵ����
	*/
	class UIDesignDocument : public Panel
	{
	public:
		UIDesignDocument();
		virtual ~UIDesignDocument();
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
