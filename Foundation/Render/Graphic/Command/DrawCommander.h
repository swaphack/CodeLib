#pragma once

#include <vector>

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
		virtual ~DrawCommander();
	public:
		// 推送命令
		virtual void addCommand(DrawCommand* pCommand);
		// 执行所有命令
		virtual void flushAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};
}