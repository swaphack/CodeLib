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
		void setUIRoot(render::Node* root);
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
		void setFilePath(const std::string& filepath);
		/**
		*	�ļ�·��
		*/
		const std::string& getFilePath();
		/**
		*	���ڽ����С
		*/
		const math::Size& getViewSize();
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
		void onViewSizeChanged(const math::Size& inputSize);
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
		render::Node* m_pRoot;
		// ����
		Layout* m_pLayout;
		// ���ַ���
		LayoutDirection m_eLayoutDirection;
		// ���ڽ����С
		math::Size m_sViewSize;
	};
}