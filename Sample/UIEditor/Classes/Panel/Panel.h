#pragma once

#include "ui.h"

namespace ue
{

#define PANEL_SELECT_TARGET "PANEL_SELECT_TARGET"
#define PANEL_SELECT_DESIGN_FILE "PANEL_SELECT_DESIGN_FILE"
#define PANEL_SELECT_XML "PANEL_SELECT_XML"
#define PANEL_SELECT_LAYOUT "PANEL_SELECT_LAYOUT"

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
	protected: // 点击
		/**
		*	点击屏幕
		*/ 
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	在屏幕上滑动
		*/  
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	离开屏幕
		*/   
		virtual bool onTouchEnded(float x, float y, bool include);
	protected: // 事件派发
		/**
		*	派发布局项
		*/
		void dispatchItem(ui::LayoutItem* item);
		/**
		*	派发布局项
		*/
		void dispatchLayoutFile(ui::CtrlFile* layout);
		/**
		*	派发配置文件
		*/
		void dispatchXml(tinyxml2::XMLElement* doc);
		/**
		*	派发涉及项
		*/
		void dispatchDesignFile(const std::string& filepath);
	protected:
		/**
		*	创建控件
		*/
		static ui::LayoutItem* createIteam();
		/**
		*	创建控件
		*/
		template<typename T, typename = std::enable_if<std::is_base_of<render::CtrlWidget, T>::value, T>::type>
		static ui::LayoutItem* createIteam()
		{
			auto pItem = createIteam();
			if (pItem == nullptr)
			{
				return nullptr;
			}

			auto pNode = CREATE_NODE(T);
			if (pNode != nullptr)
			{
				pItem->setWidget(pNode);
			}

			return pItem;
		}
		/**
		*	创建文件
		*/
		static ui::LayoutItem* createUIFile(const std::string& filepath);
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
		static T* showWithTarget(const ui::LayoutItem* item, sys::CSSDirection eDir)
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
