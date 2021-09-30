#pragma once

#include "ui.h"

namespace ue
{
	typedef std::function<void(ui::CtrlWidget* frontWidget)> FrontWidgetFunc;

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
		*	�����ǰ������
		*/
		bool touchFrontWidget(ui::CtrlWidget* widget, const math::Vector2& touchPoint, const FrontWidgetFunc& func);
	public:
		/**
		*	�����ؼ�
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<ui::CtrlWidget, T>::value, T>::type>
		static T* createWidget()
		{
			auto pNode = CREATE_NODE(T);
			ui::UIShaderHelper::loadShader(pNode);
			return pNode;
		}
		/**
		*	�����ļ�
		*/
		ui::CtrlWidget* createUIFile(const std::string& filepath);
		/**
		*	�����ļ����
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<Panel, T>::value, T>::type>
		static T* createPanel(const std::string& filepath)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(filepath);
			pFile->autoResize();

			return pFile;
		}


		/**
		*	�������
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<SinglePanel, T>::value, T>::type>
		static T* showWithTarget(const ui::CtrlWidget* item, sys::CSSDirection eDir)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(pFile->getPanelPath());
			pFile->autoResize();
			pFile->showWithTarget(item, eDir);

			return pFile;
		}
		/**
		*	�������
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<SinglePanel, T>::value, T>::type>
		static T* show()
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(pFile->getPanelPath());
			pFile->autoResize();
			pFile->show();

			return pFile;
		}
	};
}
