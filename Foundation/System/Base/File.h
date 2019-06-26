#pragma once

#include "Base/Types.h"

namespace sys
{
	enum FileModel
	{
		// 打开
		eFM_OPEN = 0,
		// 读取
		eFM_READ = 0x0001,
		// 写入
		eFM_WRITE = 0x0010,
		// 追加
		eFM_APPEND = 0x0100,
		// 二进制
		eFM_BINARY = 0x00010000,
	};
	// 结构或类只能保存常量，包含指针的存储会有问题，因为存储的指向目标的指针地址
	class File
	{
	public:
		File(const char* url);
		File(const char* url, int32 mode);
		~File();
	public:
		// 将数据写到本地
		static bool write(const char* url, const char* data, int64 size, int64& writtenSize);
		// 从本地读取数据
		static char* read(const char* url, int64& readSize);
		// 从本地读取数据
		static bool read(const char* url, std::string& data);
		// 追加数据到本地
		static bool append(const char* url, const char* data, int64 size, int64& appendSize);
		// 判断文件是否存在
		static bool exists(const char* url);
	public:
		bool open();
		// 将数据写到本地
		bool write(const char* data, int64 size, int64& writtenSize);
		// 从本地读取数据
		char* read(int64& size);
		// 从本地读取数据
		bool read(std::string& data);
		// 追加数据到本地
		bool append(const char* data, int64 size);
		// 判断文件是否存在
		bool exists();
		// 关闭
		bool close();
	private:
		// 文件目录
		std::string m_strUrl;
		// 句柄id
		FILE* m_pFile;
		// 模式
		int32 m_nModel;
	};
}