#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	// Ŀ¼
	class Directory
	{
	public:
		static void getDirectory(const std::string& fullpath, std::string& dir);

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
	protected:
	private:
	};
}