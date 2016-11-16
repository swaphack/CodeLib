#pragma once

namespace script
{
	class Scanner;
	class Parser;

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
		// ɨ����
		Scanner* m_pScanner;
		// �﷨����
		Parser* m_pParser;
	};
}