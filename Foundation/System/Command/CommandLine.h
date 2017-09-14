#pragma once

#include <string>
#include <queue>
#include <functional>

namespace sys
{
	// 命令行
	class CommandLine
	{
	public:
		CommandLine();
		~CommandLine();
	public:
		// 添加命令
		void pushCommand(const std::string& line);
		// 去除命令
		std::string popCommand();
		// 是否为空
		bool empty();
		// 清空
		void clear();
	private:
		std::queue<std::string> _commandLines;
	};
}