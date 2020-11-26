#pragma once

#include "ui.h"

namespace ue
{

#define PANEL_SELECT_TARGET "PANEL_SELECT_TARGET"
#define PANEL_SELECT_DESIGN_FILE "PANEL_SELECT_DESIGN_FILE"
#define PANEL_SELECT_XML "PANEL_SELECT_XML"
#define PANEL_SELECT_LAYOUT "PANEL_SELECT_LAYOUT"

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
	protected: // ���
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
	protected: // �¼��ɷ�
		/**
		*	�ɷ�������
		*/
		void dispatchItem(ui::LayoutItem* item);
		/**
		*	�ɷ�������
		*/
		void dispatchLayoutFile(ui::CtrlFile* layout);
		/**
		*	�ɷ������ļ�
		*/
		void dispatchXml(tinyxml2::XMLElement* doc);
		/**
		*	�ɷ��漰��
		*/
		void dispatchDesignFile(const std::string& filepath);
	protected:
		/**
		*	�����ؼ�
		*/
		static ui::LayoutItem* createIteam();
		/**
		*	�����ؼ�
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
		*	�����ļ�
		*/
		static ui::LayoutItem* createUIFile(const std::string& filepath);
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
