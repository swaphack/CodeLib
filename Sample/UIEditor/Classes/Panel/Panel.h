#pragma once

#include "ui.h"

namespace ue
{
	typedef std::function<void(ui::CtrlWidget* frontWidget)> FrontWidgetFunc;

	// 面板
	class Panel : public ui::CtrlFile
	{
	public:
		Panel();
		virtual ~Panel();
	public:
		virtual bool init();
	protected:
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	protected:
		/**
		*	点击最前面的组件
		*/
		bool touchFrontWidget(ui::CtrlWidget* widget, const math::Vector2& touchPoint, const FrontWidgetFunc& func);
	public:
		/**
		*	创建控件
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<ui::CtrlWidget, T>::value, T>::type>
		static T* createWidget()
		{
			auto pNode = CREATE_NODE(T);
			ui::UIShaderHelper::loadShader(pNode);
			return pNode;
		}
		/**
		*	创建文件
		*/
		ui::CtrlWidget* createUIFile(const std::string& filepath);
		/**
		*	创建文件面板
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
		*	创建面板
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
		*	创建面板
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
