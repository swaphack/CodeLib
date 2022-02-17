#pragma once

#include "Panel/Panel.h"
#include "common.h"

namespace ue
{
	// Ŀ¼��
	class UIDesignDir : public Panel, public ui::TableDataProtocol
	{
	public:
		UIDesignDir();
		virtual ~UIDesignDir();
	public:
		virtual bool init();
	public:
		/**
		*	������
		*/
		virtual int getDataCount();
		/**
		*  ��С
		*/
		virtual math::Size getDataSize(int index, int& tag);
		/**
		*  �ؼ�
		*/
		virtual ui::CtrlWidget* getDataCell(int index, int tag);
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
		void setDirectory(const std::string& root);
	protected:
		/**
		*	����Ŀ¼��
		*/
		void updateRootPanel(bool cleanFold = false);
		/**
		*	����Ŀ¼��
		*/
		void updateRootList(ui::CtrlListView* layout, const DirDetail& detail, int layer = 0);
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
		ui::CtrlButton* createDirItem(int height, const std::string& name, const std::string& fullpath);
		/**
		*	�����ļ�����
		*/
		ui::CtrlButton* createFileItem(int height, const std::string& name, const std::string& fullpath);
		/**
		*	��ȡ�ܵ�Ŀ¼�������ļ�����
		*/
		int getTotalDirCount(const DirDetail& detail);
		/**
		*	��ȡĿ¼�������ļ�����Ϣ
		*/
		DirDetail getDirDetail(const DirDetail& detail, int index, int tempCount, bool& bFile);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 20;
		// ��Ŀ¼
		std::string _root;
		// ������Ϣ
		std::map<std::string, bool> _dirFoldInfo;
		// Ŀ¼��Ϣ
		std::vector<SimpleDirInfo> _simpleDirInfo;
		// ���
		ui::CtrlTableView* _tableView = nullptr;
	};
}
