#pragma once

#include "system.h"
#include "ui.h"

namespace ue
{
	// ѡ�񲼾��ļ�
#define PANEL_SELECT_DESIGN_FILE "PANEL_SELECT_DESIGN_FILE"
	// ѡ�в�����
#define PANEL_SELECT_WIDGET "PANEL_SELECT_WIDGET"
	// �����ļ�
#define PANEL_SAVE_FILE "PANEL_SAVE_FILE"

	/**
	*	�¼�����
	*/
	class PanelEvent : public sys::EventCenter
	{
	public:
		PanelEvent();
		virtual ~PanelEvent();
	public:
		/**
		*	�ɷ��¼�
		*/
		void dispatchEvent(const std::string& name, void* userData);
	public:// �¼��ɷ�
		/**
		*	�ɷ��漰�ļ�
		*/
		void setDesignFile(const std::string& filepath);
		/**
		*	�ɷ��漰�ļ�
		*/
		void setSelectNode(ui::CtrlWidget* node);
		/**
		*	�����ļ�
		*/
		void saveFile();
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
