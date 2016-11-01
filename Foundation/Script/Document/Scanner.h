#pragma once

namespace script
{
	class Block;
	class Expression;

	// 文档扫描器
	class Scanner
	{
	public:
		Scanner();
	public:
		// 设置代码块
		void setBlock(Block* block);
		// 浏览文本
		bool read(const char* ptr, int size);
	protected:
		// 解析
		bool parse();
		// 读取代码块
		Block* readBlock();
		// 读取表达式
		Expression* readExpression();
	private:
		// 文本内容指针
		char* m_pContent;
		// 偏移位置
		int m_nOffset;
		// 文本大小
		int m_nSize;
		// 代码块
		Block* m_pBlock;
	};
}