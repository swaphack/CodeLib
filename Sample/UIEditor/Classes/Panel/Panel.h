#pragma once

#include "ui.h"

namespace ue
{
	// ���
	class Panel : public ui::CtrlFile
	{
	public:
		Panel();
		virtual ~Panel();
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
	};
}
