#pragma once

#include "macros.h"

namespace ui
{
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
		void dispose();
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
		*	�����ڴ�С�����ı�ʱ
		*/
		void onViewSizeChanged(const sys::Size& inputSize);
	protected:
		/**
		*	���ؽ����ļ�
		*/
		bool loadFile();
		/**
		*	��ʼ��
		*/
		bool initUI();
		/**
		*	�¼���
		*/
		virtual bool initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual bool initText();
		/**
		*	��ȡԪ�����ڵ�
		*/
		Widget* getWidget();
	protected:
		// �ļ�·��
		std::string m_strFilePath;
		// ����
		LayoutItem* m_pLayoutItem;
		// ���ڽ����С
		sys::Size m_sViewSize;
	};
}