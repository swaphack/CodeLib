#pragma once

#include <string>
#include <vector>

namespace script
{
	// ��Ϣ
	class Logger
	{
	public:
		// ��Ϣ����
		enum Level
		{
			// ����
			eML_NORMAL,
			// ����
			eML_DEBUG,
			// ��Ϣ
			eML_INFORMATION,
			// ����
			eML_WARNING,
			// ����
			eML_ERROR,
		};

		struct T_Message
		{
			// ����
			Level level;
			// �ı�
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