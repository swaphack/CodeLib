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
		// �����ļ�
		bool saveFile(const char* filepath);
		// �ı�ָ��
		char* getPtr();
		// �ı���С
		int getSize();
	protected:
		// ת�����ĵ���ʽ
		virtual bool convertToDocumentStruct() { return true; }
		// ת�����ı���ʽ
		virtual bool convertToTextStruct() { return true; }
	private:
		// �ı�ָ��
		char* _buffer;
		// �ı���С
		int _size;
	};
}