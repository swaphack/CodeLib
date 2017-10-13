#pragma once

#include "macros.h"
#include "ui_common.h"

namespace ui
{
	class Layout;
	/**
	*	������ʾ
	*/
	class Display : public sys::Object
	{
	public:
		Display();
		virtual ~Display();
	public:
		/**
		*	����ui���ڵ�
		*/
		void setUIRoot(Widget* root);
		/**
		*	��ʾ
		*/
		void show();
		/**
		*	����
		*/
		void hide();
		/**
		*	����
		*/
		void close();
		/**
		*	���¼���
		*/
		void reload();
		/**
		*	�����ļ�·��
		*/
		void setFilePath(const char* filepath);
		/**
		*	�ļ�·��
		*/
		const char* getFilePath();
		/**
		*	���ڽ����С
		*/
		const sys::Size& getViewSize();
		/**
		*	��ȡ���ַ���
		*/
		LayoutDirection getLayoutDirection();
		/**
		*	��ȡ����
		*/
		Layout* getLayout();
	protected:
		/**
		*	�����ڴ�С�����ı�ʱ
		*/
		void onViewSizeChanged(const sys::Size& inputSize);
		/**
		*	���ؽ����ļ�
		*/
		bool loadFile();
		/**
		*	��ʼ��
		*/
		void initUI();
		/**
		*	�¼���
		*/
		virtual void initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual void initText();
		/**
		*	��С�Զ�����
		*/
		void autoResize();
	protected:
		// �ļ�·��
		std::string m_strFilePath;
		// ui���ڵ�
		Widget* m_pRoot;
		// ����
		Layout* m_pLayout;
		// ���ַ���
		LayoutDirection m_eLayoutDirection;
		// ���ڽ����С
		sys::Size m_sViewSize;
	};
}