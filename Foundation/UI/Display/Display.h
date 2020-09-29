#pragma once

#include "system.h"
#include "render.h"
#include "Layout/ui_common.h"

namespace ui
{
	class Layout;
	/**
	*	������ʾ
	*/
	class Display : public render::Node, public render::WindowProtocol
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
		*	���¼���
		*/
		void reload();
	public:
		/**
		*	�����ļ�·��
		*/
		void load(const std::string& filepath);
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
		virtual void onWindowSizeChange(const math::Size& inputSize);
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
		// ����
		Layout* m_pLayout = nullptr;
		// ���ַ���
		LayoutDirection m_eLayoutDirection = LayoutDirection::NONE;
		// ���ڽ����С
		math::Size m_sViewSize;
	};
}