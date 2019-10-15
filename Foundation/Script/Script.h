#pragma once

#include <string>
#include <map>

namespace script
{
	class Document;
	class WordDocument;
	class WordFilter;
	class SymbolHandler;
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
		bool initWordSet(const std::string& filepath);
		// ��ʼ�����Ž�������
		bool initSysmbolRule(const std::string& filepath);
		// ���ؽű��ļ�
		bool load(const std::string& filepath);
		// ���������ı�
		bool import(const std::string& filepath);
		// ִ�нű�
		void run();
	protected:
		// ����ĵ�
		void addDocument(const std::string& name, Document* document);
		// �Ƴ��ĵ�
		void removeDocument(const std::string& name);
		// �Ƴ������ĵ�
		void removeAllDocuments();
	private:
		// �����ļ� �ж��Ƿ����ڱ�׼�ĵ�
		Document* complieFile(const std::string& filepath);
	private:
		static Script* s_script;
		// �ű��ĵ�
		std::map<std::string, Document*> _documents;
		// ���ʹ���
		WordFilter* _worldFilter = nullptr;
		// ��ڽű��ĵ�
		Document* _mainDocument = nullptr;
		// �ؼ��������ĵ�
		WordDocument* _wordDocument = nullptr;
		// ���Ŵ���
		SymbolHandler* _symbolHandler = nullptr;
	};
}