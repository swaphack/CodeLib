#pragma once

#include "Base/Types.h"

namespace sys
{
	class Directory
	{
	public:
		static void getDirectory(const char* fullpath, std::string& dir);

		// 创建文件
		static int32 createFile(const char* filename);
		// 删除文件
		static int32 deleteFile(const char* filename);
		// 重命名文件
		static int32 renameFile(const char* oldFilename, const char* newFilename);

		// 创建文件夹
		static int32 createDirectory(const char* dirname);
		// 删除文件夹
		static int32 deleteDirectory(const char* dirname);
		// 重命名文件夹
		static int32 renameDirectory(const char* oldDirname, const char* newDirname);

		// 获取当前目录
		static void getCurrentDirectory(std::string& dir);
		// 设置当前目录
		static int32 setCurrentDirectory(const char* name);
	protected:
	private:
	};
}