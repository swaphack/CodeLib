#pragma once

#include <functional>
#include <map>
#include <string>
#include <cstdint>
#include <vector>

namespace sys
{
	typedef std::function<bool(const std::vector<std::string>& params)> ParseCommand;

	// 关键值
	class CommandParams
	{
	public:
		CommandParams();
		~CommandParams();
	public:
		void setKey(const std::string& key);
		const std::string& getKey() const;

		void addParam(const std::string& param);
		void removeParam(const std::string& param);
		void removeAllParams();

		int32_t getParamsCount() const;
		std::string item(int32_t index);
	private:
		// 关键字
		std::string _key;
		// 参数
		std::vector<std::string> _params;
	};

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
		/*
		格式 sudo -rm -rf rn a b
		*/
		void parseLine(const std::string& line);
		/*
		格式 sudo -rm -rf
		*/
		void parseCommand(const std::string& commamd);
	protected:
		void dispatch(const std::string& key, const std::vector<std::string>& params);
	private:
		// 解析方式
		std::map<std::string, ParseCommand> _commandParsers;
	};
}