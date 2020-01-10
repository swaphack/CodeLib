#pragma once

#include "Base/Types.h"

namespace sys
{
	class Directory
	{
	public:
		static void getDirectory(const char* fullpath, std::string& dir);

		// �����ļ�
		static int32_t createFile(const char* filename);
		// ɾ���ļ�
		static int32_t deleteFile(const char* filename);
		// �������ļ�
		static int32_t renameFile(const char* oldFilename, const char* newFilename);

		// �����ļ���
		static int32_t createDirectory(const char* dirname);
		// ɾ���ļ���
		static int32_t deleteDirectory(const char* dirname);
		// �������ļ���
		static int32_t renameDirectory(const char* oldDirname, const char* newDirname);

		// ��ȡ��ǰĿ¼
		static void getCurrentDirectory(std::string& dir);
		// ���õ�ǰĿ¼
		static int32_t setCurrentDirectory(const char* name);
	protected:
	private:
	};
}