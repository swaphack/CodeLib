#pragma once

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
		virtual bool load(const char* filepath);
		// ���ؽű�
		virtual bool loadString(const char* text);
	protected:
		// ִ�нű�
		virtual void run();
	private:
		static Script* s_script;
		// �ű��ĵ�
		Document* _document;
	};
}