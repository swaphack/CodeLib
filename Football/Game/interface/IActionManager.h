#pragma once

namespace game
{
	class IAction;
	class IPlayer;
	/**
	*	��������
	*/
	class IActionManager
	{
	public:
		virtual ~IActionManager() {}
	public:
		/**
		*	��Ӷ���
		*/
		virtual void addAction(IAction* action) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeAction(IAction* action) = 0;
		/**
		*	�Ƴ����ж���
		*/
		virtual void removeAllActions() = 0;
	};
}