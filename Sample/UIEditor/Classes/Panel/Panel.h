#pragma once

#include "ui.h"

namespace ue
{

#define PANEL_SELECT_TARGET "selectTarget"
#define PANEL_SELECT_FILE "selectFile"
#define PANEL_SELECT_XML "selectXML"

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
		void dispatchFile(ui::CtrlFile* layout);
		/**
		*	�ɷ������ļ�
		*/
		void dispatchXml(tinyxml2::XMLElement* doc);
	protected:
		/**
		*	�����ļ�
		*/
		static ui::LayoutItem* createUIFile(const std::string& filepath);
		/**
		*	�����ļ�
		*/
		template<typename T>
		static T* createPanel(const std::string& filepath)
		{
			auto pFile = CREATE_NODE(T);
			pFile->setRootView(true);
			pFile->setFilePath(filepath);
			pFile->autoResize();

			return pFile;
		}
	};
}
