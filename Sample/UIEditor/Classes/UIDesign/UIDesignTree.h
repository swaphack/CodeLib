#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// �ڵ���
	class UIDesignTree : public Panel
	{
	public:
		UIDesignTree();
		virtual ~UIDesignTree();
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
		void setNode(const Node* pNode);
	protected:
		/**
		*	����Ŀ¼��
		*/
		void updateRootPanel();
		/**
		*	����Ŀ¼��
		*/
		void updateRootList(ui::CtrlListView* layout, const Node* pNode, int layer = 0);
	private:
		/**
		*	�ı������Ϣ
		*/
		void onChangeFoldState(const std::string& name);
		/**
		*	Ŀ¼�Ƿ����
		*/
		bool isDirFolded(const std::string& name);
	private:
		/**
		*	����Ŀ¼����
		*/
		ui::CtrlButton* createHasChildrenNode(int height, const std::string& name, const std::string& fullpath);
		/**
		*	�����ļ�����
		*/
		ui::CtrlButton* createNoChildrenNode(int height, const std::string& name, const std::string& fullpath);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 35;
		// ��Ŀ¼
		std::string _root;
		// ������Ϣ
		std::map<std::string, bool> _dirFoldInfo;

		ui::CtrlListView* _listview = nullptr;
	};
}
