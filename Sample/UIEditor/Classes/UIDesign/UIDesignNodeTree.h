#pragma once
#pragma once

#include "Panel/Panel.h"

namespace ue
{

	// �ڵ���
	class UIDesignNodeTree : public Panel
	{
	public:
		UIDesignNodeTree();
		virtual ~UIDesignNodeTree();
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
	public:
		/**
		*	����Ŀ¼
		*/
		void setNode(Node* pNode);
	protected:
		/**
		*	����Ŀ¼��
		*/
		void updateRootPanel(bool cleanFold = false);
		/**
		*	����Ŀ¼��
		*/
		void updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer = 0);
	private:
		/**
		*	�ı������Ϣ
		*/
		void onChangeFoldState(const render::Node* node);
		/**
		*	Ŀ¼�Ƿ����
		*/
		bool isDirFolded(const render::Node* node);
	private:
		/**
		*	����Ŀ¼����
		*/
		ui::CtrlButton* createHasChildrenNode(int height, const std::string& name, const render::Node* node);
		/**
		*	�����ļ�����
		*/
		ui::CtrlButton* createNoChildrenNode(int height, const std::string& name, const render::Node* node);
		
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 20;

		// ������Ϣ
		std::map<render::Node*, bool> _dirFoldInfo;

		ui::CtrlListView* _listview = nullptr;

		render::Node* _rootNode = nullptr;
	};
}
