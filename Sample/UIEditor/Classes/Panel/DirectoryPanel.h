#pragma once

#include "Panel.h"

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
	class DirectoryPanel : public Panel
	{
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
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
		void updateRootPanel();
		/**
		*	����Ŀ¼��
		*/
		void updateRootList(ui::Layout* layout, const DirDetail& detail);
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
		ui::LayoutItem* createDirItem(int top, int height, const std::string& name, const std::string& fullpath);
		/**
		*	�����ļ�����
		*/
		ui::LayoutItem* createFileItem(int top, int height, const std::string& name);
		/**
		*	������
		*/
		ui::LayoutItem* createRootItem(int top, int height, bool isDir, const std::string& name, const std::string& fullpath);
	private:
		const float CONST_OFFSET_Y = 5;
		const float CONST_ITEM_HEIGHT = 30;
		// ��Ŀ¼
		std::string _root;
		// Ŀ¼��Ϣ
		DirDetail _dirDetail;
		// ���붥��λ��
		float _top = 0;
		// ������Ϣ
		std::map<std::string, bool> _dirFoldInfo;

		std::map<std::string, ui::LayoutItem*> _dirItems;
	};
}
