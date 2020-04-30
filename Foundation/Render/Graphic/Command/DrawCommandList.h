#pragma once

#include "DrawCommand.h"

namespace render
{
	/**
	*	���������б�
	*/
	class DrawCommandList : public DrawCommand
	{
	public:
		DrawCommandList();
		virtual ~DrawCommandList();
	public:
		// ׷��һ������
		void appendCommand(DrawCommand* pCommand);
		// ����
		virtual void draw();

		void removeAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};
}