#pragma once

#include <string>
#include <map>

namespace script
{
	class Document;
	class WordDocument;
	class WordFilter;
	class SymbolHandler;
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
		bool initWordSet(const std::string& filepath);
		// 初始化符号解析规则
		bool initSysmbolRule(const std::string& filepath);
		// 加载脚本文件
		bool load(const std::string& filepath);
		// 导入引用文本
		bool import(const std::string& filepath);
		// 执行脚本
		void run();
	protected:
		// 添加文档
		void addDocument(const std::string& name, Document* document);
		// 移除文档
		void removeDocument(const std::string& name);
		// 移除所有文档
		void removeAllDocuments();
	private:
		// 编译文件 判断是否属于标准文档
		Document* complieFile(const std::string& filepath);
	private:
		static Script* s_script;
		// 脚本文档
		std::map<std::string, Document*> _documents;
		// 单词过滤
		WordFilter* _worldFilter = nullptr;
		// 入口脚本文档
		Document* _mainDocument = nullptr;
		// 关键字配置文档
		WordDocument* _wordDocument = nullptr;
		// 符号处理
		SymbolHandler* _symbolHandler = nullptr;
	};
}