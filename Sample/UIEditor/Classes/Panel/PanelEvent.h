#pragma once

#include "system.h"
#include "ui.h"

namespace ue
{
	// ѡ�񲼾��ļ�
#define PANEL_SELECT_DESIGN_FILE "PANEL_SELECT_DESIGN_FILE"
	// ѡ�и��ڵ�
#define PANEL_SELECT_ROOT "PANEL_SELECT_ROOT"
	// ѡ�в�����
#define PANEL_SELECT_WIDGET "PANEL_SELECT_WIDGET"
	// ѡ�����ڵ�
#define PANEL_SELECT_NODE_TREE "PANEL_SELECT_NODE_TREE"
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
		*	�ɷ�����ļ�
		*/
		void setDesignFile(const std::string& filepath);
		/**
		*	�ɷ�ѡ�нڵ�
		*/
		void setSelectNode(render::Node* node);
		/**
		*	�ɷ�ѡ�нڵ���
		*/
		void setSelectNodeTree(const std::vector<int>& vecIndex);
		/**
		*	�ɷ����ڵ�
		*/
		void setRoot(render::Node* node);
		/**
		*	�����ļ�
		*/
		void saveFile();
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
