#pragma once

namespace script
{
	// 输出
	class Console
	{		
	private:
		Console();
		virtual ~Console();
	public:
		static Console* getInstance();
	public:
		// 调试
		void debug(bool condition, const char* text);
		// 信息
		void info(bool condition, const char* text);
		// 警告
		void warn(bool condition, const char* text);
		// 错误
		void error(bool condition, const char* text);		
		// 显示正常文本
		void show(const char* text);
		// 调试
		void debug(const char* text);
		// 信息
		void info(const char* text);
		// 警告
		void warn(const char* text);
		// 错误
		void error(const char* text);
		// 显示
		void open();
		// 关闭
		void close();
		// 暂停
		void pause();
	};
}