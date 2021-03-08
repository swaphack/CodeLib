#pragma once

#include "system.h"
#include "ui.h"

namespace ue
{
	// ѡ���ļ�
#define PANEL_SELECT_FILE "PANEL_SELECT_FILE"
	// ѡ�и��ڵ�
#define PANEL_SELECT_ROOT "PANEL_SELECT_ROOT"
	// ѡ����ͼ�ؼ���
#define PANEL_SELECT_VIEW_WIDGET "PANEL_SELECT_VIEW_WIDGET"
	// ѡ�����ڵ�
#define PANEL_SELECT_NODE_TREE "PANEL_SELECT_NODE_TREE"
	// �����ļ�
#define PANEL_SAVE_FILE "PANEL_SAVE_FILE"
	// ѡ�пؼ���
#define PANEL_SELECT_CONTROL_WIDGET "PANEL_SELECT_CONTROL_WIDGET"

	class UIDesignView;
	class UIDesignNodeTree;

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
		*	�ɷ�ѡ���ļ�
		*/
		void setSelectFile(const std::string& filepath);
		/**
		*	�ɷ�ѡ�нڵ�
		*/
		void setSelectNode(render::Node* node);
		/**
		*	�ɷ�ѡ�нڵ����ڵ�
		*/
		void setSelectTreeNode(const std::vector<int>& vecIndex);
		/**
		*	�ɷ����ڵ�
		*/
		void setRoot(render::Node* node);
		/**
		*	�ɷ�ѡ�пؼ���
		*/
		void setSelectControlWidget(render::Node* node);
		/**
		*	�����ļ�
		*/
		void saveFile();
	public:
		/**
		*	�ļ�������ͼ
		*/
		void setViewPanel(UIDesignView* panel);
		/**
		*	�ļ�������ͼ
		*/
		UIDesignView* getViewPanel() const;
		/**
		*	�ڵ���
		*/
		void setNodeTreePanel(UIDesignNodeTree* panel);
		/**
		*	�ڵ���
		*/
		UIDesignNodeTree* getNodeTreePanel() const;
	private:
		/**
		*	�ļ�������ͼ
		*/
		UIDesignView* m_pDesignView = nullptr;
		/**
		*	�ڵ���
		*/
		UIDesignNodeTree* m_pDesignNodeTree = nullptr;
	};

#define G_PANELEVT sys::Instance<PanelEvent>::getInstance()
}
