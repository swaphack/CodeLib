#pragma once

#include <string>

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
		bool loadFile(const std::string& filepath);
		// �����ļ�
		bool saveFile(const std::string& filepath);
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