#pragma once

#include <string>
#include <vector>

namespace script
{
	// 信息
	class Logger
	{
	public:
		// 信息级别
		enum Level
		{
			// 正常
			eML_NORMAL,
			// 调试
			eML_DEBUG,
			// 信息
			eML_INFORMATION,
			// 警告
			eML_WARNING,
			// 错误
			eML_ERROR,
		};

		struct T_Message
		{
			// 级别
			Level level;
			// 文本
			std::string body;
		};
	public:
		static Logger* getInstance();
	public:
		void write(const T_Message& msg);
		void write(Level level, const std::string& body);
		void normal(const std::string& body);
		void debug(const std::string& body);
		void info(const std::string& body);
		void warn(const std::string& body);
		void error(const std::string& body);
		void flush();
	private:
		std::vector<T_Message> m_vecMessages;
	};
}