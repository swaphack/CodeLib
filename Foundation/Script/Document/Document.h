#pragma once

namespace script
{
	// 脚本文档解析
	class Document
	{
	public:
		Document();
		virtual ~Document();
	public:
		// 加载文件
		bool loadFile(const char* filepath);
		// 解析
		virtual bool parse();
	public:
		// 文本指针
		char* getPtr();
		// 文本大小
		int getSize();
	private:
		// 文本指针
		char* _buffer;
		// 文本大小
		int _size;
	};
}