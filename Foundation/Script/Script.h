#pragma once

#include <string>
#include <map>

namespace script
{
	class Document;
	// 脚本处理
	class Script
	{
	private:
		Script();
	public:
		virtual ~Script();
	public:
		static Script* getInstance();
		// 初始化单词库
		bool initWordSet(const char* filepath);
		// 初始化过滤器
		bool initWordFilter();
		// 加载脚本文件
		bool load(const char* filepath);
		// 导入引用文本
		bool import(const char* filepath);
		// 执行脚本
		void run();
	protected:
		// 添加文档
		void addDocument(const char* name, Document* document);
		// 移除文档
		void removeDocument(const char* name);
		// 移除所有文档
		void removeAllDocuments();
	private:
		// 编译文件 判断是否属于标准文档
		Document* complieFile(const char* filepath);
	private:
		static Script* s_script;
		// 脚本文档
		std::map<std::string, Document*> _documents;
		// 入口脚本文档
		Document* _mainDocument;
	};
}