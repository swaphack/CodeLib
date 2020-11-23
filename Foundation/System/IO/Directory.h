#pragma once

#include <string>
#include <cstdint>
#include <vector>

namespace sys
{
	// Ŀ¼
	class Directory
	{
	public:
		// ��ȡĿ¼
		static void getDirectory(const std::string& fullpath, std::string& dir);
		// ��ȡ�����ļ�
		static void getAllFiles(const std::string& dir, std::vector<std::string>& files);
		// �����ļ�
		static int32_t createFile(const std::string& filename);
		// ɾ���ļ�
		static int32_t deleteFile(const std::string& filename);
		// �������ļ�
		static int32_t renameFile(const std::string& oldFilename, const std::string& newFilename);

		// �����ļ���
		static int32_t createDirectory(const std::string& dirname);
		// ɾ���ļ���
		static int32_t deleteDirectory(const std::string& dirname);
		// �������ļ���
		static int32_t renameDirectory(const std::string& oldDirname, const std::string& newDirname);

		// ��ȡ��ǰĿ¼
		static void getCurrentDirectory(std::string& dir);
		// ���õ�ǰĿ¼
		static int32_t setCurrentDirectory(const std::string& name);
		// ��ȡĿ¼����
		static std::string getDirName(const std::string& fullpath, bool containsFormat = true);
	public:
		Directory();
		virtual ~Directory();
	public:
		/**
		*	����Ŀ¼·��
		*/
		void setRoot(const std::string root);
		/**
		*	��ȡĿ¼·��
		*/
		const std::string& getRoot() const;
	public:
		/**
		*	��ȡĿ¼���ļ�
		*/
		const std::vector<std::string>& getFiles() const;
		/**
		*	��ȡĿ¼��Ŀ¼
		*/
		const std::vector<std::string>& getSubDirs() const;
		/**
		*	������Ϣ
		*/
		void load();
	private:
		// ��·��
		std::string _root;
		// �ļ�
		std::vector<std::string> _files;
		// ��Ŀ¼
		std::vector<std::string> _sudDirs;
	};
}
