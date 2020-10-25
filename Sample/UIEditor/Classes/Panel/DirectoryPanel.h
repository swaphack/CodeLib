#pragma once

#include "Panel.h"

namespace ue
{
	// Ŀ¼��
	class DirectoryPanel : public Panel
	{
	private:
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
	public:
		DirectoryPanel();
		virtual ~DirectoryPanel();
	public:
		virtual bool init();
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
