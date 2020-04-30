#pragma once

#include "DrawCommand.h"

namespace render
{
	/**
	*	绘制命令列表
	*/
	class DrawCommandList : public DrawCommand
	{
	public:
		DrawCommandList();
		virtual ~DrawCommandList();
	public:
		// 追加一条命令
		void appendCommand(DrawCommand* pCommand);
		// 绘制
		virtual void draw();

		void removeAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};
}