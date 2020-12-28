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
	private:
		// ������
		UIDesignView* m_pDesignPanel = nullptr;
	};
}