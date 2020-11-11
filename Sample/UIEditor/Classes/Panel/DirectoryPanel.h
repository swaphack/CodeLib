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
		// ����Ŀ¼��
		void updateDirectoryPanel();
	private:
		// ��Ŀ¼
		std::string _root;
		// Ŀ¼��Ϣ
		DirDetail _dirDetail;
	};
}
