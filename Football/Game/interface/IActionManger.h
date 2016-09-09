#pragma once

namespace game
{
	class IAction;
	class IPlayer;
	/**
	*	��������
	*/
	class IActionManger
	{
	public:
		virtual ~IActionManger() {}
	public:
		/**
		*	��Ӷ���
		*/
		virtual void addAction(IAction* action) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeAction(IAction* action) = 0;
	};
}