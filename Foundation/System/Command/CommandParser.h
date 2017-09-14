#pragma once

#include <string>
#include <map>
#include <vector>
#include <functional>

namespace sys
{
	typedef std::function<bool(const std::vector<std::string>& params)> ParseCommand;
	// �������
	class CommandParser
	{
	public:
		CommandParser();
		~CommandParser();
	public:
		// ��ӽ�����
		void addParser(const std::string& key, ParseCommand parser);
		// �Ƴ�������
		void removeParser(const std::string& key);
		// �Ƴ����н�����
		void removeAllParsers();

		void parse(const std::string& line);
	private:
		// ������ʽ
		std::map<std::string, ParseCommand> _commandParsers;
	};
}