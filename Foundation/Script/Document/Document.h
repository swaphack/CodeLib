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
		// 保存文件
		bool saveFile(const char* filepath);
		// 文本指针
		char* getPtr();
		// 文本大小
		int getSize();
	protected:
		// 转化成文档格式
		virtual bool convertToDocumentStruct() { return true; }
		// 转化成文本格式
		virtual bool convertToTextStruct() { return true; }
	private:
		// 文本指针
		char* _buffer;
		// 文本大小
		int _size;
	};
}