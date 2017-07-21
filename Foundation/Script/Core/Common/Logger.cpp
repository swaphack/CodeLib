#include "Logger.h"
#include "Console.h"

using namespace script;


void Logger::write(const T_Message& msg)
{
	m_vecMessages.push_back(msg);
}

void Logger::write(Level level, const std::string& body)
{
	write({ level, body });
}

void Logger::normal(const std::string& body)
{
	write(eML_NORMAL, body);
}

void Logger::debug(const std::string& body)
{
	write(eML_DEBUG, body);
}

void Logger::info(const std::string& body)
{
	write(eML_INFORMATION, body);
}

void Logger::warn(const std::string& body)
{
	write(eML_WARNING, body);
}

void Logger::error(const std::string& body)
{
	write(eML_ERROR, body);
}

void Logger::flush()
{
	if (m_vecMessages.empty())
	{
		return;
	}

	for (int i = 0; i < m_vecMessages.size(); i++)
	{
		Level level = m_vecMessages[i].level;
		switch (level)
		{
		case Logger::eML_NORMAL:
			Console::getInstance()->show(m_vecMessages[i].body.c_str());
			break;
		case Logger::eML_DEBUG:
			Console::getInstance()->debug(m_vecMessages[i].body.c_str());
			break;
		case Logger::eML_INFORMATION:
			Console::getInstance()->info(m_vecMessages[i].body.c_str());
			break;
		case Logger::eML_WARNING:
			Console::getInstance()->warn(m_vecMessages[i].body.c_str());
			break;
		case Logger::eML_ERROR:
			Console::getInstance()->error(m_vecMessages[i].body.c_str());
			break;
		default:
			break;
		}
	}

	m_vecMessages.clear();
}
