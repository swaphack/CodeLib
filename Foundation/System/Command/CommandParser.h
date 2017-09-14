#pragma once

#include <string>
#include <map>
#include <vector>
#include <functional>

namespace sys
{
	typedef std::function<bool(const std::vector<std::string>& params)> ParseCommand;
	// 命令解析
	class CommandParser
	{
	public:
		CommandParser();
		~CommandParser();
	public:
		// 添加解析器
		void addParser(const std::string& key, ParseCommand parser);
		// 移除解析器
		void removeParser(const std::string& key);
		// 移除所有解析器
		void removeAllParsers();

		void parse(const std::string& line);
	private:
		// 解析方式
		std::map<std::string, ParseCommand> _commandParsers;
	};
}