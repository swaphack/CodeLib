#pragma once

namespace script
{
	class Block;
	class Scanner;
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
		// 代码块
		Block* m_pBlock;
		// 扫描器
		Scanner* m_pScanner;
	};
}