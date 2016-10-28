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
		// 加载脚本文件
		virtual bool load(const char* filepath);
		// 加载脚本
		virtual bool loadString(const char* text);
	protected:
		// 执行脚本
		virtual void run();
	private:
		static Script* s_script;
		// 脚本文档
		Document* _document;
	};
}