#pragma once

namespace script
{
	class Block;
	class Scanner;
	// �ű��ĵ�����
	class Document
	{
	public:
		Document();
		virtual ~Document();
	public:
		// �����ļ�
		bool loadFile(const char* filepath);
		// ����
		bool parse(const char* text, int size);
	private:
		// �����
		Block* m_pBlock;
		// ɨ����
		Scanner* m_pScanner;
	};
}