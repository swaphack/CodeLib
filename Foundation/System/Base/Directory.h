#pragma once

#include "Base/Types.h"

namespace sys
{
	class Directory
	{
	public:
		static void getDirectory(const char* fullpath, std::string& dir);

		// �����ļ�
		static int32 createFile(const char* filename);
		// ɾ���ļ�
		static int32 deleteFile(const char* filename);
		// �������ļ�
		static int32 renameFile(const char* oldFilename, const char* newFilename);

		// �����ļ���
		static int32 createDirectory(const char* dirname);
		// ɾ���ļ���
		static int32 deleteDirectory(const char* dirname);
		// �������ļ���
		static int32 renameDirectory(const char* oldDirname, const char* newDirname);

		// ��ȡ��ǰĿ¼
		static void getCurrentDirectory(std::string& dir);
		// ���õ�ǰĿ¼
		static int32 setCurrentDirectory(const char* name);
	protected:
	private:
	};
}