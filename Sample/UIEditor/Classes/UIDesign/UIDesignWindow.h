#pragma once

#include "Panel/Panel.h"

namespace ue
{
	class UIDesignView;
	class UIDesignProperty;

	// ��ͼ����
	class UIDesignWindow : public Panel
	{
	public:
		UIDesignWindow();
		virtual ~UIDesignWindow();
	public:
		virtual bool init();
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
	private:
		// ������
		UIDesignView* m_pDesignPanel = nullptr;
	};
}