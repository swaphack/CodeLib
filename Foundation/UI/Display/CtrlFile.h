#pragma once

#include "system.h"
#include "render.h"
#include "Layout/macros.h"
#include "UI/CtrlWidget.h"

namespace ui
{
	class Layout;
	/**
	*	������ʾ
	*/
	class CtrlFile : 
		public CtrlWidget, 
		public render::WindowProtocol
	{
	public:
		CtrlFile();
		virtual ~CtrlFile();
	public:
		virtual bool init();
	public:
		/**
		*	��ʾ
		*/
		void show();
	public:
		/**
		*	�����ļ�·��
		*/
		void setFilePath(const std::string& filepath);
		/**
		*	�ļ�·��
		*/
		const std::string& getFilePath();
		/**
		*	���¼���
		*/
		void reload();
		/**
		*	����
		*/
		void save();
		/**
		*	����Ϊָ��Ŀ¼�ļ�
		*/
		void saveTo(const std::string& filepath);
	public:
		/**
		*	���ڽ����С
		*/
		const math::Size& getViewSize() const;
		/**
		*	��ȡ���ַ���
		*/
		LayoutDirection getLayoutDirection() const;
	public:
		/**
		*	�Ƿ��Ǹ���ͼ
		*/
		void setRootView(bool root);
		/**
		*	�Ƿ��Ǹ���ͼ
		*/
		bool isRootView() const;
		/**
		*	��С�Զ�����
		*/
		void autoResize();
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
		// �ļ�·��
		std::string m_strFilePath;
		// ���ַ���
		LayoutDirection m_eLayoutDirection = LayoutDirection::NONE;
		// ���ڽ����С
		math::Size m_sViewSize;
		// �Ƿ����ͼ
		bool m_bRootView = false;
		// ���ڵ�
		ui::CtrlWidget* m_pRootWidget = nullptr;
	};
}