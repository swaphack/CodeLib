#pragma once

namespace script
{
	class Compiler;
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
		Compiler* m_pCompiler;
		// �﷨����
		Parser* m_pParser;
	};
}