#pragma once

#include "Panel.h"

namespace ue
{
	class DesignPanel;
	class PropertyPanel;

	// ��ͼ����
	class ViewLayout : public Panel
	{
	public:
		ViewLayout();
		virtual ~ViewLayout();
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
		DesignPanel* m_pDesignPanel = nullptr;
	};
}