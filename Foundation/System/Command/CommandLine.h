#pragma once

#include <queue>
#include <string>

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
		bool empty() const;
		// ���
		void clear();
	private:
		std::queue<std::string> _commandLines;
	};
}