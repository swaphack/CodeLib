#pragma once

#include <string>
#include <map>
#include <vector>
#include <functional>

namespace sys
{
	typedef std::function<bool(const std::vector<std::string>& params)> ParseCommand;

	// �ؼ�ֵ
	class CommandParams
	{
	public:
		CommandParams();
		~CommandParams();
	public:
		void setKey(const std::string& key);
		const std::string& getKey();

		void addParam(const std::string& param);
		void removeParam(const std::string& param);
		void removeAllParams();

		int getParamsCount();
		std::string item(int index);
	private:
		// �ؼ���
		std::string _key;
		// ����
		std::vector<std::string> _params;
	};

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
		/*
		��ʽ sudo -rm -rf rn a b
		*/
		void parseLine(const std::string& line);
		/*
		��ʽ sudo -rm -rf
		*/
		void parseCommand(const std::string& commamd);
	protected:
		void dispatch(const std::string& key, const std::vector<std::string>& params);
	private:
		// ������ʽ
		std::map<std::string, ParseCommand> _commandParsers;
	};
}