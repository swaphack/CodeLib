#pragma once

#include <vector>
#include <string>
#include <map>

namespace render
{
	class DrawCommand;
	/**
	*	ָ�ӹ�
	*/
	class DrawCommander
	{
	public:
		DrawCommander();
		~DrawCommander();
	public:
		// ��������
		void addCommand(DrawCommand* pCommand);
		// ִ����������
		void flush();
		void removeAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};

	#define G_DRAWCOMMANDER sys::Instance<DrawCommander>::getInstance()
}