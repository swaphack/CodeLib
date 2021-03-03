#pragma once

#include "Panel/Panel.h"

namespace ue
{
	/**
	*	���ֲ㣬���ڴ����¼�
	*/
	class UIDesignMask : public Panel
	{
	public:
		UIDesignMask();
		virtual ~UIDesignMask();
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
	private:
		ui::CtrlLayout* m_pMainLayout = nullptr;

		math::Vector2 m_pTempPosition;
		ui::CtrlImage* m_pCloneWidget = nullptr;
	};
}