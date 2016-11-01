#pragma once

#include <string>
#include <map>

namespace script
{
	class Document;

	class Script
	{
	private:
		Script();
	public:
		virtual ~Script();
	public:
		static Script* getInstance();
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
		static Script* s_script;
		// �ű��ĵ�
		std::map<std::string, Document*> _documents;
		// ��ڽű��ĵ�
		Document* _mainDocument;
	};
}