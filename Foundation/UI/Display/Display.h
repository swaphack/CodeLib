#pragma once

#include "macros.h"

namespace ui
{
	/**
	*	���ַ���
	*/
	enum LayoutDirection
	{
		// ��
		ELD_NONE,
		// ��ֱ����
		ELD_HORIZONTAL,
		// ˮƽ����
		ELD_VERTICAL,
	};

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
		*	���ô��ڽ����С
		*/
		void setViewSize(const sys::Size& inputSize);
		/**
		*	���ڽ����С
		*/
		const sys::Size& getViewSize();
		/**
		*	���ò��ַ���
		*/
		void setLayoutDirection(LayoutDirection eDirection);
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