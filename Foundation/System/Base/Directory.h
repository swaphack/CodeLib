#pragma once
#include <string>

namespace sys
{
	class Directory
	{
	public:
		static void getDirectory(const char* fullpath, std::string& dir);

		// �����ļ�
		static int createFile(const char* filename);
		// ɾ���ļ�
		static int deleteFile(const char* filename);
		// �������ļ�
		static int renameFile(const char* oldFilename, const char* newFilename);

		// �����ļ���
		static int createDirectory(const char* dirname);
		// ɾ���ļ���
		static int deleteDirectory(const char* dirname);
		// �������ļ���
		static int renameDirectory(const char* oldDirname, const char* newDirname);

		// ��ȡ��ǰĿ¼
		static void getCurrentDirectory(std::string& dir);
		// ���õ�ǰĿ¼
		static int setCurrentDirectory(const char* name);
	protected:
	private:
	};
}