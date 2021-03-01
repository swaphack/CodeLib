#pragma once

#include "Panel/Panel.h"

namespace ue
{
	/**
	*	Ŀ¼��Ϣ
	*/
	struct DirDetail
	{
	public:
		// ����
		std::string name;
		// ·��
		std::string fullpath;
		// Ŀ¼
		std::vector<DirDetail> subDirs;
		// �ļ�
		std::vector<std::string> files;
	public:
		// ���ø�Ŀ¼
		void setRoot(const std::string& root);
		// ���
		void clear();
	};

	// Ŀ¼��
	class UIDesignDirectory : public Panel
	{
	public:
		UIDesignDirectory();
		virtual ~UIDesignDirectory();
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
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 35;
		// ��Ŀ¼
		std::string _root;
		// Ŀ¼��Ϣ
		DirDetail _dirDetail;
		// ������Ϣ
		std::map<std::string, bool> _dirFoldInfo;

		ui::CtrlListView* _listview = nullptr;
	};
}
