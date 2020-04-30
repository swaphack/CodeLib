#pragma once

#include <vector>
#include <string>
#include <map>

namespace render
{
	class DrawCommand;
	/**
	*	指挥官
	*/
	class DrawCommander
	{
	public:
		DrawCommander();
		~DrawCommander();
	public:
		// 推送命令
		void addCommand(DrawCommand* pCommand);
		// 执行所有命令
		void flush();
		void removeAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};

	#define G_DRAWCOMMANDER sys::Instance<DrawCommander>::getInstance()
}