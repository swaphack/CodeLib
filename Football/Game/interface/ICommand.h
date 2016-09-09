#pragma once

namespace game
{
	class IAction;

	/**
	*	命令
	*/
	class ICommand
	{
	public:
		virtual ~ICommand() {}
	public:
		/**
		*	生成最佳动作
		*/
		virtual IAction* makeAction() = 0;
	};
}