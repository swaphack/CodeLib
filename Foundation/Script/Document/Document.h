#pragma once

namespace script
{
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
		virtual bool parse();
	public:
		// �ı�ָ��
		char* getPtr();
		// �ı���С
		int getSize();
	private:
		// �ı�ָ��
		char* _buffer;
		// �ı���С
		int _size;
	};
}