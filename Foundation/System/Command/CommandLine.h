#pragma once

#include <string>
#include <queue>
#include <functional>

namespace sys
{
	// ������
	class CommandLine
	{
	public:
		CommandLine();
		~CommandLine();
	public:
		// �������
		void pushCommand(const std::string& line);
		// ȥ������
		std::string popCommand();
		// �Ƿ�Ϊ��
		bool empty();
		// ���
		void clear();
	private:
		std::queue<std::string> _commandLines;
	};
}