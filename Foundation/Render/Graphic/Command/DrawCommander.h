#pragma once

#include <vector>

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
		virtual ~DrawCommander();
	public:
		// ��������
		virtual void addCommand(DrawCommand* pCommand);
		// ִ����������
		virtual void flushAllCommands();
	private:
		std::vector<DrawCommand*> _commands;
	};
}