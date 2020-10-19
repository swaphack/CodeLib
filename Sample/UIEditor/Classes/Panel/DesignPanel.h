#pragma once

#include "Panel.h"

namespace ue
{
	// �����
	class DesignPanel : public Panel
	{
	public:
		DesignPanel();
		virtual ~DesignPanel();
	public:
		virtual bool init();
	public:
		/**
		*	ȡ��ѡ��
		*/
		void unselectTarget();
		/**
		*	��ȡȡ��ѡ��
		*/
		ui::LayoutItem* getSelectedTarget() const;
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
	protected:
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
	protected:
		/**
		*	�����ǰ������
		*/
		bool touchFrontWidget(ui::LayoutItem* layoutItem,float x, float y);
	protected:
		// ����ļ�
		ui::LayoutItem* m_pUIFile = nullptr;
		// �Ƿ�ѡ��
		bool m_bSelected = false;
		// ѡ�ж���
		ui::LayoutItem* m_pSelectedTarget = nullptr;
	};
}
