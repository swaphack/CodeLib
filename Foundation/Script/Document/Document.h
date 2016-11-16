#pragma once

namespace script
{
	class Scanner;
	class Parser;

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
		bool parse(const char* text, int size);
	private:
		// 扫描器
		Scanner* m_pScanner;
		// 语法分析
		Parser* m_pParser;
	};
}