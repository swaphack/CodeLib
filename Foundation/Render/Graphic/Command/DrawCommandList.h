#pragma once

#include "DrawCommand.h"

namespace render
{
	/**
	*	ªÊ÷∆√¸¡Ó¡–±Ì
	*/
	class DrawCommandList : public DrawCommand
	{
	public:
		DrawCommandList();
		virtual ~DrawCommandList();
	public:
		void appendCommand(DrawCommand* pCommand);

		virtual void draw();
	private:
		std::vector<DrawCommand*> _commandList;
	};
}