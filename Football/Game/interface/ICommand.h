#pragma once

namespace game
{
	class IAction;

	/**
	*	����
	*/
	class ICommand
	{
	public:
		virtual ~ICommand() {}
	public:
		/**
		*	������Ѷ���
		*/
		virtual IAction* makeAction() = 0;
	};
}