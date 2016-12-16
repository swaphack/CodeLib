#pragma once

#include <string>
#include <map>

namespace script
{
	class Document;
	// �ű�����
	class Script
	{
	private:
		Script();
	public:
		virtual ~Script();
	public:
		static Script* getInstance();
		// ��ʼ�����ʿ�
		bool initWordSet(const char* filepath);
		// ��ʼ��������
		bool initWordFilter();
		// ���ؽű��ļ�
		bool load(const char* filepath);
		// ���������ı�
		bool import(const char* filepath);
		// ִ�нű�
		void run();
	protected:
		// ����ĵ�
		void addDocument(const char* name, Document* document);
		// �Ƴ��ĵ�
		void removeDocument(const char* name);
		// �Ƴ������ĵ�
		void removeAllDocuments();
	private:
		// �����ļ� �ж��Ƿ����ڱ�׼�ĵ�
		Document* complieFile(const char* filepath);
	private:
		static Script* s_script;
		// �ű��ĵ�
		std::map<std::string, Document*> _documents;
		// ��ڽű��ĵ�
		Document* _mainDocument;
	};
}