#pragma once

namespace sys
{
	// 结构或类只能保存常量，包含指针的存储会有问题，因为存储的指向目标的指针地址
	class File
	{
	private:
		File() {}
		~File() {}
	public:
		// 将数据写到本地
		static bool write(const char* url, const char* data, long size);
		// 从本地读取数据
		static char* read(const char* url, long& size);
		// 追加数据到本地
		static bool append(const char* url, const char* data, long size);
		// 判断文件是否存在
		static bool isFileExists(const char* url);
	};
}